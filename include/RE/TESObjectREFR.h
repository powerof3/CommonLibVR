#pragma once

#include <memory>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <vector>

#include "function_ref.h"

#include "RE/BSFixedString.h"
#include "RE/BSHandleRefObject.h"
#include "RE/BSPointerHandle.h"
#include "RE/BSTArray.h"
#include "RE/BSTEvent.h"
#include "RE/BSTList.h"
#include "RE/BSTSmartPointer.h"
#include "RE/ExtraDataList.h"
#include "RE/FormTypes.h"
#include "RE/IAnimationGraphManagerHolder.h"
#include "RE/MagicSystem.h"
#include "RE/NiPoint3.h"
#include "RE/NiSmartPointer.h"
#include "RE/TESForm.h"


namespace RE
{
	enum class LOCK_LEVEL : UInt32;
	class ActorCause;
	class BGSAnimationSequencer;
	class BGSDialogueBranch;
	class BipedAnim;
	class BSAnimNoteReceiver;
	class BSFaceGenAnimationData;
	class BSFaceGenNiNode;
	class BSFlattenedBoneTree;
	class DialogueResponse;
	class Explosion;
	class InventoryChanges;
	class InventoryEntryData;
	class MagicCaster;
	class MagicTarget;
	class NiAVObject;
	class NiControllerManager;
	class NiControllerSequence;
	class NiNode;
	class NiObject;
	class Projectile;
	class TargetEntry;
	class TESActorBase;
	class TESBoundObject;
	class TESContainer;
	class TrapData;
	class TrapEntry;
	struct BGSDecalGroup;
	struct BSAnimationGraphEvent;
	struct BSAnimationUpdateData;
	struct REFR_LOCK;


	enum class ITEM_REMOVE_REASON : UInt32
	{
		kRemove,
		kSteal,
		kSelling,
		kDropping,
		kStoreInContainer,
		kStoreInTeammate
	};


	struct OBJ_REFR
	{
		TESBoundObject* objectReference;  // 00
		NiPoint3		angle;			  // 08
		NiPoint3		location;		  // 14
	};
	STATIC_ASSERT(sizeof(OBJ_REFR) == 0x20);


	struct LOADED_REF_DATA
	{
		BSTSmallArray<void*>  unk00;				// 00 - handleList?
		TESWaterForm*		  currentWaterType;		// 18
		float				  relevantWaterHeight;	// 20
		float				  cachedRadius;			// 24
		UInt16				  flags;				// 28
		SInt16				  underwaterCount;		// 2A
		UInt32				  pad2C;				// 2C
		UInt64				  unk30;				// 30 - AIProcess::Data0B8
		UInt64				  unk38;				// 38
		UInt64				  unk40;				// 40
		UInt64				  unk48;				// 48
		UInt64				  unk50;				// 50
		UInt64				  unk58;				// 58
		UInt64				  unk60;				// 60
		NiPointer<NiAVObject> data3D;				// 68
		void*				  unk70;				// 70 - smart ptr
	};
	STATIC_ASSERT(sizeof(LOADED_REF_DATA) == 0x78);


	NiSmartPointer(TESObjectREFR);


	class TESObjectREFR :
		public TESForm,								 // 00
		public BSHandleRefObject,					 // 20
		public BSTEventSink<BSAnimationGraphEvent>,	 // 30
		public IAnimationGraphManagerHolder			 // 38
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESObjectREFR;


		using Count = SInt32;
		using InventoryCountMap = std::unordered_map<TESBoundObject*, Count>;
		using InventoryItemMap = std::unordered_map<TESBoundObject*, std::pair<Count, std::unique_ptr<InventoryEntryData>>>;
		using InventoryDropMap = std::unordered_map<TESBoundObject*, std::pair<Count, std::vector<NiPointer<TESObjectREFR>>>>;
		inline static constexpr auto FORMTYPE = FormType::Reference;


		enum class MotionType : UInt32	// hkpMotion::MotionType
		{
			kDynamic = 1,
			kSphereInertia = 2,
			kBoxInertia = 3,
			kKeyframed = 4,
			kFixed = 5,
			kThinBoxInertia = 6,
			kCharacter = 7
		};


		struct ChangeFlags
		{
			enum ChangeFlag : UInt32
			{
				kMoved = 1 << 1,
				kHavokMoved = 1 << 2,
				kCellChanged = 1 << 3,
				kScale = 1 << 4,
				kInventory = 1 << 5,
				kOwnershipExtra = 1 << 6,
				kBaseObject = 1 << 7,
				kItemExtraData = 1 << 10,
				kAmmoExtra = 1 << 11,
				kLockExtra = 1 << 12,
				kEmpty = 1 << 21,
				kOpenDefaultState = 1 << 22,
				kOpenState = 1 << 23,
				kPromoted = 1 << 25,
				kActivatingChildren = 1 << 26,
				kLeveledInventory = 1 << 27,
				kAnimation = 1 << 28,
				kEncZoneExtra = 1 << 29,
				kCreatedOnlyExtra = 1 << 30,
				kGameOnlyExtra = (UInt32)1 << 31
			};
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kFlag4 = 1 << 4,
				kIsGroundPiece = kFlag4,
				kCollisionsDisabled = kFlag4,

				kDeleted = 1 << 5,
				kHiddenFromLocalMap = 1 << 6,  // TESObjectSTAT
				kTurnOffFire = 1 << 7,

				kFlag8 = 1 << 8,
				kInaccessible = kFlag8,			   // TESObjectDOOR
				kLODRespectsEnableState = kFlag8,  // TESObjectSTAT
				kStartsDead = kFlag8,			   // TESNPC
				kDoesntLightWater = kFlag8,

				kMotionBlur = 1 << 9,  // TESObjectSTAT
				kPersistent = 1 << 10,
				kInitiallyDisabled = 1 << 11,
				kIgnored = 1 << 12,

				kFlag13 = 1 << 13,
				kStartUnconscious = kFlag13,  // TESNPC
				kSkyMarker = kFlag13,
				kHarvested = kFlag13,  // TESObjectTREE

				kIsFullLOD = 1 << 16,	// Actor
				kNeverFades = 1 << 16,	// TESObjectLIGH

				kDoesntLightLandscape = 1 << 17,

				kIgnoreFriendlyHits = 1 << 20,	// Actor

				kNoAIAcquire = 1 << 25,
				kCollisionGeometry_Filter = 1 << 26,
				kCollisionGeometry_BoundingBox = 1 << 27,
				kReflectedByAutoWater = 1 << 28,

				kDontHavokSettle = 1 << 29,

				kFlag30 = 1 << 30,
				kGround = kFlag30,
				kRespawns = kFlag30,

				kMultibound = (UInt32)1 << 31
			};
		};


		virtual ~TESObjectREFR();  // 00

		// override (TESForm)
		virtual void				 InitializeData() override;															   // 04
		virtual void				 ClearData() override;																   // 05
		virtual bool				 Load(TESFile* a_mod) override;														   // 06
		virtual TESForm*			 CreateDuplicateForm(bool a_createEditorID, void* a_arg2) override;					   // 09
		virtual bool				 CheckSaveGame(BGSSaveFormBuffer* a_buf) override;									   // 0D
		virtual void				 SaveGame(BGSSaveFormBuffer* a_buf) override;										   // 0E
		virtual void				 LoadGame(BGSLoadFormBuffer* a_buf) override;										   // 0F
		virtual void				 InitLoadGame(BGSLoadFormBuffer* a_buf) override;									   // 10
		virtual void				 FinishLoadGame(BGSLoadFormBuffer* a_buf) override;									   // 11
		virtual void				 Revert(BGSLoadFormBuffer* a_buf) override;											   // 12
		virtual void				 InitItemImpl() override;															   // 13
		virtual FormType			 GetSavedFormType() const override;													   // 15
		virtual void				 GetFormDetailedString(char* a_buf, UInt32 a_bufLen) override;						   // 16
		virtual bool				 GetRandomAnim() const override;													   // 18 - { return data.objectReference->GetRandomAnim(); }
		virtual bool				 IsHeadingMarker() const override;													   // 1A - { return data.objectReference->formType == FormType::Light ? (flags & RecordFlags::kNeverFades) != 0 : false; }
		virtual bool				 GetDangerous() const override;														   // 1B - { return data.objectReference->GetDangerous(); }
		virtual bool				 GetObstacle() const override;														   // 1D - { return data.objectReference ? data.objectReference->GetObstacle() : false; }
		virtual bool				 GetOnLocalMap() const override;													   // 1F - { return (flags >> 9) & 1 && data.objectReference->GetOnLocalMap(); }
		virtual bool				 GetMustUpdate() const override;													   // 20 - { return data.objectReference->GetMustUpdate(); }
		virtual void				 SetOnLocalMap(bool a_set) override;												   // 21
		virtual bool				 GetIgnoredBySandbox() const override;												   // 22
		virtual void				 SetDelete(bool a_set) override;													   // 23
		virtual void				 SetAltered(bool a_set) override;													   // 24
		virtual bool				 IsWater() const override;															   // 2A - { return data.objectReference ? data.objectReference->IsWater() : false; }
		virtual TESObjectREFR*		 AsReference1() override;															   // 2B - { return this; }
		virtual const TESObjectREFR* AsReference2() const override;														   // 2C - { return this; }
		virtual bool				 BelongsInGroup(FORM* a_form, bool a_allowParentGroups, bool a_currentOnly) override;  // 30
		virtual void				 CreateGroupData(FORM* a_form, FORM_GROUP* a_group) override;						   // 31
		virtual const char*			 GetFormEditorID() const override;													   // 32

		// override (BSTEventSink<BSAnimationGraphEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BSAnimationGraphEvent* a_event, BSTEventSource<BSAnimationGraphEvent>* a_dispatcher) override;	// 01

		// override (IAnimationGraphManagerHolder)
		virtual bool GetAnimationGraphManagerImpl(BSTSmartPointer<BSAnimationGraphManager>& a_out) override;													   // 02
		virtual bool SetAnimationGraphManagerImpl(BSTSmartPointer<BSAnimationGraphManager>& a_in) override;														   // 03
		virtual bool PopulateGraphNodesToTarget(BSScrapArray<NiAVObject*>& a_nodes) override;																	   // 04
		virtual bool ConstructAnimationGraph(BSTSmartPointer<BShkbAnimationGraph>& a_out) override;																   // 05
		virtual bool SetupAnimEventSinks(const BSTSmartPointer<BShkbAnimationGraph>& a_animGraph) override;														   // 08
		virtual void PostChangeAnimationManager(const BSTSmartPointer<BShkbAnimationGraph>& a_arg1, const BSTSmartPointer<BShkbAnimationGraph>& a_arg2) override;  // 0D

		// add
		virtual void							  Predestroy();																																															 // 3B
		virtual BGSLocation*					  GetEditorLocation1() const;																																											 // 3C
		virtual bool							  GetEditorLocation2(NiPoint3& a_outPos, NiPoint3& a_outRot, TESForm*& a_outWorldOrCell, TESObjectCELL* a_fallback);																					 // 3D
		virtual void							  ForceEditorLocation(BGSLocation* a_location);																																							 // 3E
		virtual void							  Update3DPosition(bool a_warp);																																										 // 3F
		virtual void							  UpdateSoundCallBack(bool a_endSceneAction);																																							 // 40
		virtual bool							  SetDialogueWithPlayer(bool a_flag, bool a_forceGreet, TESTopicInfo* a_topic);																															 // 41
		virtual void							  Unk_42(void);																																															 // 42
		virtual bool							  GetFullLODRef() const;																																												 // 43
		virtual void							  SetFullLODRef(bool a_set);																																											 // 44
		virtual BGSAnimationSequencer*			  GetSequencer() const;																																													 // 45
		virtual bool							  QCanUpdateSync() const;																																												 // 46 - { return true; }
		virtual bool							  GetAllowPromoteToPersistent() const;																																									 // 47 - { return true; }
		virtual bool							  HasKeywordHelper(const BGSKeyword* a_keyword) const;																																					 // 48
		virtual TESPackage*						  CheckForCurrentAliasPackage();																																										 // 49 - { return 0; }
		virtual BGSScene*						  GetCurrentScene() const;																																												 // 4A
		virtual void							  SetCurrentScene(BGSScene* a_scene);																																									 // 4B
		virtual bool							  UpdateInDialogue(DialogueResponse* a_response, bool a_unused);																																		 // 4C
		virtual BGSDialogueBranch*				  GetExclusiveBranch() const;																																											 // 4D
		virtual void							  SetExclusiveBranch(BGSDialogueBranch* a_branch);																																						 // 4E
		virtual void							  PauseCurrentDialogue();																																												 // 4F
		virtual void							  SetActorCause(ActorCause* a_cause);																																									 // 50
		virtual ActorCause*						  GetActorCause() const;																																												 // 51
		virtual NiPoint3						  GetStartingAngle() const;																																												 // 52
		virtual NiPoint3						  GetStartingLocation() const;																																											 // 53
		virtual void							  SetStartingPosition(const NiPoint3& a_pos);																																							 // 54
		virtual void							  UpdateRefLight();																																														 // 55
		virtual ObjectRefHandle					  RemoveItem(TESBoundObject* a_item, SInt32 a_count, ITEM_REMOVE_REASON a_reason, ExtraDataList* a_extraList, TESObjectREFR* a_moveToRef, const NiPoint3* a_dropLoc = 0, const NiPoint3* a_rotate = 0);	 // 56
		virtual bool							  AddWornItem(TESBoundObject* a_item, SInt32 a_count, bool a_forceEquip, UInt32 a_arg4, UInt32 a_arg5);																									 // 57
		virtual void							  DoTrap1(TrapData& a_data);																																											 // 58 - { return; }
		virtual void							  DoTrap2(TrapEntry* a_trap, TargetEntry* a_target);																																					 // 59 - { return; }
		virtual void							  AddObjectToContainer(TESBoundObject* a_object, ExtraDataList* a_extraList, SInt32 a_count, TESObjectREFR* a_fromRefr);																				 // 5A
		virtual NiPoint3						  GetLookingAtLocation() const;																																											 // 5B
		virtual MagicCaster*					  GetMagicCaster(MagicSystem::CastingSource a_source);																																					 // 5C
		virtual MagicTarget*					  GetMagicTarget();																																														 // 5D
		virtual bool							  IsChild() const;																																														 // 5E - { return false; }
		virtual TESActorBase*					  GetTemplateActorBase();																																												 // 5F - { return 0; }
		virtual void							  SetTemplateActorBase(TESActorBase* a_template);																																						 // 60 - { return; }
		virtual BSFaceGenNiNode*				  GetFaceNodeSkinned();																																													 // 61 - { return 0; }
		virtual BSFaceGenNiNode*				  GetFaceNode();																																														 // 62 - { return GetFaceNodeSkinned(); }
		virtual BSFaceGenAnimationData*			  GetFaceGenAnimationData();																																											 // 63 - { return 0; }
		virtual bool							  ClampToGround();																																														 // 64
		virtual bool							  DetachHavok(NiAVObject* a_obj3D);																																										 // 65
		virtual void							  InitHavok();																																															 // 66
		virtual void							  Unk_67(void);																																															 // 67 - { return; }
		virtual void							  Unk_68(void);																																															 // 68 - { return; }
		virtual void							  Unk_69(void);																																															 // 69 - { return; }
		virtual NiAVObject*						  Load3D(bool a_backgroundLoading);																																										 // 6A
		virtual void							  Release3DRelatedData();																																												 // 6B
		virtual void							  Set3D(NiAVObject* a_object, bool a_queue3DTasks = true);																																				 // 6C
		virtual bool							  ShouldBackgroundClone() const;																																										 // 6D
		virtual void							  Unk_6E(void);																																															 // 6E - { return; }
		virtual NiAVObject*						  Get3D1(bool a_firstPerson) const;																																										 // 6F - { return Get3D2(); }
		virtual NiAVObject*						  Get3D2() const;																																														 // 70
		virtual bool							  Is3rdPersonVisible() const;																																											 // 71 - { return true; }
		virtual bool							  PopulateGraphProjectsToLoad(void) const;																																								 // 72
		virtual NiPoint3						  GetBoundMin() const;																																													 // 73
		virtual NiPoint3						  GetBoundMax() const;																																													 // 74
		virtual void							  Unk_75(void);																																															 // 75 - { return 0; }
		virtual bool							  InitNonNPCAnimation(NiNode& a_nodeForAnim);																																							 // 76
		virtual bool							  CheckAndFixSkinAndBoneOrder(NiNode& a_nodeToTest);																																					 // 77
		virtual void							  Unk_78(void);																																															 // 78
		virtual void							  ModifyAnimationUpdateData(BSAnimationUpdateData& a_data);																																				 // 79 - { return; }
		virtual bool							  ShouldSaveAnimationOnUnloading() const;																																								 // 7A
		virtual bool							  ShouldSaveAnimationOnSaving() const;																																									 // 7B
		virtual bool							  ShouldPerformRevert() const;																																											 // 7C - { return true; }
		virtual void							  UpdateAnimation(float a_delta);																																										 // 7D
		virtual const BSTSmartPointer<BipedAnim>& GetBiped1(bool a_firstPerson) const;																																									 // 7E - { return GetBiped2(); }
		virtual const BSTSmartPointer<BipedAnim>& GetBiped2() const;																																													 // 7F
		virtual const BSTSmartPointer<BipedAnim>& GetCurrentBiped() const;																																												 // 80 - { return GetBiped2(); }
		virtual void							  SetBiped(const BSTSmartPointer<BipedAnim>& a_biped);																																					 // 81 - { return; }
		virtual void							  Unk_82(void);																																															 // 82 - { return; }
		virtual void							  Unk_83(void);																																															 // 83 - { return; }
		virtual void							  Unk_84(void);																																															 // 84 - { return; }
		virtual void							  SetObjectReference(TESBoundObject* a_object);																																							 // 85 - sets flag 24 if the object has destructibles
		virtual void							  MoveHavok(bool a_forceRec);																																											 // 86
		virtual void							  GetLinearVelocity(NiPoint3& a_velocity) const;																																						 // 87
		virtual void							  SetActionComplete(bool a_set);																																										 // 88 - { return; }
		virtual void							  SetMovementComplete(bool a_set);																																										 // 89 - { return; }
		virtual void							  Disable();																																															 // 8A
		virtual void							  ResetInventory(bool a_leveledOnly);																																									 // 8B
		virtual void							  Unk_8C(void);																																															 // 8C - { return 0; }
		virtual void							  Unk_8D(void);																																															 // 8D - { return; }
		virtual NiAVObject*						  GetCurrent3D() const;																																													 // 8E - { return Get3D2(); }
		virtual Explosion*						  AsExplosion();																																														 // 8F - { return 0; }
		virtual Projectile*						  AsProjectile();																																														 // 90 - { return 0; }
		virtual bool							  OnAddCellPerformQueueReference(TESObjectCELL& a_cell) const;																																			 // 91 - { return true; }
		virtual void							  DoMoveToHigh();																																														 // 92 - { return; }
		virtual void							  TryMoveToMiddleLow();																																													 // 93 - { return; }
		virtual bool							  TryChangeSkyCellActorsProcessLevel();																																									 // 94 - { return false; }
		virtual void							  Unk_95(void);																																															 // 95 - { return; }
		virtual void							  Unk_96(void);																																															 // 96 - { return; }
		virtual void							  Unk_97(void);																																															 // 97 - related to lockpicking
		virtual TESObjectCELL*					  GetSaveParentCell() const;																																											 // 98
		virtual void							  SetParentCell(TESObjectCELL* a_cell);																																									 // 99
		virtual bool							  IsDead(bool a_notEssential) const;																																									 // 9A
		virtual BSAnimNoteReceiver*				  CreateAnimNoteReceiver();																																												 // 9B
		virtual BSAnimNoteReceiver*				  GetAnimNoteReceiver();																																												 // 9C
		virtual void							  Unk_9D(void);																																															 // 9D
		virtual void							  Unk_9E(void);																																															 // 9E - { return 0; }
		virtual TESAmmo*						  GetCurrentAmmo() const;																																												 // 9F - { return 0; }
		virtual BGSDecalGroup*					  GetDecalGroup() const;																																												 // A0
		virtual void							  Unk_A1(void);																																															 // A1
		virtual void							  UnequipItem(UInt64 a_arg1, TESBoundObject* a_object);


		static NiPointer<TESObjectREFR> LookupByHandle(RefHandle a_refHandle);
		static bool						LookupByHandle(RefHandle a_refHandle, NiPointer<TESObjectREFR>& a_refrOut);
		static TESObjectREFR*			FindReferenceFor3D(NiAVObject* a_object3D);

		ObjectRefHandle							CreateRefHandle();
		void									DoTrap(TrapData& a_data);
		void									DoTrap(TrapEntry* a_trap, TargetEntry* a_target);
		NiAVObject*								Get3D() const;
		NiAVObject*								Get3D(bool a_firstPerson) const;
		TESNPC*									GetActorOwner();
		NiPoint3								GetAngle() const;
		float									GetAngleX() const;
		float									GetAngleY() const;
		float									GetAngleZ() const;
		float									GetBaseHeight() const;
		TESBoundObject*							GetBaseObject();
		const TESBoundObject*					GetBaseObject() const;
		const BSTSmartPointer<BipedAnim>&		GetBiped() const;
		const BSTSmartPointer<BipedAnim>&		GetBiped(bool a_firstPerson) const;
		TESContainer*							GetContainer();
		const char*								GetDisplayFullName();
		InventoryDropMap						GetDroppedInventory();
		InventoryDropMap						GetDroppedInventory(llvm::function_ref<bool(TESBoundObject*)> a_filter);
		BGSLocation*							GetEditorLocation() const;
		bool									GetEditorLocation(NiPoint3& a_outPos, NiPoint3& a_outRot, TESForm*& a_outWorldOrCell, TESObjectCELL* a_fallback);
		TESFaction*								GetFactionOwner();
		float									GetHeadingAngle(const RE::NiPoint3& a_pos, bool a_abs) const;
		float									GetHeight() const;
		InventoryItemMap						GetInventory();
		InventoryItemMap						GetInventory(std::function<bool(TESBoundObject&)> a_filter);
		SInt32									GetInventoryCount();
		InventoryCountMap						GetInventoryCounts();
		InventoryCountMap						GetInventoryCounts(std::function<bool(TESBoundObject&)> a_filter);
		InventoryChanges*						GetInventoryChanges();
		TESObjectREFR*							GetLinkedRef(BGSKeyword* a_keyword);
		REFR_LOCK*								GetLock() const;
		LOCK_LEVEL								GetLockLevel() const;
		const char*								GetName() const;
		NiAVObject*								GetNodeByName(const BSFixedString& a_nodeName);
		[[nodiscard]] constexpr TESBoundObject* GetObjectReference() const noexcept { return data.objectReference; }
		TESForm*								GetOwner() const;
		TESObjectCELL*							GetParentCell() const;
		NiPoint3								GetPosition() const;
		float									GetPositionX() const;
		float									GetPositionY() const;
		float									GetPositionZ() const;
		UInt32									GetStealValue(const InventoryEntryData* a_entryData, UInt32 a_numItems, bool a_useMult) const;
		float									GetSubmergedWaterLevel(float a_zPos, TESObjectCELL* a_cell);
		float									GetWaterHeight() const;
		float									GetWeight() const;
		TESWorldSpace*							GetWorldspace() const;
		bool									HasCollision() const;
		bool									HasKeyword(const BGSKeyword* a_keyword) const;
		bool									HasQuestObject() const;
		void									InitChildActivates(TESObjectREFR* a_activator);
		bool									InitInventoryIfRequired(bool a_skipExtra = false);
		bool									Is3DLoaded() const;
		bool									IsActivationBlocked() const;
		bool									IsCrimeToActivate();
		bool									IsDead() const;
		bool									IsDisabled() const;
		bool									IsHorse() const;
		bool									IsInitiallyDisabled() const;
		bool									IsLocked() const;
		bool									IsMarkedForDeletion() const;
		bool									IsOffLimits();
		bool									MoveToNode(TESObjectREFR* a_target, const BSFixedString& a_nodeName);
		bool									MoveToNode(TESObjectREFR* a_target, NiAVObject* a_node);
		void									PlayAnimation(std::string_view a_from, std::string_view a_to);
		void									PlayAnimation(NiControllerManager* a_manager, NiControllerSequence* a_toSeq, NiControllerSequence* a_fromSeq);
		void									SetActivationBlocked(bool a_blocked);
		void									SetCollision(bool a_enable);
		bool									SetDisplayName(const BSFixedString& a_name, bool a_force);
		bool									SetMotionType(MotionType a_motionType, bool a_allowActivate = true);
		void									SetPosition(float a_x, float a_y, float a_z);
		void									SetPosition(NiPoint3 a_pos);


		// members
		OBJ_REFR		 data;			// 40
		TESObjectCELL*	 parentCell;	// 60
		LOADED_REF_DATA* loadedData;	// 68
		ExtraDataList	 extraList;		// 70
		UInt64			 unk88;			// 88
		UInt16			 refScale;		// 90
		SInt8			 modelState;	// 92
		bool			 preDestroyed;	// 93
		UInt32			 pad94;			// 94

	private:
		void MoveTo_Impl(const ObjectRefHandle& a_targetHandle, TESObjectCELL* a_targetCell, TESWorldSpace* a_selfWorldSpace, const NiPoint3& a_position, const NiPoint3& a_rotation);
		void PlayAnimation_Impl(NiControllerManager* a_manager, NiControllerSequence* a_toSeq, NiControllerSequence* a_fromSeq, bool a_arg4 = false);
	};
	STATIC_ASSERT(sizeof(TESObjectREFR) == 0x98);
};
