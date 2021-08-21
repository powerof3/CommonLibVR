#include "RE/TESObjectARMO.h"

#include "RE/TESObjectARMA.h"


namespace RE
{
	TESObjectARMA* TESObjectARMO::GetArmorAddon(TESRace* a_race)
	{
		if (a_race) {
			for (auto& currentAddon : armorAddons) {
				if (currentAddon && currentAddon->IsValidRace(a_race)) {
					return currentAddon;
				}
			}
		}

		return nullptr;
	}

	
	TESObjectARMA* TESObjectARMO::GetArmorAddonByMask(TESRace* a_race, BGSBipedObjectForm::BipedObjectSlot a_slot)
	{
		if (a_race) {
			for (auto& currentAddon : armorAddons) {
				if (currentAddon && currentAddon->IsValidRace(a_race) && (currentAddon->GetSlotMask() & a_slot) == a_slot) {
					return currentAddon;
				}
			}
		}

		return nullptr;
	}


	float TESObjectARMO::GetArmorRating()
	{
		return static_cast<float>(armorRating) / static_cast<float>(100.0);
	}
}
