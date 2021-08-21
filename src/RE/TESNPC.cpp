#include "RE/TESNPC.h"

#include "RE/FormTraits.h"
#include "RE/Offsets.h"
#include "RE/TESRace.h"
#include "RE/TESSpellList.h"
#include "REL/Relocation.h"


namespace RE
{
	bool TESNPC::AddPerk(BGSPerk* a_perk, SInt8 a_rank)
	{
		if (GetPerkIndex(a_perk) == std::nullopt) {
			auto newPerk = new PerkRankData(a_perk, a_rank);
			if (newPerk) {
				auto oldData = perks;
				perks = calloc<PerkRankData>(++perkCount);
				if (oldData) {
					for (UInt32 i = 0; i < perkCount - 1; i++) {
						perks[i] = oldData[i];
					}
					free(oldData);
					oldData = nullptr;
				}
				perks[perkCount - 1] = *newPerk;
				return true;
			}
		}
		return false;
	}


	TESNPC::HeadRelatedData::HeadRelatedData() :
		hairColor(nullptr),
		faceDetails(nullptr)
	{}


	void TESNPC::ChangeHeadPart(BGSHeadPart* a_target)
	{
		using func_t = decltype(&TESNPC::ChangeHeadPart);
		REL::Offset<func_t> func(Offset::TESNPC::ChangeHeadPart);
		return func(this, a_target);
	}


	BGSHeadPart** TESNPC::GetBaseOverlays() const
	{
		using func_t = decltype(&TESNPC::GetBaseOverlays);
		REL::Offset<func_t> func(Offset::TESNPC::GetBaseOverlays);
		return func(this);
	}

	std::optional<UInt32> TESNPC::GetPerkIndex(BGSPerk* a_perk) const
	{
		std::optional<UInt32> index = std::nullopt;
		if (perks) {
			for (UInt32 i = 0; i < perkCount; i++) {
				if (perks[i].perk && perks[i].perk == a_perk) {
					index = i;
					break;
				}
			}
		}
		return index;
	}


	SEX TESNPC::GetSex() const
	{
		return IsFemale() ? SEX::kFemale : SEX::kMale;
	}


	TESObjectARMO* TESNPC::GetSkin() const
	{
		if (skin) {
			return skin;
		}
		if (race && race->skin) {
			return race->skin;
		}
		return nullptr;
	}


	bool TESNPC::IsInClass(TESClass* a_class) const
	{
		return npcClass ? npcClass == a_class : false;
	}


	BGSHeadPart* TESNPC::GetCurrentHeadPartByType(HeadPartType a_type)
	{
		auto headpart = HasOverlays() ? GetHeadPartOverlayByType(a_type) : GetHeadPartByType(a_type);
		if (!headpart && race) {
			headpart = race->GetHeadPartByType(a_type, GetSex());
		}
		return headpart;
	}


	BGSHeadPart* TESNPC::GetHeadPartByType(HeadPartType a_type)
	{
		if (headParts) {
			for (SInt8 i = 0; i < numHeadParts; ++i) {
				if (headParts[i] && headParts[i]->type == a_type) {
					return headParts[i];
				}
			}
		}
		return nullptr;
	}


	BGSHeadPart* TESNPC::GetHeadPartOverlayByType(HeadPartType a_type)
	{
		const auto numOverlays = GetNumBaseOverlays();
		auto overlays = GetBaseOverlays();
		if (overlays) {
			for (UInt32 i = 0; i < numOverlays; ++i) {
				if (overlays[i]->type == a_type) {
					return overlays[i];
				}
			}
		}
		return nullptr;
	}


	float TESNPC::GetHeight() const
	{
		if (!race) {
			return height;
		}

		const auto sex = GetSex();
		switch (sex) {
		case SEX::kMale:
		case SEX::kFemale:
			return race->data.height[sex] * height;
		default:
			return 0.0;
		}
	}


	UInt32 TESNPC::GetNumBaseOverlays() const
	{
		using func_t = decltype(&TESNPC::GetNumBaseOverlays);
		REL::Offset<func_t> func(Offset::TESNPC::GetNumBaseOverlays);
		return func(this);
	}


	TESSpellList::SpellData* TESNPC::GetOrCreateSpellList()
	{
		if (!actorEffects) {
			actorEffects = new TESSpellList::SpellData();
		}
		return actorEffects;
	}


	TESRace* TESNPC::GetRace()
	{
		return race;
	}


	TESNPC* TESNPC::GetRootFaceNPC()
	{
		auto iter = this;
		while (iter->faceNPC) {
			iter = iter->faceNPC;
		}
		return iter;
	}


	const TESNPC* TESNPC::GetRootFaceNPC() const
	{
		auto iter = this;
		while (iter->faceNPC) {
			iter = iter->faceNPC;
		}
		return iter;
	}


	float TESNPC::Layer::GetInterpolationValue() const
	{
		return static_cast<float>(interpolationValue) / static_cast<float>(100.0);
	}


	bool TESNPC::HasKeyword(std::string_view a_formEditorID) const
	{
		bool hasKeyword = HasKeywordString(a_formEditorID);
		if (!hasKeyword && race) {
			hasKeyword = race->HasKeywordString(a_formEditorID);
		}
		return hasKeyword;
	}


	bool TESNPC::HasOverlays()
	{
		using func_t = decltype(&TESNPC::HasOverlays);
		REL::Offset<func_t> func(Offset::TESNPC::HasOverlays);
		return func(this);
	}


	bool TESNPC::RemovePerk(BGSPerk* a_perk)
	{
		auto index = GetPerkIndex(a_perk);
		if (index != std::nullopt) {
			auto oldData = perks;
			if (oldData) {
				perks = calloc<PerkRankData>(--perkCount);
				for (UInt32 i = 0; i < perkCount + 1; i++) {
					if (index != i) {
						perks[i] = oldData[i];
					}
				}
				free(oldData);
				oldData = nullptr;
				return true;
			}
		}
		return false;
	}


	void TESNPC::SetFaceTexture(BGSTextureSet* a_textureSet)
	{
		if (!headRelatedData && a_textureSet) {
			headRelatedData = new HeadRelatedData();
		}

		if (headRelatedData) {
			headRelatedData->faceDetails = a_textureSet;
		}
	}


	void TESNPC::SetHairColor(BGSColorForm* a_hairColor)
	{
		if (!headRelatedData && a_hairColor) {
			headRelatedData = new HeadRelatedData();
		}

		if (headRelatedData) {
			headRelatedData->hairColor = a_hairColor;
		}
	}


	void TESNPC::SetSkinFromTint(NiColorA* a_result, TintMask* a_tintMask, bool a_fromTint)
	{
		using func_t = decltype(&TESNPC::SetSkinFromTint);
		REL::Offset<func_t> func(Offset::TESNPC::SetSkinFromTint);
		return func(this, a_result, a_tintMask, a_fromTint);
	}


	void TESNPC::UpdateNeck(BSFaceGenNiNode* a_faceNode)
	{
		using func_t = decltype(&TESNPC::UpdateNeck);
		REL::Offset<func_t> func(Offset::TESNPC::UpdateNeck);
		return func(this, a_faceNode);
	}
}
