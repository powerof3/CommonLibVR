#pragma once

#include "RE/BSISoundDescriptor.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSSoundDescriptor;


	class BGSSoundDescriptorForm :
		public TESForm,			   // 00
		public BSISoundDescriptor  // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSSoundDescriptorForm;
		inline static constexpr auto FORMTYPE = FormType::SoundRecord;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSSoundDescriptorForm();	// 00

		// override (TESForm)
		virtual void ClearData() override;						   // 05
		virtual bool Load(TESFile* a_mod) override;				   // 06
		virtual void InitItemImpl() override;					   // 13
		virtual bool SetFormEditorID(const char* a_str) override;  // 33

		// add
		virtual UInt32 GetDescriptorType();	 // 3B - { return soundDescriptor->GetType(); }


		// members
		BGSSoundDescriptor* soundDescriptor;  // 28
	};
	STATIC_ASSERT(sizeof(BGSSoundDescriptorForm) == 0x30);
}
