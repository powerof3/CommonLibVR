#pragma once

#include <optional>

#include "RE/BaseFormComponent.h"


namespace RE
{
	class BGSKeyword;


	class BGSKeywordForm : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSKeywordForm;


		virtual ~BGSKeywordForm();	// 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01 - { return; }
		virtual void ClearDataComponent() override;						// 02
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual bool		HasKeyword(const BGSKeyword* a_keyword) const;	// 04
		virtual BGSKeyword* GetDefaultKeyword() const;						// 05 - { return 0; }

		bool					   AddKeyword(BGSKeyword* a_keyword);
		bool					   HasKeyword(FormID a_formID) const;
		bool					   HasKeywordString(std::string_view a_formEditorID) const;
		std::optional<BGSKeyword*> GetKeywordAt(UInt32 a_idx) const;
		UInt32					   GetNumKeywords() const;
		std::optional<UInt32>	   GetKeywordIndex(BGSKeyword* a_keyword) const;
		bool					   RemoveKeyword(BGSKeyword* a_keyword);


		// members
		BGSKeyword** keywords;	   // 08 - KWDA
		UInt32		 numKeywords;  // 10 - KSIZ
		UInt32		 pad14;		   // 14
	};
	STATIC_ASSERT(sizeof(BGSKeywordForm) == 0x18);
}
