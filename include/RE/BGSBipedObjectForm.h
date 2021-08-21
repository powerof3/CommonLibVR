#pragma once

#include "RE/BaseFormComponent.h"


namespace RE
{
	struct BIPED_MODEL	// BOD2
	{
		enum class BipedObjectSlot : UInt32
		{
			kNone = 0,
			kHead = 1 << 0,
			kHair = 1 << 1,
			kBody = 1 << 2,
			kHands = 1 << 3,
			kForearms = 1 << 4,
			kAmulet = 1 << 5,
			kRing = 1 << 6,
			kFeet = 1 << 7,
			kCalves = 1 << 8,
			kShield = 1 << 9,
			kTail = 1 << 10,
			kLongHair = 1 << 11,
			kCirclet = 1 << 12,
			kEars = 1 << 13,
			kModMouth = 1 << 14,
			kModNeck = 1 << 15,
			kModChestPrimary = 1 << 16,
			kModBack = 1 << 17,
			kModMisc1 = 1 << 18,
			kModPelvisPrimary = 1 << 19,
			kDecapitateHead = 1 << 20,
			kDecapitate = 1 << 21,
			kModPelvisSecondary = 1 << 22,
			kModLegRight = 1 << 23,
			kModLegLeft = 1 << 24,
			kModFaceJewelry = 1 << 25,
			kModChestSecondary = 1 << 26,
			kModShoulder = 1 << 27,
			kModArmLeft = 1 << 28,
			kModArmRight = 1 << 29,
			kModMisc2 = 1 << 30,
			kFX01 = (UInt32)1 << 31
		};


		enum class ArmorType : UInt32
		{
			kLightArmor,
			kHeavyArmor,
			kClothing
		};


		BipedObjectSlot bipedObjectSlots;  // 0
		ArmorType		armorType;		   // 4
	};
	STATIC_ASSERT(sizeof(BIPED_MODEL) == 0x8);


	class BGSBipedObjectForm : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSBipedObjectForm;


		using ArmorType = BIPED_MODEL::ArmorType;
		using BipedObjectSlot = BIPED_MODEL::BipedObjectSlot;
		using FirstPersonFlag = BIPED_MODEL::BipedObjectSlot;


		virtual ~BGSBipedObjectForm();	// 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01
		virtual void ClearDataComponent() override;						// 02 - { return; }
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03


		BipedObjectSlot AddSlotToMask(BipedObjectSlot a_slot);
		ArmorType		GetArmorType() const;
		BipedObjectSlot GetSlotMask() const;
		bool			HasPartOf(BipedObjectSlot a_flag) const;
		bool			IsClothing() const;
		bool			IsHeavyArmor() const;
		bool			IsLightArmor() const;
		bool			IsShield() const;
		BipedObjectSlot RemoveSlotFromMask(BipedObjectSlot a_slot);
		void			SetSlotMask(BipedObjectSlot a_mask);


		// members
		BIPED_MODEL bipedModelData;	 // 08 - BOD2
	};
	STATIC_ASSERT(sizeof(BGSBipedObjectForm) == 0x10);
}
