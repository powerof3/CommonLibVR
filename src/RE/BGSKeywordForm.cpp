#include "RE/BGSKeywordForm.h"

#include "RE/BGSKeyword.h"


namespace RE
{
	bool BGSKeywordForm::AddKeyword(BGSKeyword* a_keyword)
	{
		if (!GetKeywordIndex(a_keyword).has_value()) {
			auto oldData = keywords;
			keywords = calloc<BGSKeyword*>(++numKeywords);
			if (oldData) {
				for (UInt32 i = 0; i < numKeywords - 1; ++i) {
					keywords[i] = oldData[i];
				}
				free(oldData);
				oldData = nullptr;
			}
			keywords[numKeywords - 1] = a_keyword;
			return true;
		}
		return false;
	}

	
	bool BGSKeywordForm::HasKeyword(FormID a_formID) const
	{
		if (keywords) {
			for (UInt32 idx = 0; idx < numKeywords; ++idx) {
				if (keywords[idx] && keywords[idx]->formID == a_formID) {
					return true;
				}
			}
		}

		return false;
	}


	bool BGSKeywordForm::HasKeywordString(std::string_view a_formEditorID) const
	{
		if (keywords) {
			for (UInt32 idx = 0; idx < numKeywords; ++idx) {
				if (keywords[idx] && keywords[idx]->formEditorID == a_formEditorID) {
					return true;
				}
			}
		}

		return false;
	}


	std::optional<BGSKeyword*> BGSKeywordForm::GetKeywordAt(UInt32 a_idx) const
	{
		if (a_idx < numKeywords) {
			return std::make_optional(keywords[a_idx]);
		} else {
			return std::nullopt;
		}
	}


	std::optional<UInt32> BGSKeywordForm::GetKeywordIndex(BGSKeyword* a_keyword) const
	{
		std::optional<UInt32> index = std::nullopt;
		if (keywords) {
			for (UInt32 i = 0; i < numKeywords; ++i) {
				if (keywords[i] && keywords[i] == a_keyword) {
					index = i;
					break;
				}
			}
		}
		return index;
	}


	UInt32 BGSKeywordForm::GetNumKeywords() const
	{
		return numKeywords;
	}


		bool BGSKeywordForm::RemoveKeyword(BGSKeyword* a_keyword)
	{
		auto index = GetKeywordIndex(a_keyword);
		if (index.has_value()) {
			auto oldData = keywords;
			if (oldData) {
				keywords = calloc<BGSKeyword*>(--numKeywords);
				for (UInt32 i = 0; i < numKeywords + 1; ++i) {
					if (i != index.value()) {
						keywords[i] = oldData[i];
					}
				}
				free(oldData);
				oldData = nullptr;

				return true;
			}
		}
		return false;
	}
}
