#include "RE/TESWorldSpace.h"


namespace RE
{
	bool TESWorldSpace::HasMaxHeightData() const
	{
		return maxHeightData != nullptr;
	}


	float TESWorldSpace::GetWaterHeight() const
	{
		auto world = this;
		while (world->parentWorld && (world->parentUseFlags & ParentUseFlag::kUseLandData) != ParentUseFlag::kNone) {
			world = world->parentWorld;
		}
		return world->defaultWaterHeight;
	}
}
