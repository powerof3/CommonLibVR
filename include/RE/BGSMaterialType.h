#pragma once

#include "RE/BSFixedString.h"
#include "RE/FormTypes.h"
#include "RE/NiColor.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSMaterialType : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMaterialType;
		inline static constexpr auto FORMTYPE = FormType::MaterialType;


		enum class FLAG : UInt32
		{
			kNone = 0,
			kStairs = 1 << 0,
			kArrowsStick = 1 << 1
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSMaterialType();	 // 00

		// override (TESForm)
		virtual void ClearData() override;			 // 04
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		BGSMaterialType*  parentType;		   // 20 - PNAM
		BSFixedString	  materialName;		   // 28 - MNAM
		UInt32			  materialID;		   // 30
		NiColor			  materialColor;	   // 34 - CNAM
		float			  buoyancy;			   // 40 - BNAM
		FLAG			  flags;			   // 44 - FNAM
		BGSImpactDataSet* havokImpactDataSet;  // 48 - HNAM
	};
	STATIC_ASSERT(sizeof(BGSMaterialType) == 0x50);
}
