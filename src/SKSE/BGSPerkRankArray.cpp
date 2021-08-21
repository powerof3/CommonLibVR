#include "RE/BGSPerkRankArray.h"


namespace RE
{
	PerkRankData::PerkRankData() :
		perk(nullptr),
		currentRank(0),
		pad09(0),
		pad0A(0),
		pad0C(0)
	{
	}


	PerkRankData::PerkRankData(BGSPerk* a_perk, SInt8 a_rank) :
		perk(a_perk),
		currentRank(a_rank),
		pad09(0),
		pad0A(0),
		pad0C(0)
	{
	}
}