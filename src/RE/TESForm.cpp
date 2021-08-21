#include "RE/TESForm.h"

#include "RE/BSScript/IObjectHandlePolicy.h"
#include "RE/BSScript/Internal/VirtualMachine.h"
#include "RE/ExtraEnchantment.h"
#include "RE/FormTraits.h"
#include "RE/MagicItem.h"
#include "RE/TESFullName.h"
#include "RE/TESModel.h"
#include "RE/TESObjectREFR.h"
#include "RE/TESValueForm.h"
#include "REL/Relocation.h"


namespace RE
{
	void TESForm::AddCompileIndex(FormID& a_id, TESFile* a_file)
	{
		using func_t = decltype(&TESForm::AddCompileIndex);
		//		REL::Offset<func_t> func = REL::ID(14509);   // VR is 1a5510
		REL::Offset<func_t> func = 0x1a5510;
		return func(a_id, a_file);
	}


	std::pair<BSTHashMap<FormID, TESForm*>*, std::reference_wrapper<BSReadWriteLock>> TESForm::GetAllForms()
	{
		//		REL::Offset<BSTHashMap<FormID, TESForm*>**> allForms = REL::ID(514351);   // SE is 1ec3cb8   VR is 1f88b18
		REL::Offset<BSTHashMap<FormID, TESForm*>**> allForms = 0x1f88b18;

		//		REL::Offset<BSReadWriteLock*> allFormsMapLock = REL::ID(514360);          // SE is 1ec4150   VR is 1f88fb0
		REL::Offset<BSReadWriteLock*> allFormsMapLock = 0x1f88fb0;
		return std::make_pair(*allForms, std::ref(*allFormsMapLock));
	}


	std::pair<BSTHashMap<BSFixedString, TESForm*>*, std::reference_wrapper<BSReadWriteLock>> TESForm::GetAllFormsByEditorID()
	{
		// REL::Offset<BSTHashMap<BSFixedString, TESForm*>**> allFormsByEditorID = REL::ID(514352);  // SSE is 1ec3cc0 VR is 1f88b20
		REL::Offset<BSTHashMap<BSFixedString, TESForm*>**> allFormsByEditorID = 0x1f88b20;

		//  REL::Offset<BSReadWriteLock*> allFormsEditorIDMapLock = REL::ID(514361);   // SSE is 1ec4158  VR is 1f88fb8
		REL::Offset<BSReadWriteLock*> allFormsEditorIDMapLock = 0x1f88fb8;

		return std::make_pair(*allFormsByEditorID, std::ref(*allFormsEditorIDMapLock));
	}


	TESForm* TESForm::LookupByID(FormID a_formID)
	{
		auto allForms = GetAllForms();
		BSReadLockGuard locker(allForms.second);
		if (!allForms.first) {
			return nullptr;
		}

		auto& formIDs = *allForms.first;
		auto it = formIDs.find(a_formID);
		return it != formIDs.end() ? it->second : nullptr;
	}


	TESForm* TESForm::LookupByEditorID(const std::string_view& a_editorID)
	{
		auto allFormsByEditorID = GetAllFormsByEditorID();
		BSReadLockGuard locker(allFormsByEditorID.second);
		if (!allFormsByEditorID.first) {
			return nullptr;
		}

		auto& editorIDs = *allFormsByEditorID.first;
		auto it = editorIDs.find(a_editorID);
		return it != editorIDs.end() ? it->second : nullptr;
	}


	TESObjectREFR* TESForm::AsReference()
	{
		return AsReference1();
	}


	const TESObjectREFR* TESForm::AsReference() const
	{
		return AsReference2();
	}


	TESFile* TESForm::GetFile(SInt32 a_idx) const
	{
		auto array = sourceFiles.array;
		if (!array || array->empty()) {
			return nullptr;
		}

		if (a_idx < 0 || a_idx >= array->size()) {
			return array->back();
		} else {
			return (*array)[a_idx];
		}
	}


	SInt32 TESForm::GetGoldValue() const
	{
		SInt32 value = 0;
		auto form = this;
		auto objRef = As<TESObjectREFR>();
		if (objRef) {
			form = objRef->GetBaseObject();
			auto xEnch = objRef->extraList.GetByType<ExtraEnchantment>();
			if (xEnch && xEnch->enchantment) {
				value += static_cast<SInt32>(xEnch->enchantment->CalculateTotalGoldValue());
			}
		}

		auto valueForm = form->As<TESValueForm>();
		if (valueForm) {
			value += valueForm->value;
		} else {
			auto magicItem = form->As<MagicItem>();
			if (magicItem) {
				value += static_cast<SInt32>(magicItem->CalculateTotalGoldValue());
			} else {
				value = -1;
			}
		}

		return value;
	}


	const char* TESForm::GetName() const
	{
		auto fullName = As<TESFullName>();
		if (fullName) {
			auto str = fullName->GetFullName();
			return str ? str : "";
		} else {
			return "";
		}
	}


	float TESForm::GetWeight() const
	{
		auto ref = As<TESObjectREFR>();
		auto baseObj = ref ? ref->GetBaseObject() : nullptr;
		auto form = baseObj ? baseObj : this;
		auto weightForm = form->As<TESWeightForm>();
		if (weightForm) {
			return weightForm->weight;
		} else if (form->Is(FormType::NPC)) {
			auto npc = static_cast<const TESNPC*>(form);
			return npc->weight;
		} else {
			return -1.0;
		}
	}


	bool TESForm::HasAllKeywords(BGSListForm* a_keywords) const
	{
		auto keywordForm = As<BGSKeywordForm>();
		if (keywordForm) {
			bool failed = false;
			if (!a_keywords->forms.empty()) {
				for (auto& form : a_keywords->forms) {
					if (form) {
						auto keyword = form->As<BGSKeyword>();
						if (!keyword || !keywordForm->HasKeyword(keyword)) {
							failed = true;
							break;
						}
					}
				}
			}
			if (a_keywords->scriptAddedTempForms) {
				for (const auto& formID : *a_keywords->scriptAddedTempForms) {
					auto keyword = LookupByID<BGSKeyword>(formID);
					if (!keyword || !keywordForm->HasKeyword(keyword)) {
						failed = true;
						break;
					}
				}
			}
			if (failed) {
				return false;
			}
			return true;
		}
		return false;
	}


	bool TESForm::HasAllKeywords(const std::vector<BGSKeyword*>& a_keywords) const
	{
		auto keywordForm = As<BGSKeywordForm>();
		if (keywordForm) {
			if (!a_keywords.empty()) {
				bool failed = false;
				for (auto& keyword : a_keywords) {
					if (keyword && !keywordForm->HasKeyword(keyword)) {
						failed = true;
						break;
					}
				}
				if (failed) {
					return false;
				}
			}
			return true;
		}
		return false;
	}


	bool TESForm::HasKeywords(BGSListForm* a_keywords) const
	{
		auto keywordForm = As<BGSKeywordForm>();
		if (keywordForm) {
			if (!a_keywords->forms.empty()) {
				for (auto& form : a_keywords->forms) {
					if (form) {
						auto keyword = form->As<BGSKeyword>();
						if (keyword && keywordForm->HasKeyword(keyword)) {
							return true;
						}
					}
				}
			}
			if (a_keywords->scriptAddedTempForms) {
				for (const auto& formID : *a_keywords->scriptAddedTempForms) {
					auto keyword = LookupByID<BGSKeyword>(formID);
					if (keyword && keywordForm->HasKeyword(keyword)) {
						return true;
					}
				}
			}
		}
		return false;
	}


	bool TESForm::HasKeywords(const std::vector<BGSKeyword*>& a_keywords) const
	{
		if (!a_keywords.empty()) {
			auto keywordForm = As<BGSKeywordForm>();
			if (keywordForm) {
				for (auto& keyword : a_keywords) {
					if (keyword && keywordForm->HasKeyword(keyword)) {
						return true;
					}
				}
			}
		}
		return false;
	}


	bool TESForm::HasVMAD() const
	{
		auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
		if (!vm) {
			return false;
		}

		auto policy = vm->GetObjectHandlePolicy();
		if (!policy) {
			return false;
		}

		const auto handle = policy->GetHandleForObject(GetFormType(), this);
		return handle != policy->EmptyHandle();
	}


	bool TESForm::HasWorldModel() const noexcept
	{
		return As<TESModel>() != nullptr;
	}


	void TESForm::InitItem()
	{
		InitItemImpl();
	}


	bool TESForm::IsAmmo() const noexcept
	{
		return Is(FormType::Ammo);
	}


	bool TESForm::IsArmor() const noexcept
	{
		return Is(FormType::Armor);
	}


	bool TESForm::IsDeleted() const noexcept
	{
		return (formFlags & RecordFlags::kDeleted) != 0;
	}


	bool TESForm::IsDynamicForm() const noexcept
	{
		return formID >= 0xFF000000;
	}


	bool TESForm::IsGold() const noexcept
	{
		return formID == 0x0000000F;
	}


	bool TESForm::IsIgnored() const noexcept
	{
		return (formFlags & RecordFlags::kIgnored) != 0;
	}


	bool TESForm::IsInitialized() const noexcept
	{
		return (formFlags & RecordFlags::kInitialized) != 0;
	}


	bool TESForm::IsKey() const noexcept
	{
		return Is(FormType::KeyMaster);
	}


	bool TESForm::IsLockpick() const noexcept
	{
		return formID == 0x0000000A;
	}


	bool TESForm::IsPlayer() const noexcept
	{
		return formID == 0x00000007;
	}


	bool TESForm::IsPlayerRef() const noexcept
	{
		return formID == 0x00000014;
	}


	bool TESForm::IsSoulGem() const noexcept
	{
		return Is(FormType::SoulGem);
	}


	bool TESForm::IsWeapon() const noexcept
	{
		return Is(FormType::Weapon);
	}
}
