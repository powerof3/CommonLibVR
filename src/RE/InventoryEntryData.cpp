#include "RE/InventoryEntryData.h"

#include "RE/ExtraDataList.h"
#include "RE/ExtraEnchantment.h"
#include "RE/ExtraHotkey.h"
#include "RE/ExtraLeveledItem.h"
#include "RE/ExtraTextDisplayData.h"
#include "RE/GameSettingCollection.h"
#include "RE/Offsets.h"
#include "RE/TESBoundObject.h"
#include "RE/TESEnchantableForm.h"
#include "RE/TESSoulGem.h"
#include "RE/FormTraits.h"
#include "REL/Relocation.h"


namespace RE
{
	InventoryEntryData::InventoryEntryData() :
		object(nullptr),
		extraLists(nullptr),
		countDelta(0),
		pad14(0)
	{}


	InventoryEntryData::InventoryEntryData(const InventoryEntryData& a_rhs) :
		object(a_rhs.object),
		extraLists(nullptr),
		countDelta(a_rhs.countDelta),
		pad14(0)
	{
		if (a_rhs.extraLists) {
			extraLists = new BSSimpleList<ExtraDataList*>(*a_rhs.extraLists);
		}
	}


	InventoryEntryData::InventoryEntryData(InventoryEntryData&& a_rhs) :
		object(std::move(a_rhs.object)),
		extraLists(std::move(a_rhs.extraLists)),
		countDelta(std::move(a_rhs.countDelta)),
		pad14(0)
	{
		a_rhs.object = nullptr;
		a_rhs.extraLists = nullptr;
		a_rhs.countDelta = 0;
	}


	InventoryEntryData::InventoryEntryData(TESBoundObject* a_object, SInt32 a_countDelta) :
		object(a_object),
		extraLists(nullptr),
		countDelta(a_countDelta),
		pad14(0)
	{
		extraLists = new BSSimpleList<ExtraDataList*>;
	}


	InventoryEntryData::~InventoryEntryData()
	{
		delete extraLists;
	}


	InventoryEntryData& InventoryEntryData::operator=(const InventoryEntryData& a_rhs)
	{
		if (this == &a_rhs) {
			return *this;
		}

		object = a_rhs.object;

		delete extraLists;
		if (a_rhs.extraLists) {
			extraLists = new BSSimpleList<ExtraDataList*>(*a_rhs.extraLists);
		} else {
			extraLists = nullptr;
		}

		countDelta = a_rhs.countDelta;

		return *this;
	}


	InventoryEntryData& InventoryEntryData::operator=(InventoryEntryData&& a_rhs)
	{
		if (this == &a_rhs) {
			return *this;
		}

		object = std::move(a_rhs.object);
		a_rhs.object = nullptr;

		delete extraLists;
		extraLists = std::move(a_rhs.extraLists);
		a_rhs.extraLists = nullptr;

		countDelta = std::move(a_rhs.countDelta);
		a_rhs.countDelta = 0;

		return *this;
	}


	void InventoryEntryData::AddExtraList(ExtraDataList* a_extra)
	{
		if (!a_extra) {
			return;
		}

		if (!extraLists) {
			extraLists = new BSSimpleList<ExtraDataList*>;
		}

		extraLists->push_front(a_extra);
	}


	bool InventoryEntryData::CanItemBeTaken(bool a_noEquipped, bool a_noFavourited, bool a_noQuestItem) const
	{
		if (a_noEquipped && GetWorn()) {
			return false;
		}
		if (a_noFavourited && IsFavorited()) {
			return false;
		}
		if (a_noQuestItem && IsQuestObject()) {
			return false;
		}
		return true;
	}


	const char* InventoryEntryData::GetDisplayName()
	{
		const char* name = nullptr;
		if (extraLists && !extraLists->empty()) {
			name = extraLists->front()->GetDisplayName(object);
		} else if (object) {
			name = object->GetName();
		}

		if (!name || name[0] == '\0') {
			auto gmst = GameSettingCollection::GetSingleton();
			auto sMissingName = gmst ? gmst->GetSetting("sMissingName") : nullptr;
			name = sMissingName ? sMissingName->GetString() : "";
		}

		return name;
	}


	TESBoundObject* InventoryEntryData::GetObject()
	{
		return object;
	}


	TESForm* InventoryEntryData::GetOwner()
	{
		if (extraLists && !extraLists->empty()) {
			return extraLists->front()->GetOwner();
		} else {
			return nullptr;
		}
	}


	SOUL_LEVEL InventoryEntryData::GetSoulLevel() const
	{
		if (extraLists) {
			for (auto& xList : *extraLists) {
				if (!xList) {
					continue;
				}

				auto lvl = xList->GetSoulLevel();
				if (lvl > SOUL_LEVEL::kNone) {
					return lvl;
				}
			}
		}

		if (object && object->Is(FormType::SoulGem)) {
			auto soulGem = static_cast<const TESSoulGem*>(object);
			return soulGem->GetContainedSoul();
		}

		return SOUL_LEVEL::kNone;
	}


	SInt32 InventoryEntryData::GetValue()
	{
		using func_t = decltype(&InventoryEntryData::GetValue);
		REL::Offset<func_t> func(Offset::InventoryEntryData::GetValue);
		return func(this);
	}


	float InventoryEntryData::GetWeight() const
	{
		return object ? object->GetWeight() : static_cast<float>(-1.0);
	}


	bool InventoryEntryData::GetWorn() const
	{
		if (extraLists) {
			for (auto& xList : *extraLists) {
				if (xList) {
					auto worn = xList->GetWorn();
					if (worn) {
						return true;
					}
				}
			}
		}
		return false;
	}


	bool InventoryEntryData::IsEnchanted() const
	{
		if (object) {
			auto ench = object->As<TESEnchantableForm>();
			if (ench && ench->formEnchanting) {
				return true;
			}
		}

		if (extraLists) {
			for (const auto& xList : *extraLists) {
				const auto xEnch = xList->GetByType<ExtraEnchantment>();
				if (xEnch && xEnch->enchantment) {
					return true;
				}
			}
		}

		return false;
	}


	bool InventoryEntryData::IsFavorited() const
	{
		if (extraLists) {
			for (const auto& xList : *extraLists) {
				auto favorited = xList->HasType<ExtraHotkey>();
				if (favorited) {
					return true;
				}
			}
		}

		return false;
	}


	bool InventoryEntryData::IsLeveled() const
	{
		if (extraLists) {
			for (const auto& xList : *extraLists) {
				if (xList && xList->HasType<ExtraLeveledItem>()) {
					return true;
				}
			}
		}

		return false;
	}


	bool InventoryEntryData::IsOwnedBy(Actor* a_actor, bool a_defaultTo)
	{
		return IsOwnedBy(a_actor, GetOwner(), a_defaultTo);
	}


	bool InventoryEntryData::IsOwnedBy(Actor* a_actor, TESForm* a_itemOwner, bool a_defaultTo)
	{
		return IsOwnedBy_Impl(a_actor, a_itemOwner, a_defaultTo);
	}


	bool InventoryEntryData::IsOwnedBy_Impl(Actor* a_actor, TESForm* a_itemOwner, bool a_defaultTo)
	{
		using func_t = decltype(&InventoryEntryData::IsOwnedBy_Impl);
		REL::Offset<func_t> func(Offset::InventoryEntryData::IsOwnedBy);
		return func(this, a_actor, a_itemOwner, a_defaultTo);
	}


	bool InventoryEntryData::IsQuestObject() const
	{
		using func_t = decltype(&InventoryEntryData::IsQuestObject);
		REL::Offset<func_t> func = 0x1E7740;
		return func(this);
	}
}
