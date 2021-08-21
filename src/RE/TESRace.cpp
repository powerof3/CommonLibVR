#include "RE/TESRace.h"


namespace RE
{
	bool TESRace::AllowsPCDialogue() const
	{
		return (data.flags & RACE_DATA::Flag::kAllowPCDialogue) != RACE_DATA::Flag::kNone;
	}


	bool TESRace::AllowsPickpocket() const
	{
		return (data.flags & RACE_DATA::Flag::kAllowPickpocket) != RACE_DATA::Flag::kNone;
	}

	
	BGSHeadPart* TESRace::GetHeadPartByType(HeadPartType a_type, SEX a_sex) const
	{
		auto faceData = faceRelatedData[a_sex];
		if (faceData && faceData->headParts) {
			for (auto& headpart : *faceData->headParts) {
				if (headpart && headpart->type == a_type) {
					return headpart;
				}
			}
		}

		return nullptr;
	}
}
