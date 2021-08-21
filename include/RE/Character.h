#pragma once

#include "RE/Actor.h"


namespace RE
{
	class Character : public Actor
	{
	public:
		inline static constexpr auto RTTI = RTTI_Character;
		inline static constexpr auto FORMTYPE = FormType::ActorCharacter;


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


		virtual ~Character();  // 000

		// override (Actor)
		virtual void					SaveGame(BGSSaveFormBuffer* a_buf) override;								// 00E - { Actor::SaveBuffer(a_buf); }
		virtual void					LoadGame(BGSLoadFormBuffer* a_buf) override;								// 00F - { Actor::LoadBuffer(a_buf); }
		virtual void					InitLoadGame(BGSLoadFormBuffer* a_buf) override;							// 010 - { Actor::InitLoadGame(a_arg1); }
		virtual void					FinishLoadGame(BGSLoadFormBuffer* a_buf) override;							// 011 - { Actor::FinishLoadGame(a_arg1); }
		virtual void					Revert(BGSLoadFormBuffer* a_buf) override;									// 012 - { return; }
		virtual void					Predestroy(void) override;													// 03B
		virtual bool					IsChild() const override;													// 05E - { return race ? (race->data.flags & Flag::kChild) != Flag::kNone : false; }
		virtual BSFaceGenNiNode*		GetFaceNodeSkinned() override;												// 061
		virtual BSFaceGenAnimationData* GetFaceGenAnimationData() override;											// 063
		virtual void					SetBiped(const BSTSmartPointer<BipedAnim>& a_biped) override;				// 081
		virtual void					InitiateVampireFeedPackage(Actor* a_arg1, TESObjectREFR* a_arg2) override;	// 0C0
		virtual void					Unk_C6(void) override;														// 0C4 - { unk272 = a_arg1; }
		virtual void					Unk_C7(void) override;														// 0C5 - { return unk272; }
		virtual void					Unk_C8(void) override;														// 0C6 - { return 1; }
		virtual void					OnArmorActorValueChanged() override;										// 0CA
		virtual void					Unk_D9(void) override;														// 0D7
		virtual void					Unk_DB(void) override;														// 0D9
		virtual void					Unk_E8(void) override;														// 0E6 - calculate armor rating?
		virtual void					Unk_E9(void) override;														// 0E7 - something about armor rating
		virtual void					Unk_EA(void) override;														// 0E8 - get unarmed damage?
		virtual void					PrecacheData(void) override;												// 120

		// add
		virtual void Unk_128(void);	 // 128
		virtual void Unk_129(void);	 // 129 - { return 1; }
	};
	STATIC_ASSERT(sizeof(Character) == 0x2B0);
}
