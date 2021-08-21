#pragma once

#include "RE/AITimeStamp.h"
#include "RE/ActiveEffect.h"
#include "RE/ActorState.h"
#include "RE/ActorValueOwner.h"
#include "RE/ActorValues.h"
#include "RE/BGSBipedObjectForm.h"
#include "RE/BGSEntryPointPerkEntry.h"
#include "RE/BSPointerHandle.h"
#include "RE/BSPointerHandleSmartPointer.h"
#include "RE/BSTArray.h"
#include "RE/BSTEvent.h"
#include "RE/BSTList.h"
#include "RE/BSTSmartPointer.h"
#include "RE/BSTTuple.h"
#include "RE/DetectionPriorities.h"
#include "RE/FormTypes.h"
#include "RE/IPostAnimationChannelUpdateFunctor.h"
#include "RE/MagicSystem.h"
#include "RE/MagicTarget.h"
#include "RE/NiSmartPointer.h"
#include "RE/TESNPC.h"
#include "RE/TESObjectREFR.h"


namespace RE
{
	class ActorMagicCaster;
	class ActorMover;
	class AIProcess;
	class bhkCharacterController;
	class bhkCharacterMoveFinishEvent;
	class BipedAnim;
	class BSTransformDeltaEvent;
	class CombatController;
	class CombatGroup;
	class ExtraDataList;
	class InventoryEntryData;
	class MovementControllerNPC;
	class MovementMessageActorCollision;
	class NiRefObject;
	class PackageLocation;
	class PerkEntryVisitor;
	struct ActorMotionFeedbackData;
	struct ActorMotionFeedbackOutput;


	enum class ACTOR_CRITICAL_STAGE : UInt32
	{
		kNone = 0,
		kGooStart = 1,
		kGooEnd = 2,
		kDisintegrateStart = 3,
		kDisintegrateEnd = 4,

		kTotal
	};


	struct Modifiers
	{
		// members
		float modifiers[ACTOR_VALUE_MODIFIERS::kTotal];	 // 0
	};
	STATIC_ASSERT(sizeof(Modifiers) == 0xC);


	struct ActorValueStorage
	{
		template <class T>
		struct LocalMap
		{
		public:
			T* operator[](ActorValue a_actorValue)
			{
				return GetAt(static_cast<char>(a_actorValue));
			}


			const T* operator[](ActorValue a_actorValue) const
			{
				return GetAt(static_cast<char>(a_actorValue));
			}


			// members
			BSFixedString actorValues;	// 00
			T*			  entries;		// 08

		private:
			T* GetAt(char a_actorValue) const
			{
				auto akVals = actorValues.data();
				if (akVals && entries) {
					UInt32 idx = 0;
					while (akVals[idx] != '\0') {
						if (akVals[idx] == a_actorValue) {
							break;
						}
						++idx;
					}

					if (akVals[idx] != '\0') {
						return std::addressof(entries[idx]);
					}
				}
				return 0;
			}
		};
		STATIC_ASSERT(sizeof(LocalMap<float>) == 0x10);


		// members
		LocalMap<float>		baseValues;	 // 00
		LocalMap<Modifiers> modifiers;	 // 10
	};
	STATIC_ASSERT(sizeof(ActorValueStorage) == 0x20);


	NiSmartPointer(Actor);


	class Actor :
		public TESObjectREFR,							   // 000
		public MagicTarget,								   // 098
		public ActorValueOwner,							   // 0B0
		public ActorState,								   // 0B8
		public BSTEventSink<BSTransformDeltaEvent>,		   // 0C8
		public BSTEventSink<bhkCharacterMoveFinishEvent>,  // 0D0
		public IPostAnimationChannelUpdateFunctor		   // 0D8
	{
	private:
		using EntryPoint = BGSEntryPointPerkEntry::EntryPoint;

	public:
		inline static constexpr auto RTTI = RTTI_Actor;
		inline static constexpr auto FORMTYPE = FormType::ActorCharacter;


		struct SlotTypes
		{
			enum
			{
				kLeftHand = 0,
				kRightHand,
				kUnknown,
				kPowerOrShout,

				kTotal
			};
		};


		enum class BOOL_BITS : UInt32
		{
			kNone = 0,
			kDelayUpdateScenegraph = 1 << 0,
			kProcessMe = 1 << 1,
			kMurderAlarm = 1 << 2,
			kHasSceneExtra = 1 << 3,
			kHeadingFixed = 1 << 4,
			kSpeakingDone = 1 << 5,
			kIgnoreChangeAnimationCall = 1 << 6,
			kSoundFileDone = 1 << 7,
			kVoiceFileDone = 1 << 8,
			kInTempChangeList = 1 << 9,
			kDoNotRunSayToCallback = 1 << 10,
			kDead = 1 << 11,
			kForceGreetingPlayer = 1 << 12,
			kForceUpdateQuestTarget = 1 << 13,
			kSearchingInCombat = 1 << 14,
			kAttackOnNextTheft = 1 << 15,
			kEvpBuffered = 1 << 16,
			kResetAI = 1 << 17,
			kInWater = 1 << 18,
			kSwimming = 1 << 19,
			kVoicePausedByScript = 1 << 20,
			kWasInFrustrum = 1 << 21,
			kShouldRotateToTrack = 1 << 22,
			kSetOnDeath = 1 << 23,
			kDoNotPadVoice = 1 << 24,
			kFootIKInRange = 1 << 25,
			kPlayerTeammate = 1 << 26,
			kGivePlayerXP = 1 << 27,
			kSoundCallbackSuccess = 1 << 28,
			kUseEmotion = 1 << 29,
			kGuard = 1 << 30,
			kParalyzed = (UInt32)1 << 31
		};


		enum class BOOL_FLAGS : UInt32
		{
			kNone = 0,
			kScenePackage = 1 << 0,
			kIsAMount = 1 << 1,
			kMountPointClear = 1 << 2,
			kGettingOnOffMount = 1 << 3,
			kInRandomScene = 1 << 4,
			kNoBleedoutRecovery = 1 << 5,
			kInBleedoutAnimation = 1 << 6,
			kCanDoFavor = 1 << 7,
			kShouldAnimGraphUpdate = 1 << 8,
			kCanSpeakToEssentialDown = 1 << 9,
			kBribedByPlayer = 1 << 10,
			kAngryWithPlayer = 1 << 11,
			kIsTrespassing = 1 << 12,
			kCanSpeak = 1 << 13,
			kIsInKillMove = 1 << 14,
			kAttackOnSight = 1 << 15,
			kIsCommandedActor = 1 << 16,
			kForceOneAnimgraphUpdate = 1 << 17,
			kEssential = 1 << 18,
			kProtected = 1 << 19,
			kAttackingDisabled = 1 << 20,
			kCastingDisabled = 1 << 21,
			kSceneHeadTrackRotation = 1 << 22,
			kForceIncMinBoneUpdate = 1 << 23,
			kCrimeSearch = 1 << 24,
			kMovingIntoLoadedArea = 1 << 25,
			kDoNotShowOnStealthMeter = 1 << 26,
			kMovementBlocked = 1 << 27,
			kAllowInstantFurniturePopInPlayerCell = 1 << 28,
			kForceAnimGraphUpdate = 1 << 29,
			kCheckAddEffectDualCast = 1 << 30,
			kUnderwater = (UInt32)1 << 31
		};


		struct ChangeFlags
		{
			enum ChangeFlag : UInt32
			{
				kLifeState = 1 << 10,
				kPackageExtraData = 1 << 11,
				kMerchantContainer = 1 << 12,
				kDismemberedLimbs = 1 << 17,
				kLeveledActor = 1 << 18,
				kDispModifiers = 1 << 19,
				kTempModifiers = 1 << 20,
				kDamageModifiers = 1 << 21,
				kOverrideModifiers = 1 << 22,
				kPermanentModifiers = 1 << 23,
			};
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kStartsDead = 1 << 9,
				kPersistent = 1 << 10,
				kInitiallyDisabled = 1 << 11,
				kIgnored = 1 << 12,
				kNoAIAcquire = 1 << 25,
				kDontHavokSettle = 1 << 29
			};
		};


		virtual ~Actor();  // 000

		// override (TESObjectREFR)
		virtual void					SaveGame(BGSSaveFormBuffer* a_buf) override;																																									// 00E
		virtual void					LoadGame(BGSLoadFormBuffer* a_buf) override;																																									// 00F
		virtual void					InitLoadGame(BGSLoadFormBuffer* a_buf) override;																																								// 010
		virtual void					FinishLoadGame(BGSLoadFormBuffer* a_buf) override;																																								// 011
		virtual void					Revert(BGSLoadFormBuffer* a_buf) override;																																										// 012
		virtual void					InitItemImpl() override;																																														// 013
		virtual void					SetDelete(bool a_set) override;																																													// 023
		virtual void					Predestroy() override;																																															// 03B
		virtual BGSLocation*			GetEditorLocation1() const override;																																											// 03C - { return editorLocation; }
		virtual bool					GetEditorLocation2(NiPoint3& a_outPos, NiPoint3& a_outRot, TESForm*& a_outWorldOrCell, TESObjectCELL* a_fallback) override;																						// 03D
		virtual void					ForceEditorLocation(BGSLocation* a_location) override;																																							// 03E - { editorLocation = a_location; }
		virtual void					Update3DPosition(bool a_warp) override;																																											// 03F
		virtual void					UpdateSoundCallBack(bool a_endSceneAction) override;																																							// 040
		virtual bool					SetDialogueWithPlayer(bool a_flag, bool a_forceGreet, TESTopicInfo* a_topic) override;																															// 041
		virtual BGSAnimationSequencer*	GetSequencer(void) const override;																																												// 045 - { return currentProcess->high->animSequencer; }
		virtual bool					HasKeywordHelper(const BGSKeyword* a_keyword) const override;																																					// 048
		virtual TESPackage*				CheckForCurrentAliasPackage() override;																																											// 049 - { return 0; }
		virtual BGSScene*				GetCurrentScene() const override;																																												// 04A
		virtual void					SetCurrentScene(BGSScene* a_scene) override;																																									// 04B
		virtual bool					UpdateInDialogue(DialogueResponse* a_response, bool a_unused) override;																																			// 04C
		virtual BGSDialogueBranch*		GetExclusiveBranch() const override;																																											// 04D - { return exclusiveBranch; }
		virtual void					SetExclusiveBranch(BGSDialogueBranch* a_branch) override;																																						// 04E - { exclusiveBranch = a_arg1; }
		virtual void					PauseCurrentDialogue(void) override;																																											// 04F
		virtual NiPoint3				GetStartingAngle() const override;																																												// 052
		virtual NiPoint3				GetStartingLocation() const override;																																											// 053
		virtual ObjectRefHandle			RemoveItem(TESBoundObject* a_item, SInt32 a_count, ITEM_REMOVE_REASON a_reason, ExtraDataList* a_extraList, TESObjectREFR* a_moveToRef, const NiPoint3* a_dropLoc = 0, const NiPoint3* a_rotate = 0) override;	// 056
		virtual bool					AddWornItem(TESBoundObject* a_item, SInt32 a_count, bool a_forceEquip, UInt32 a_arg4, UInt32 a_arg5) override;																									// 057
		virtual void					DoTrap1(TrapData& a_data) override;																																												// 058
		virtual void					DoTrap2(TrapEntry* a_trap, TargetEntry* a_target) override;																																						// 059
		virtual void					AddObjectToContainer(TESBoundObject* a_object, ExtraDataList* a_extraList, SInt32 a_count, TESObjectREFR* a_fromRefr) override;																					// 05A
		virtual NiPoint3				GetLookingAtLocation() const override;																																											// 05B
		virtual MagicCaster*			GetMagicCaster(MagicSystem::CastingSource a_source) override;																																					// 05C
		virtual MagicTarget*			GetMagicTarget() override;																																														// 05D - { return static_cast<MagicTarget*>(this); }
		virtual bool					IsChild() const override;																																														// 05E - { return false; }
		virtual BSFaceGenAnimationData* GetFaceGenAnimationData() override;																																												// 063
		virtual bool					DetachHavok(NiAVObject* a_obj3D) override;																																										// 065
		virtual void					InitHavok() override;																																															// 066
		virtual void					Unk_67(void) override;																																															// 067 - related to vampire lord cape
		virtual void					Unk_68(void) override;																																															// 068
		virtual void					Unk_69(void) override;																																															// 069
		virtual NiAVObject*				Load3D(bool a_arg1) override;																																													// 06A
		virtual void					Set3D(NiAVObject* a_object, bool a_queue3DTasks = true) override;																																				// 06C
		virtual bool					PopulateGraphProjectsToLoad(void) const override;																																								// 072
		virtual NiPoint3				GetBoundMin() const override;																																													// 073
		virtual NiPoint3				GetBoundMax() const override;																																													// 074
		virtual void					Unk_75(void) override;																																															// 075 - "ActorValue GetWeaponSkill()"? really weird call, only works for right hand, and defaults to 1
		virtual void					Unk_78(void) override;																																															// 078
		virtual void					ModifyAnimationUpdateData(BSAnimationUpdateData& a_data) override;																																				// 079
		virtual bool					ShouldSaveAnimationOnUnloading() const override;																																								// 07A - { return false; }
		virtual bool					ShouldSaveAnimationOnSaving() const override;																																									// 07B
		virtual bool					ShouldPerformRevert() const override;																																											// 07C
		virtual void					UpdateAnimation(float a_delta) override;																																										// 07D
		virtual void					Unk_82(void) override;																																															// 082
		virtual void					SetObjectReference(TESBoundObject* a_object) override;																																							// 085
		virtual void					MoveHavok(bool a_forceRec) override;																																											// 086
		virtual void					GetLinearVelocity(NiPoint3& a_velocity) const override;																																							// 087
		virtual void					SetActionComplete(bool a_set) override;																																											// 088
		virtual void					Disable() override;																																																// 08A
		virtual void					ResetInventory(bool a_leveledOnly) override;																																									// 08B
		virtual void					Unk_8C(void) override;																																															// 08C
		virtual void					Unk_8D(void) override;																																															// 08D
		virtual bool					OnAddCellPerformQueueReference(TESObjectCELL& a_cell) const override;																																			// 091
		virtual void					DoMoveToHigh() override;																																														// 092
		virtual void					TryMoveToMiddleLow() override;																																													// 093
		virtual bool					TryChangeSkyCellActorsProcessLevel() override;																																									// 094
		virtual void					Unk_96(void) override;																																															// 096
		virtual void					Unk_97(void) override;																																															// 097
		virtual void					SetParentCell(TESObjectCELL* a_cell) override;																																									// 099
		virtual bool					IsDead(bool a_notEssential) const override;																																										// 09A
		virtual void					Unk_9D(void) override;																																															// 09D
		virtual void					Unk_9E(void) override;																																															// 09E
		virtual TESAmmo*				GetCurrentAmmo() const override;																																												// 09F
		virtual void					UnequipItem(UInt64 a_arg1, TESBoundObject* a_object) override;																																					// 0A2

		// override (MagicTarget)
		virtual Actor*						 GetTargetStatsObject() override;	   // 002 - { return this; }
		virtual bool						 MagicTargetIsActor() const override;  // 003 - { return true; }
		virtual BSSimpleList<ActiveEffect*>* GetActiveEffectList() override;	   // 007

		// add
		virtual void				 Unk_A3(void);																																									  // 0A3
		virtual void				 PlayPickUpSound(TESBoundObject* a_object, bool a_pickup, bool a_use);																											  // 0A4
		virtual float				 GetHeading(bool a_ignoreRaceSettings) const;																																	  // 0A5
		virtual void				 SetAvoidanceDisabled(bool a_set);																																				  // 0A6 - { return; }
		virtual void				 Unk_A7(void);																																									  // 0A7
		virtual void				 DrawWeaponMagicHands(bool a_draw);																																				  // 0A8
		virtual void				 Unk_A9(void);																																									  // 0A9
		virtual void				 Unk_AA(void);																																									  // 0AA
		virtual void				 SetPosition(const NiPoint3& a_pos, bool a_updateCharController);																												  // 0AB
		virtual void				 KillDying();																																									  // 0AC
		virtual void				 Resurrect(bool a_resetInventory, bool a_attach3D);																																  // 0AD
		virtual bool				 PutActorOnMountQuick();																																						  // 0AE
		virtual void				 Update(float a_delta);																																							  // 0AF
		virtual void				 UpdateNoAI(float a_delta);																																						  // 0B0 - { return UpdateActor3DPosition(); }
		virtual void				 UpdateCharacterControllerSimulationSettings(bhkCharacterController& a_controller);																								  // 0B1
		virtual void				 PotentiallyFixRagdollState();																																					  // 0B2
		virtual void				 UpdateNonRenderSafe(float a_delta);																																			  // 0B3
		virtual void				 OnItemEquipped(bool a_playAnim);																																				  // 0B4
		virtual void				 Unk_B5(void);																																									  // 0B5 - { return 1; }
		virtual void				 Unk_B6(void);																																									  // 0B6
		virtual void				 SetCrimeGoldValue(TESFaction* a_faction, bool a_violent, UInt32 a_amount);																										  // 0B7
		virtual void				 ModCrimeGoldValue(TESFaction* a_faction, bool a_violent, SInt32 a_amount);																										  // 0B8
		virtual void				 RemoveCrimeGoldValue(TESFaction* a_faction, SInt32 a_amount, bool a_violent);																									  // 0B9
		virtual UInt32				 GetCrimeGoldValue(const TESFaction* a_faction) const;																															  // 0BA
		virtual void				 GoToPrison(TESFaction* a_faction, bool a_removeInventory, bool a_realJail);																									  // 0BB - { return; }
		virtual void				 ServePrisonTime();																																								  // 0BC - { return; }
		virtual void				 PayFine(TESFaction* a_faction, bool a_goToJail, bool a_removeStolenItems);																										  // 0BD - { return; }
		virtual bool				 GetCannibal();																																									  // 0BE - { return false; }
		virtual void				 SetCannibal(bool a_set);																																						  // 0BF - { return; }
		virtual bool				 GetVampireFeed();																																								  // 0C0 - { return false; }
		virtual void				 SetVampireFeed(bool a_set);																																					  // 0C1 - { return; }
		virtual void				 InitiateVampireFeedPackage(Actor* a_target, TESObjectREFR* a_furniture);																										  // 0C2 - { return; }
		virtual void				 InitiateCannibalPackage(Actor* a_target);																																		  // 0C3 - { return; }
		virtual void				 GetEyeVector(NiPoint3& a_origin, NiPoint3& a_direction, bool a_includeCameraOffset);																							  // 0C4
		virtual void				 SetRefraction(bool a_enable, float a_refraction);																																  // 0C5
		virtual void				 Unk_C6(void);																																									  // 0C6 - { return; }
		virtual void				 Unk_C7(void);																																									  // 0C7 - { return 1; }
		virtual void				 Unk_C8(void) = 0;																																								  // 0C8
		virtual float				 GetAcrobatics() const;																																							  // 0C9 - { return 1.0; }
		virtual void				 Unk_CA(void);																																									  // 0CA
		virtual void				 Unk_CB(void);																																									  // 0CB
		virtual void				 OnArmorActorValueChanged();																																					  // 0CC - { return; }
		virtual ObjectRefHandle		 DropObject(const TESBoundObject* a_object, ExtraDataList* a_extraList, SInt32 a_count, const NiPoint3* a_dropLoc = 0, const NiPoint3* a_rotate = 0);							  // 0CD
		virtual void				 PickUpObject(TESObjectREFR* a_object, SInt32 a_count, bool a_arg3 = false, bool a_playSound = true);																			  // 0CE
		virtual void				 AttachArrow(const BSTSmartPointer<BipedAnim>& a_biped);																														  // 0CF
		virtual void				 DetachArrow(const BSTSmartPointer<BipedAnim>& a_biped);																														  // 0D0
		virtual bool				 AddShout(TESShout* a_shout);																																					  // 0D1
		virtual void				 Unk_D2(void);																																									  // 0D2 - { return; }
		virtual void				 Unk_D3(void);																																									  // 0D3
		virtual UInt32				 UseAmmo(UInt32 a_shotCount);																																					  // 0D4
		virtual bool				 CalculateCachedOwnerIsInCombatantFaction() const;																																  // 0D5
		virtual CombatGroup*		 GetCombatGroup() const;																																						  // 0D6
		virtual void				 SetCombatGroup(CombatGroup* a_group);																																			  // 0D7
		virtual bool				 CheckValidTarget(TESObjectREFR& a_target);																																		  // 0D8
		virtual void				 Unk_D9(void);																																									  // 0D9 - { return 0; }
		virtual void				 InitiateDialogue(Actor* a_target, PackageLocation* a_loc1, PackageLocation* a_loc2);																							  // 0DA
		virtual void				 Unk_DB(void);																																									  // 0DB
		virtual void				 EndDialogue();																																									  // 0DC
		virtual Actor*				 SetUpTalkingActivatorActor(Actor* a_target, Actor*& a_activator);																												  // 0DD
		virtual void				 Unk_DE(void);																																									  // 0DE - { return; }
		virtual void				 InitiateFlee(TESObjectREFR* a_fleeRef, bool a_runOnce, bool a_knows, bool a_combatMode, TESObjectCELL* a_cell, TESObjectREFR* a_ref, float a_fleeFromDist, float a_fleeToDist);  // 0DF
		virtual void				 InitiateGetUpPackage();																																						  // 0E0
		virtual void				 PutCreatedPackage(TESPackage* a_package, bool a_tempPackage, bool a_createdPackage, bool a_allowFromFurniture);																  // 0E1
		virtual void				 UpdateAlpha();																																									  // 0E2
		virtual void				 SetAlpha(float a_alpha = 1.0);																																					  // 0E3
		virtual float				 GetAlpha();																																									  // 0E4
		virtual bool				 IsInCombat() const;																																							  // 0E5
		virtual void				 UpdateCombat();																																								  // 0E6
		virtual void				 StopCombat();																																									  // 0E7
		virtual void				 Unk_E8(void);																																									  // 0E8 - { return 0.0; }
		virtual void				 Unk_E9(void);																																									  // 0E9 - { return 0.0; }
		virtual void				 Unk_EA(void);																																									  // 0EA - { return 0; }
		virtual void				 Unk_EB(void);																																									  // 0EB - { return 0; }
		virtual void				 Unk_EC(void);																																									  // 0EC - { return 0; }
		virtual void				 Unk_ED(void);																																									  // 0ED
		virtual void				 Unk_EE(void);																																									  // 0EE
		virtual void				 Unk_EF(void);																																									  // 0EF
		virtual void				 Unk_F0(void);																																									  // 0F0
		virtual void				 WeaponSwingCallBack();																																							  // 0F1
		virtual void				 SetActorStartingPosition();																																					  // 0F2
		virtual void				 Unk_F3(void);																																									  // 0F3
		virtual void				 Unk_F4(void);																																									  // 0F4
		virtual void				 Unk_F5(void);																																									  // 0F5
		virtual void				 Unk_F6(void);																																									  // 0F6
		virtual bool				 HasBeenAttacked() const;																																						  // 0F7
		virtual void				 SetBeenAttacked(bool a_set);																																					  // 0F8
		virtual void				 UseSkill(ActorValue a_av, float a_points, TESForm* a_arg3);																													  // 0F9 - { return; }
		virtual bool				 IsAtPoint(const NiPoint3& a_point, float a_radius, bool a_expandRadius, bool a_alwaysTestHeight);																				  // 0FA
		virtual bool				 IsInFaction(const TESFaction* faction) const;																																	  // 0FB
		virtual void				 ForEachPerk(PerkEntryVisitor& a_visitor) const;																																  // 0FC - { return; }
		virtual void				 AddPerk(BGSPerk* a_perk, UInt32 a_rank = 0);																																	  // 0FD - { return; }
		virtual void				 RemovePerk(BGSPerk* a_perk);																																					  // 0FE - { return; }
		virtual void				 Unk_FF(void);																																									  // 0FF
		virtual void				 Unk_100(void);																																									  // 100
		virtual bool				 HasPerkEntries(EntryPoint a_entryType) const;																																	  // 101
		virtual void				 ForEachPerkEntry(EntryPoint a_entryType, PerkEntryVisitor& a_visitor) const;																									  // 102 - { return; }
		virtual void				 ApplyPerksFromBase();																																							  // 103 - { return false; }
		virtual void				 StartPowerAttackCoolDown();																																					  // 104
		virtual bool				 IsPowerAttackCoolingDown() const;																																				  // 105
		virtual void				 HandleHealthDamage(Actor* a_attacker, float a_damage);																															  // 106 - { return; }
		virtual void				 Unk_107(void);																																									  // 107 - { return ~(unk0E0 >> 5) & 1; }
		virtual void				 Unk_108(void);																																									  // 108
		virtual bool				 QSpeakingDone() const;																																							  // 109
		virtual void				 SetSpeakingDone(bool a_set);																																					  // 10A - { return unk16C; }
		virtual void				 CreateMovementController();																																					  // 10B - { unk16C = a_arg1; }
		virtual void				 Unk_10C(void);																																									  // 12C - { return unk170; }
		virtual void				 Unk_10D(void);																																									  // 10D - { unk170 = a_arg1; }
		virtual void				 Unk_10E(void);																																									  // 10E
		virtual void				 Unk_10F(void);																																									  // 10F
		virtual void				 KillImpl(Actor* a_attacker, float a_damage, bool a_sendEvent, bool a_ragdollInstant);																							  // 110
		virtual void				 Unk_111(void);																																									  // 111 - { return; }
		virtual bool				 CheckCast(MagicItem* a_spell, bool a_dualCast, MagicSystem::CannotCastReason* a_reason);																						  // 112 - return -1 on error
		virtual void				 CheckTempModifiers();																																							  // 113 - { return; }
		virtual SInt32				 GetCurrentShoutLevel();																																						  // 114 - { return {}; }
		virtual void				 SetLastRiddenMount(ActorHandle a_mount);																																		  // 115
		virtual ActorHandle			 QLastRiddenMount() const;																																						  // 116
		virtual bool				 CalculateCachedOwnerIsUndead() const;																																			  // 117 - { return; }
		virtual bool				 CalculateCachedOwnerIsNPC() const;																																				  // 118
		virtual void				 Unk_119(void);																																									  // 119 - { return "ActorResponse"; }
		virtual void				 Unk_11A(void);																																									  // 11A
		virtual const BSFixedString& GetResponseString() const;																																						  // 11B
		virtual void				 Unk_11C(void);																																									  // 11C
		virtual void				 UpdateCombatControllerSettings();																																				  // 11D
		virtual void				 UpdateFadeSettings(bhkCharacterController* a_controller);																														  // 11E
		virtual bool				 ComputeMotionFeedbackSpeedAndDirection(const ActorMotionFeedbackData& a_data, float a_delta, ActorMotionFeedbackOutput& a_output);												  // 11F
		virtual bool				 UpdateFeedbackGraphSpeedAndDirection(const ActorMotionFeedbackOutput& a_output);																								  // 120
		virtual void				 UpdateActor3DPosition();																																						  // 121
		virtual void				 PrecacheData();																																								  // 122
		virtual void				 WornArmorChanged(void);																																						  // 123
		virtual void				 ProcessTracking(float a_delta, NiAVObject* a_obj3D);																															  // 124
		virtual void				 Unk_125(void);																																									  // 125
		virtual void				 CreateActorMover();																																							  // 126
		virtual void				 DestroyActorMover();																																							  // 127
		virtual bool				 ShouldRespondToActorCollision(const MovementMessageActorCollision& a_msg, const ActorHandlePtr& a_target);
		virtual float				 CheckClampDamageModifier(ActorValue a_av, float a_delta);	
		static NiPointer<Actor>		 LookupByHandle(RefHandle a_refHandle);
		static bool					 LookupByHandle(RefHandle a_refHandle, NiPointer<Actor>& a_refrOut);

		bool                      AddSpell(SpellItem* a_spell);
		void                      AddToFaction(TESFaction* a_faction, std::int8_t a_rank);
		void                      AllowBleedoutDialogue(bool a_canTalk);
		void                      AllowPCDialogue(bool a_talk);
		bool                      CanFlyHere() const;
		bool                      CanPickpocket() const;
		bool                      CanTalkToPlayer() const;
		void                      ClearArrested();
		void                      ClearExpressionOverride();
		void                      ClearExtraArrows();
		ActorHandle               CreateRefHandle();
		void                      Decapitate();
		void                      DispelWornItemEnchantments();
		void					  DoReset3D(bool a_updateWeight);
		void					  EnableAI(bool a_enable);
		void                      EvaluatePackage(bool a_arg1 = false, bool a_arg2 = false);
		TESNPC*                   GetActorBase();
		const TESNPC*             GetActorBase() const;
		InventoryEntryData*       GetAttackingWeapon();
		const InventoryEntryData* GetAttackingWeapon() const;
		bhkCharacterController*   GetCharController() const;
		TESFaction*               GetCrimeFaction();
		const TESFaction*         GetCrimeFaction() const;
		InventoryEntryData*       GetEquippedEntryData(bool a_leftHand) const;
		TESForm*                  GetEquippedObject(bool a_leftHand) const;
		SInt32                    GetGoldAmount();
		NiAVObject*               GetHeadPartObject(BGSHeadPart::HeadPartType a_type);
		float                     GetHeight();
		Actor*                    GetKiller() const;
		UInt16                    GetLevel() const;
		TESRace*                  GetRace() const;
		TESObjectARMO*            GetSkin(BGSBipedObjectForm::BipedObjectSlot a_slot);
		SOUL_LEVEL                GetSoulLevel() const;
		TESObjectARMO*            GetWornArmor(BGSBipedObjectForm::BipedObjectSlot a_slot);
		TESObjectARMO*            GetWornArmor(FormID a_ID);
		bool                      HasKeyword(const BGSKeyword* a_keyword) const;
		bool                      HasKeyword(const char* a_formEditorID) const;
		bool                      HasPerk(BGSPerk* a_perk) const;
		bool                      HasSpell(SpellItem* a_spell) const;
		bool                      InstantKill();
		bool                      IsAIEnabled() const;
		bool                      IsAMount() const;
		bool                      IsBeingRidden() const;
		bool                      IsCommandedActor() const;
		bool                      IsEssential() const;
		bool                      IsFactionInCrimeGroup(const TESFaction* a_faction) const;
		bool                      IsGhost() const;
		bool                      IsGuard() const;
		bool                      IsHostileToActor(Actor* a_actor);
		bool                      IsInKillMove() const;
		bool                      IsLimbGone(UInt32 a_limb);
		bool                      IsOnMount() const;
		bool                      IsPlayerTeammate() const;
		bool                      IsRunning() const;
		bool                      IsSneaking() const;
		bool                      IsSummoned() const;
		bool                      IsTrespassing() const;
		bool                      RemoveSelectedSpell(SpellItem* a_spell) const;
		bool                      RemoveSpell(SpellItem* a_spell);
		SInt32                    RequestDetectionLevel(Actor* a_target, DETECTION_PRIORITY a_priority = DETECTION_PRIORITY::kNormal);
		void                      StealAlarm(TESObjectREFR* a_refItemOrContainer, TESForm* a_stolenItem, SInt32 a_numItems, SInt32 a_value, TESForm* a_owner, bool a_allowGetBackStolenItemPackage);
		void                      SwitchRace(TESRace* a_race, bool a_player);
		void                      UpdateArmorAbility(TESForm* a_armor, ExtraDataList* a_extraData);
		void                      Update3DModel();
		void                      UpdateHairColor();
		void                      UpdateSkinColor();
		void                      UpdateWeaponAbility(TESForm* a_weapon, ExtraDataList* a_extraData, bool a_leftHand);
		NiAVObject*               VisitArmorAddon(TESObjectARMO* a_armor, TESObjectARMA* a_arma);
		bool                      VisitFactions(llvm::function_ref<bool(TESFaction* a_faction, SInt8 a_rank)> a_visitor);


		// members
		BOOL_BITS							   boolBits;						   // 0E0
		float								   updateTargetTimer;				   // 0E4
		ACTOR_CRITICAL_STAGE				   criticalStage;					   // 0E8
		UInt32								   pad0EC;							   // 0EC
		AIProcess*							   currentProcess;					   // 0F0
		ObjectRefHandle						   dialogueItemTarget;				   // 0F8
		ActorHandle							   currentCombatTarget;				   // 0FC
		ActorHandle							   myKiller;						   // 100
		float								   checkMyDeadBodyTimer;			   // 104
		float								   voiceTimer;						   // 108
		float								   underWaterTimer;					   // 10C
		SInt32								   thiefCrimeStamp;					   // 110
		SInt32								   actionValue;						   // 114
		float								   timerOnAction;					   // 118
		UInt32								   unk11C;							   // 11C
		NiPoint3							   editorLocCoord;					   // 120
		float								   editorLocRot;					   // 12C
		TESForm*							   editorLocForm;					   // 130
		BGSLocation*						   editorLocation;					   // 138
		ActorMover*							   actorMover;						   // 140
		BSTSmartPointer<MovementControllerNPC> movementController;				   // 148
		void*								   unk150;							   // 150
		CombatController*					   combatController;				   // 158
		TESFaction*							   vendorFaction;					   // 160
		AITimeStamp							   calculateVendorFactionTimer;		   // 168
		UInt32								   unk16C;							   // 16C
		UInt32								   unk170;							   // 170
		UInt32								   unk174;							   // 174
		UInt32								   unk178;							   // 178
		UInt32								   intimidateBribeDayStamp;			   // 17C
		UInt64								   unk180;							   // 180
		BSTSmallArray<SpellItem*>			   addedSpells;						   // 188
		ActorMagicCaster*					   magicCasters[SlotTypes::kTotal];	   // 1A0
		MagicItem*							   selectedSpells[SlotTypes::kTotal];  // 1C0
		TESForm*							   selectedPower;					   // 1E0
		UInt32								   unk1E8;							   // 1E8
		UInt32								   pad1EC;							   // 1EC
		TESRace*							   race;							   // 1F0
		float								   equippedWeight;					   // 1F8
		BOOL_FLAGS							   boolFlags;						   // 1FC
		ActorValueStorage					   avStorage;						   // 200
		BGSDialogueBranch*					   exclusiveBranch;					   // 220
		Modifiers							   healthModifiers;					   // 228
		Modifiers							   magickaModifiers;				   // 234
		Modifiers							   staminaModifiers;				   // 240
		Modifiers							   voicePointsModifiers;			   // 24C
		float								   lastUpdate;						   // 258
		UInt32								   lastSeenTime;					   // 25C
		BSTSmartPointer<BipedAnim>			   biped;							   // 260
		float								   armorRating;						   // 268
		float								   armorBaseFactorSum;				   // 26C
		SInt8								   soundCallBackSet;				   // 271
		UInt8								   unk271;							   // 270
		UInt8								   unk272;							   // 272
		UInt8								   unk273;							   // 273
		UInt32								   unk274;							   // 274
		UInt64								   unk278;							   // 278
		UInt64								   unk280;							   // 280
		CRITICAL_SECTION					   unk288;							   // 288 - havok related

	private:
		TESFaction* GetCrimeFactionImpl() const;
	};
	STATIC_ASSERT(sizeof(Actor) == 0x2B0);
}
