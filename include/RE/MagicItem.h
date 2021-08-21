#pragma once

#include "RE/ActorValues.h"
#include "RE/BGSKeywordForm.h"
#include "RE/BSTArray.h"
#include "RE/BSTSmartPointer.h"
#include "RE/MagicSystem.h"
#include "RE/TESBoundObject.h"
#include "RE/TESFullName.h"


namespace RE
{
	class Actor;
	class ActorValueInfo;
	class Character;
	class EffectItem;
	class EffectSetting;
	class QueuedFile;
	class TESModel;
	class TESObjectWEAP;
	struct Effect;


	class MagicItem :
		public TESBoundObject,	// 00
		public TESFullName,		// 30
		public BGSKeywordForm	// 40
	{
	public:
		inline static constexpr auto RTTI = RTTI_MagicItem;


		class PreloadableVisitor
		{
		public:
			// add
			virtual void VisitModel(TESModel* a_model) = 0;			// 00
			virtual void VisitWeapon(TESObjectWEAP* a_weapon) = 0;	// 01
		};
		STATIC_ASSERT(sizeof(PreloadableVisitor) == 0x8);


		struct SkillUsageData
		{
			EffectItem* effect;		// 00
			ActorValue	skill;		// 08
			float		magnitude;	// 0C
			bool		custom;		// 10
			UInt8		pad11;		// 11
			UInt16		pad12;		// 12
			UInt32		pad14;		// 14
		};
		STATIC_ASSERT(sizeof(SkillUsageData) == 0x18);


		class Data
		{
		public:
			SInt32 costOverride;  // 0
			UInt32 flags;		  // 4
		};
		STATIC_ASSERT(sizeof(Data) == 0x8);


		virtual ~MagicItem();  // 00

		// override (TESBoundObject)
		virtual void InitializeData() override;			 // 04 - { TESForm::InitDefaults(); }
		virtual bool Load(TESFile* a_mod) override;		 // 06
		virtual void InitItemImpl() override;			 // 13
		virtual bool IsMagicItem() const override;		 // 29 - { return true; }
		virtual void Copy(TESForm* a_srcForm) override;	 // 2F
		virtual bool IsAutoCalc() const override;		 // 3E - { return (GetData().flags & 1) == 0; }

		// override (BGSKeywordForm)
		virtual bool HasKeyword(const BGSKeyword* a_keyword) const override;  // 04

		// add
		virtual MagicSystem::SpellType	 GetSpellType() const = 0;								// 53
		virtual void					 SetCastingType(MagicSystem::CastingType a_type);		// 54 - { return; }
		virtual MagicSystem::CastingType GetCastingType() const = 0;							// 55
		virtual void					 SetDelivery(MagicSystem::Delivery a_delivery);			// 56 - { return; }
		virtual MagicSystem::Delivery	 GetDelivery() const = 0;								// 57
		virtual bool					 IsValidDelivery(MagicSystem::Delivery a_delivery);		// 58 - { return true; }
		virtual float					 GetFixedCastDuration() const;							// 59 - { return 0.0; }
		virtual float					 GetRange() const;										// 5A - { return 0.0; }
		virtual bool					 IgnoresResistance() const;								// 5B - { return false; }
		virtual bool					 IgnoreLOS() const;										// 5C - { return false; }
		virtual bool					 IsFood() const;										// 5D - { return false; }
		virtual bool					 GetNoAbsorb() const;									// 5E - { return false; }
		virtual bool					 GetNoDualCastModifications() const;					// 5F - { return false; }
		virtual bool					 GetSkillUsageData(SkillUsageData& a_data) const;		// 60 - { return false; }
		virtual bool					 IsPoison() const;										// 61 - { return GetSpellType() == MagicSystem::SpellType::kPoison; }
		virtual bool					 IsMedicine() const;									// 62 - { return false; }
		virtual void					 AdjustCost(float& a_cost, Actor* a_actor) const;		// 63 - { return; }
		virtual float					 GetChargeTime() const;									// 64 - { return 0.0; }
		virtual UInt32					 GetMaxEffectCount() const;								// 65 - { return 0; }
		virtual ActorValue				 GetAssociatedSkill() const;							// 66 - { return ActorValue::kNone; }
		virtual bool					 IsTwoHanded() const;									// 67 - { return false; }
		virtual UInt32					 GetChunkID() = 0;										// 68
		virtual void					 CopyMagicItemData(MagicItem* a_src) = 0;				// 69
		virtual void					 LoadMagicItemChunk(TESFile* a_mod, UInt32 a_chunkID);	// 6A - { return; }
		virtual void					 LoadChunkDataPostProcess(TESFile* a_mod);				// 6B - { return; }
		virtual const Data*				 GetData1() const = 0;									// 6C
		virtual Data*					 GetData2() = 0;										// 6D
		virtual UInt32					 GetDataSize() const = 0;								// 6E
		virtual void					 InitFromChunk(TESFile* a_mod) = 0;						// 6F
		virtual void					 InitChunk() = 0;										// 70

		float		CalculateMagickaCost(Actor* a_caster) const;
		float		CalculateTotalGoldValue(Actor* a_caster = nullptr) const;
		Effect*		GetCostliestEffectItem(UInt32 a_arg1 = 5, bool a_arg2 = false);
		Data*		GetData();
		const Data* GetData() const;
		Effect*		GetEffectIsMatch(EffectSetting* a_base, float a_mag, UInt32 a_area, UInt32 a_dur, float a_cost);


		// members
		BSTArray<Effect*>			effects;		  // 58
		SInt32						hostileCount;	  // 70
		UInt32						pad74;			  // 74
		EffectSetting*				avEffectSetting;  // 78
		UInt32						preloadCount;	  // 80
		UInt32						pad84;			  // 84
		BSTSmartPointer<QueuedFile> preloadedItem;	  // 88

	protected:
		float CalculateCost(Actor* a_caster) const;
	};
	STATIC_ASSERT(sizeof(MagicItem) == 0x90);
}
