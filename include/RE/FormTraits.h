#pragma once

#include "RE/Actor.h"
#include "RE/ActorValueInfo.h"
#include "RE/AlchemyItem.h"
#include "RE/ArrowProjectile.h"
#include "RE/BGSAcousticSpace.h"
#include "RE/BGSAction.h"
#include "RE/BGSAddonNode.h"
#include "RE/BGSApparatus.h"
#include "RE/BGSArtObject.h"
#include "RE/BGSAssociationType.h"
#include "RE/BGSBodyPartData.h"
#include "RE/BGSCameraPath.h"
#include "RE/BGSCameraShot.h"
#include "RE/BGSCollisionLayer.h"
#include "RE/BGSColorForm.h"
#include "RE/BGSConstructibleObject.h"
#include "RE/BGSDebris.h"
#include "RE/BGSDefaultObjectManager.h"
#include "RE/BGSDialogueBranch.h"
#include "RE/BGSDualCastData.h"
#include "RE/BGSEncounterZone.h"
#include "RE/BGSEquipSlot.h"
#include "RE/BGSExplosion.h"
#include "RE/BGSFootstep.h"
#include "RE/BGSFootstepSet.h"
#include "RE/BGSHazard.h"
#include "RE/BGSHeadPart.h"
#include "RE/BGSIdleMarker.h"
#include "RE/BGSImpactData.h"
#include "RE/BGSImpactDataSet.h"
#include "RE/BGSKeyword.h"
#include "RE/BGSLensFlare.h"
#include "RE/BGSLightingTemplate.h"
#include "RE/BGSListForm.h"
#include "RE/BGSLocation.h"
#include "RE/BGSLocationRefType.h"
#include "RE/BGSMaterialObject.h"
#include "RE/BGSMaterialType.h"
#include "RE/BGSMenuIcon.h"
#include "RE/BGSMessage.h"
#include "RE/BGSMovableStatic.h"
#include "RE/BGSMovementType.h"
#include "RE/BGSMusicTrackFormWrapper.h"
#include "RE/BGSMusicType.h"
#include "RE/BGSNote.h"
#include "RE/BGSOutfit.h"
#include "RE/BGSPerk.h"
#include "RE/BGSProjectile.h"
#include "RE/BGSRagdoll.h"
#include "RE/BGSReferenceEffect.h"
#include "RE/BGSRelationship.h"
#include "RE/BGSReverbParameters.h"
#include "RE/BGSScene.h"
#include "RE/BGSShaderParticleGeometryData.h"
#include "RE/BGSSoundCategory.h"
#include "RE/BGSSoundDescriptorForm.h"
#include "RE/BGSSoundOutput.h"
#include "RE/BGSStaticCollection.h"
#include "RE/BGSStoryManagerBranchNode.h"
#include "RE/BGSStoryManagerEventNode.h"
#include "RE/BGSStoryManagerQuestNode.h"
#include "RE/BGSTalkingActivator.h"
#include "RE/BGSTextureSet.h"
#include "RE/BGSVoiceType.h"
#include "RE/BGSVolumetricLighting.h"
#include "RE/BarrierProjectile.h"
#include "RE/BeamProjectile.h"
#include "RE/Character.h"
#include "RE/ConeProjectile.h"
#include "RE/EffectSetting.h"
#include "RE/EnchantmentItem.h"
#include "RE/FlameProjectile.h"
#include "RE/GrenadeProjectile.h"
#include "RE/Hazard.h"
#include "RE/IngredientItem.h"
#include "RE/MissileProjectile.h"
#include "RE/NavMesh.h"
#include "RE/NavMeshInfoMap.h"
#include "RE/PlayerCharacter.h"
#include "RE/Script.h"
#include "RE/ScrollItem.h"
#include "RE/SpellItem.h"
#include "RE/TESAmmo.h"
#include "RE/TESClass.h"
#include "RE/TESClimate.h"
#include "RE/TESCombatStyle.h"
#include "RE/TESEffectShader.h"
#include "RE/TESEyes.h"
#include "RE/TESFaction.h"
#include "RE/TESFlora.h"
#include "RE/TESForm.h"
#include "RE/TESFurniture.h"
#include "RE/TESGlobal.h"
#include "RE/TESGrass.h"
#include "RE/TESIdleForm.h"
#include "RE/TESImageSpace.h"
#include "RE/TESImageSpaceModifier.h"
#include "RE/TESKey.h"
#include "RE/TESLandTexture.h"
#include "RE/TESLevCharacter.h"
#include "RE/TESLevItem.h"
#include "RE/TESLevSpell.h"
#include "RE/TESLoadScreen.h"
#include "RE/TESNPC.h"
#include "RE/TESObjectACTI.h"
#include "RE/TESObjectANIO.h"
#include "RE/TESObjectARMA.h"
#include "RE/TESObjectARMO.h"
#include "RE/TESObjectBOOK.h"
#include "RE/TESObjectCELL.h"
#include "RE/TESObjectCONT.h"
#include "RE/TESObjectDOOR.h"
#include "RE/TESObjectLAND.h"
#include "RE/TESObjectLIGH.h"
#include "RE/TESObjectMISC.h"
#include "RE/TESObjectREFR.h"
#include "RE/TESObjectSTAT.h"
#include "RE/TESObjectTREE.h"
#include "RE/TESObjectWEAP.h"
#include "RE/TESPackage.h"
#include "RE/TESQuest.h"
#include "RE/TESRace.h"
#include "RE/TESRegion.h"
#include "RE/TESShout.h"
#include "RE/TESSoulGem.h"
#include "RE/TESSound.h"
#include "RE/TESTopic.h"
#include "RE/TESTopicInfo.h"
#include "RE/TESWaterForm.h"
#include "RE/TESWeather.h"
#include "RE/TESWordOfPower.h"
#include "RE/TESWorldSpace.h"


namespace RE
{
	template <
		class T,
		std::enable_if_t<
			TESForm_Impl::is_valid_as_expr_v<T>,
			int>>
	constexpr T* TESForm::As() noexcept
	{
		return const_cast<T*>(
			static_cast<const TESForm*>(this)->As<T>());
	}


	template <
		class T,
		std::enable_if_t<
			TESForm_Impl::is_valid_as_expr_v<T>,
			int>>
	constexpr const T* TESForm::As() const noexcept
	{
		switch (formType) {
		case FormType::None:
			if constexpr (std::is_convertible_v<const TESForm*, const T*>) {
				return static_cast<const TESForm*>(this);
			}
			break;
		case FormType::Keyword:
			if constexpr (std::is_convertible_v<const BGSKeyword*, const T*>) {
				return static_cast<const BGSKeyword*>(this);
			}
			break;
		case FormType::LocationRefType:
			if constexpr (std::is_convertible_v<const BGSLocationRefType*, const T*>) {
				return static_cast<const BGSLocationRefType*>(this);
			}
			break;
		case FormType::Action:
			if constexpr (std::is_convertible_v<const BGSAction*, const T*>) {
				return static_cast<const BGSAction*>(this);
			}
			break;
		case FormType::TextureSet:
			if constexpr (std::is_convertible_v<const BGSTextureSet*, const T*>) {
				return static_cast<const BGSTextureSet*>(this);
			}
			break;
		case FormType::MenuIcon:
			if constexpr (std::is_convertible_v<const BGSMenuIcon*, const T*>) {
				return static_cast<const BGSMenuIcon*>(this);
			}
			break;
		case FormType::Global:
			if constexpr (std::is_convertible_v<const TESGlobal*, const T*>) {
				return static_cast<const TESGlobal*>(this);
			}
			break;
		case FormType::Class:
			if constexpr (std::is_convertible_v<const TESClass*, const T*>) {
				return static_cast<const TESClass*>(this);
			}
			break;
		case FormType::Faction:
			if constexpr (std::is_convertible_v<const TESFaction*, const T*>) {
				return static_cast<const TESFaction*>(this);
			}
			break;
		case FormType::HeadPart:
			if constexpr (std::is_convertible_v<const BGSHeadPart*, const T*>) {
				return static_cast<const BGSHeadPart*>(this);
			}
			break;
		case FormType::Eyes:
			if constexpr (std::is_convertible_v<const TESEyes*, const T*>) {
				return static_cast<const TESEyes*>(this);
			}
			break;
		case FormType::Race:
			if constexpr (std::is_convertible_v<const TESRace*, const T*>) {
				return static_cast<const TESRace*>(this);
			}
			break;
		case FormType::Sound:
			if constexpr (std::is_convertible_v<const TESSound*, const T*>) {
				return static_cast<const TESSound*>(this);
			}
			break;
		case FormType::AcousticSpace:
			if constexpr (std::is_convertible_v<const BGSAcousticSpace*, const T*>) {
				return static_cast<const BGSAcousticSpace*>(this);
			}
			break;
		case FormType::MagicEffect:
			if constexpr (std::is_convertible_v<const EffectSetting*, const T*>) {
				return static_cast<const EffectSetting*>(this);
			}
			break;
		case FormType::Script:
			if constexpr (std::is_convertible_v<const Script*, const T*>) {
				return static_cast<const Script*>(this);
			}
			break;
		case FormType::LandTexture:
			if constexpr (std::is_convertible_v<const TESLandTexture*, const T*>) {
				return static_cast<const TESLandTexture*>(this);
			}
			break;
		case FormType::Enchantment:
			if constexpr (std::is_convertible_v<const EnchantmentItem*, const T*>) {
				return static_cast<const EnchantmentItem*>(this);
			}
			break;
		case FormType::Spell:
			if constexpr (std::is_convertible_v<const SpellItem*, const T*>) {
				return static_cast<const SpellItem*>(this);
			}
			break;
		case FormType::Scroll:
			if constexpr (std::is_convertible_v<const ScrollItem*, const T*>) {
				return static_cast<const ScrollItem*>(this);
			}
			break;
		case FormType::Activator:
			if constexpr (std::is_convertible_v<const TESObjectACTI*, const T*>) {
				return static_cast<const TESObjectACTI*>(this);
			}
			break;
		case FormType::TalkingActivator:
			if constexpr (std::is_convertible_v<const BGSTalkingActivator*, const T*>) {
				return static_cast<const BGSTalkingActivator*>(this);
			}
			break;
		case FormType::Armor:
			if constexpr (std::is_convertible_v<const TESObjectARMO*, const T*>) {
				return static_cast<const TESObjectARMO*>(this);
			}
			break;
		case FormType::Book:
			if constexpr (std::is_convertible_v<const TESObjectBOOK*, const T*>) {
				return static_cast<const TESObjectBOOK*>(this);
			}
			break;
		case FormType::Container:
			if constexpr (std::is_convertible_v<const TESObjectCONT*, const T*>) {
				return static_cast<const TESObjectCONT*>(this);
			}
			break;
		case FormType::Door:
			if constexpr (std::is_convertible_v<const TESObjectDOOR*, const T*>) {
				return static_cast<const TESObjectDOOR*>(this);
			}
			break;
		case FormType::Ingredient:
			if constexpr (std::is_convertible_v<const IngredientItem*, const T*>) {
				return static_cast<const IngredientItem*>(this);
			}
			break;
		case FormType::Light:
			if constexpr (std::is_convertible_v<const TESObjectLIGH*, const T*>) {
				return static_cast<const TESObjectLIGH*>(this);
			}
			break;
		case FormType::Misc:
			if constexpr (std::is_convertible_v<const TESObjectMISC*, const T*>) {
				return static_cast<const TESObjectMISC*>(this);
			}
			break;
		case FormType::Apparatus:
			if constexpr (std::is_convertible_v<const BGSApparatus*, const T*>) {
				return static_cast<const BGSApparatus*>(this);
			}
			break;
		case FormType::Static:
			if constexpr (std::is_convertible_v<const TESObjectSTAT*, const T*>) {
				return static_cast<const TESObjectSTAT*>(this);
			}
			break;
		case FormType::StaticCollection:
			if constexpr (std::is_convertible_v<const BGSStaticCollection*, const T*>) {
				return static_cast<const BGSStaticCollection*>(this);
			}
			break;
		case FormType::MovableStatic:
			if constexpr (std::is_convertible_v<const BGSMovableStatic*, const T*>) {
				return static_cast<const BGSMovableStatic*>(this);
			}
			break;
		case FormType::Grass:
			if constexpr (std::is_convertible_v<const TESGrass*, const T*>) {
				return static_cast<const TESGrass*>(this);
			}
			break;
		case FormType::Tree:
			if constexpr (std::is_convertible_v<const TESObjectTREE*, const T*>) {
				return static_cast<const TESObjectTREE*>(this);
			}
			break;
		case FormType::Flora:
			if constexpr (std::is_convertible_v<const TESFlora*, const T*>) {
				return static_cast<const TESFlora*>(this);
			}
			break;
		case FormType::Furniture:
			if constexpr (std::is_convertible_v<const TESFurniture*, const T*>) {
				return static_cast<const TESFurniture*>(this);
			}
			break;
		case FormType::Weapon:
			if constexpr (std::is_convertible_v<const TESObjectWEAP*, const T*>) {
				return static_cast<const TESObjectWEAP*>(this);
			}
			break;
		case FormType::Ammo:
			if constexpr (std::is_convertible_v<const TESAmmo*, const T*>) {
				return static_cast<const TESAmmo*>(this);
			}
			break;
		case FormType::NPC:
			if constexpr (std::is_convertible_v<const TESNPC*, const T*>) {
				return static_cast<const TESNPC*>(this);
			}
			break;
		case FormType::LeveledNPC:
			if constexpr (std::is_convertible_v<const TESLevCharacter*, const T*>) {
				return static_cast<const TESLevCharacter*>(this);
			}
			break;
		case FormType::KeyMaster:
			if constexpr (std::is_convertible_v<const TESKey*, const T*>) {
				return static_cast<const TESKey*>(this);
			}
			break;
		case FormType::AlchemyItem:
			if constexpr (std::is_convertible_v<const AlchemyItem*, const T*>) {
				return static_cast<const AlchemyItem*>(this);
			}
			break;
		case FormType::IdleMarker:
			if constexpr (std::is_convertible_v<const BGSIdleMarker*, const T*>) {
				return static_cast<const BGSIdleMarker*>(this);
			}
			break;
		case FormType::Note:
			if constexpr (std::is_convertible_v<const BGSNote*, const T*>) {
				return static_cast<const BGSNote*>(this);
			}
			break;
		case FormType::ConstructibleObject:
			if constexpr (std::is_convertible_v<const BGSConstructibleObject*, const T*>) {
				return static_cast<const BGSConstructibleObject*>(this);
			}
			break;
		case FormType::Projectile:
			if constexpr (std::is_convertible_v<const BGSProjectile*, const T*>) {
				return static_cast<const BGSProjectile*>(this);
			}
			break;
		case FormType::Hazard:
			if constexpr (std::is_convertible_v<const BGSHazard*, const T*>) {
				return static_cast<const BGSHazard*>(this);
			}
			break;
		case FormType::SoulGem:
			if constexpr (std::is_convertible_v<const TESSoulGem*, const T*>) {
				return static_cast<const TESSoulGem*>(this);
			}
			break;
		case FormType::LeveledItem:
			if constexpr (std::is_convertible_v<const TESLevItem*, const T*>) {
				return static_cast<const TESLevItem*>(this);
			}
			break;
		case FormType::Weather:
			if constexpr (std::is_convertible_v<const TESWeather*, const T*>) {
				return static_cast<const TESWeather*>(this);
			}
			break;
		case FormType::Climate:
			if constexpr (std::is_convertible_v<const TESClimate*, const T*>) {
				return static_cast<const TESClimate*>(this);
			}
			break;
		case FormType::ShaderParticleGeometryData:
			if constexpr (std::is_convertible_v<const BGSShaderParticleGeometryData*, const T*>) {
				return static_cast<const BGSShaderParticleGeometryData*>(this);
			}
			break;
		case FormType::ReferenceEffect:
			if constexpr (std::is_convertible_v<const BGSReferenceEffect*, const T*>) {
				return static_cast<const BGSReferenceEffect*>(this);
			}
			break;
		case FormType::Region:
			if constexpr (std::is_convertible_v<const TESRegion*, const T*>) {
				return static_cast<const TESRegion*>(this);
			}
			break;
		case FormType::Navigation:
			if constexpr (std::is_convertible_v<const NavMeshInfoMap*, const T*>) {
				return static_cast<const NavMeshInfoMap*>(this);
			}
			break;
		case FormType::Cell:
			if constexpr (std::is_convertible_v<const TESObjectCELL*, const T*>) {
				return static_cast<const TESObjectCELL*>(this);
			}
			break;
		case FormType::Reference:
			if constexpr (std::is_convertible_v<const TESObjectREFR*, const T*>) {
				return static_cast<const TESObjectREFR*>(this);
			}
			break;
		case FormType::ActorCharacter:
			if constexpr (std::is_convertible_v<const Actor*, const T*>) {
				return static_cast<const Actor*>(this);
			} else if constexpr (std::is_convertible_v<const Character*, const T*>) {
				return static_cast<const Character*>(this);
			} /* else if constexpr (std::is_convertible_v<const PlayerCharacter*, const T*>) {
					return static_cast<const PlayerCharacter*>(this);
				}*/
			break;
		case FormType::ProjectileMissile:
			if constexpr (std::is_convertible_v<const MissileProjectile*, const T*>) {
				return static_cast<const MissileProjectile*>(this);
			}
			break;
		case FormType::ProjectileArrow:
			if constexpr (std::is_convertible_v<const ArrowProjectile*, const T*>) {
				return static_cast<const ArrowProjectile*>(this);
			}
			break;
		case FormType::ProjectileGrenade:
			if constexpr (std::is_convertible_v<const GrenadeProjectile*, const T*>) {
				return static_cast<const GrenadeProjectile*>(this);
			}
			break;
		case FormType::ProjectileBeam:
			if constexpr (std::is_convertible_v<const BeamProjectile*, const T*>) {
				return static_cast<const BeamProjectile*>(this);
			}
			break;
		case FormType::ProjectileFlame:
			if constexpr (std::is_convertible_v<const FlameProjectile*, const T*>) {
				return static_cast<const FlameProjectile*>(this);
			}
			break;
		case FormType::ProjectileCone:
			if constexpr (std::is_convertible_v<const ConeProjectile*, const T*>) {
				return static_cast<const ConeProjectile*>(this);
			}
			break;
		case FormType::ProjectileBarrier:
			if constexpr (std::is_convertible_v<const BarrierProjectile*, const T*>) {
				return static_cast<const BarrierProjectile*>(this);
			}
			break;
		case FormType::PlacedHazard:
			if constexpr (std::is_convertible_v<const Hazard*, const T*>) {
				return static_cast<const Hazard*>(this);
			}
			break;
		case FormType::WorldSpace:
			if constexpr (std::is_convertible_v<const TESWorldSpace*, const T*>) {
				return static_cast<const TESWorldSpace*>(this);
			}
			break;
		case FormType::Land:
			if constexpr (std::is_convertible_v<const TESObjectLAND*, const T*>) {
				return static_cast<const TESObjectLAND*>(this);
			}
			break;
		case FormType::NavMesh:
			if constexpr (std::is_convertible_v<const NavMesh*, const T*>) {
				return static_cast<const NavMesh*>(this);
			}
			break;
		case FormType::Dialogue:
			if constexpr (std::is_convertible_v<const TESTopic*, const T*>) {
				return static_cast<const TESTopic*>(this);
			}
			break;
		case FormType::Info:
			if constexpr (std::is_convertible_v<const TESTopicInfo*, const T*>) {
				return static_cast<const TESTopicInfo*>(this);
			}
			break;
		case FormType::Quest:
			if constexpr (std::is_convertible_v<const TESQuest*, const T*>) {
				return static_cast<const TESQuest*>(this);
			}
			break;
		case FormType::Idle:
			if constexpr (std::is_convertible_v<const TESIdleForm*, const T*>) {
				return static_cast<const TESIdleForm*>(this);
			}
			break;
		case FormType::Package:
			if constexpr (std::is_convertible_v<const TESPackage*, const T*>) {
				return static_cast<const TESPackage*>(this);
			}
			break;
		case FormType::CombatStyle:
			if constexpr (std::is_convertible_v<const TESCombatStyle*, const T*>) {
				return static_cast<const TESCombatStyle*>(this);
			}
			break;
		case FormType::LoadScreen:
			if constexpr (std::is_convertible_v<const TESLoadScreen*, const T*>) {
				return static_cast<const TESLoadScreen*>(this);
			}
			break;
		case FormType::LeveledSpell:
			if constexpr (std::is_convertible_v<const TESLevSpell*, const T*>) {
				return static_cast<const TESLevSpell*>(this);
			}
			break;
		case FormType::AnimatedObject:
			if constexpr (std::is_convertible_v<const TESObjectANIO*, const T*>) {
				return static_cast<const TESObjectANIO*>(this);
			}
			break;
		case FormType::Water:
			if constexpr (std::is_convertible_v<const TESWaterForm*, const T*>) {
				return static_cast<const TESWaterForm*>(this);
			}
			break;
		case FormType::EffectShader:
			if constexpr (std::is_convertible_v<const TESEffectShader*, const T*>) {
				return static_cast<const TESEffectShader*>(this);
			}
			break;
		case FormType::Explosion:
			if constexpr (std::is_convertible_v<const BGSExplosion*, const T*>) {
				return static_cast<const BGSExplosion*>(this);
			}
			break;
		case FormType::Debris:
			if constexpr (std::is_convertible_v<const BGSDebris*, const T*>) {
				return static_cast<const BGSDebris*>(this);
			}
			break;
		case FormType::ImageSpace:
			if constexpr (std::is_convertible_v<const TESImageSpace*, const T*>) {
				return static_cast<const TESImageSpace*>(this);
			}
			break;
		case FormType::ImageAdapter:
			if constexpr (std::is_convertible_v<const TESImageSpaceModifier*, const T*>) {
				return static_cast<const TESImageSpaceModifier*>(this);
			}
			break;
		case FormType::FormList:
			if constexpr (std::is_convertible_v<const BGSListForm*, const T*>) {
				return static_cast<const BGSListForm*>(this);
			}
			break;
		case FormType::Perk:
			if constexpr (std::is_convertible_v<const BGSPerk*, const T*>) {
				return static_cast<const BGSPerk*>(this);
			}
			break;
		case FormType::BodyPartData:
			if constexpr (std::is_convertible_v<const BGSBodyPartData*, const T*>) {
				return static_cast<const BGSBodyPartData*>(this);
			}
			break;
		case FormType::AddonNode:
			if constexpr (std::is_convertible_v<const BGSAddonNode*, const T*>) {
				return static_cast<const BGSAddonNode*>(this);
			}
			break;
		case FormType::ActorValueInfo:
			if constexpr (std::is_convertible_v<const ActorValueInfo*, const T*>) {
				return static_cast<const ActorValueInfo*>(this);
			}
			break;
		case FormType::CameraShot:
			if constexpr (std::is_convertible_v<const BGSCameraShot*, const T*>) {
				return static_cast<const BGSCameraShot*>(this);
			}
			break;
		case FormType::CameraPath:
			if constexpr (std::is_convertible_v<const BGSCameraPath*, const T*>) {
				return static_cast<const BGSCameraPath*>(this);
			}
			break;
		case FormType::VoiceType:
			if constexpr (std::is_convertible_v<const BGSVoiceType*, const T*>) {
				return static_cast<const BGSVoiceType*>(this);
			}
			break;
		case FormType::MaterialType:
			if constexpr (std::is_convertible_v<const BGSMaterialType*, const T*>) {
				return static_cast<const BGSMaterialType*>(this);
			}
			break;
		case FormType::Impact:
			if constexpr (std::is_convertible_v<const BGSImpactData*, const T*>) {
				return static_cast<const BGSImpactData*>(this);
			}
			break;
		case FormType::ImpactDataSet:
			if constexpr (std::is_convertible_v<const BGSImpactDataSet*, const T*>) {
				return static_cast<const BGSImpactDataSet*>(this);
			}
			break;
		case FormType::Armature:
			if constexpr (std::is_convertible_v<const TESObjectARMA*, const T*>) {
				return static_cast<const TESObjectARMA*>(this);
			}
			break;
		case FormType::EncounterZone:
			if constexpr (std::is_convertible_v<const BGSEncounterZone*, const T*>) {
				return static_cast<const BGSEncounterZone*>(this);
			}
			break;
		case FormType::Location:
			if constexpr (std::is_convertible_v<const BGSLocation*, const T*>) {
				return static_cast<const BGSLocation*>(this);
			}
			break;
		case FormType::Message:
			if constexpr (std::is_convertible_v<const BGSMessage*, const T*>) {
				return static_cast<const BGSMessage*>(this);
			}
			break;
		case FormType::Ragdoll:
			if constexpr (std::is_convertible_v<const BGSRagdoll*, const T*>) {
				return static_cast<const BGSRagdoll*>(this);
			}
			break;
		case FormType::DefaultObject:
			if constexpr (std::is_convertible_v<const BGSDefaultObjectManager*, const T*>) {
				return static_cast<const BGSDefaultObjectManager*>(this);
			}
			break;
		case FormType::LightingMaster:
			if constexpr (std::is_convertible_v<const BGSLightingTemplate*, const T*>) {
				return static_cast<const BGSLightingTemplate*>(this);
			}
			break;
		case FormType::MusicType:
			if constexpr (std::is_convertible_v<const BGSMusicType*, const T*>) {
				return static_cast<const BGSMusicType*>(this);
			}
			break;
		case FormType::Footstep:
			if constexpr (std::is_convertible_v<const BGSFootstep*, const T*>) {
				return static_cast<const BGSFootstep*>(this);
			}
			break;
		case FormType::FootstepSet:
			if constexpr (std::is_convertible_v<const BGSFootstepSet*, const T*>) {
				return static_cast<const BGSFootstepSet*>(this);
			}
			break;
		case FormType::StoryManagerBranchNode:
			if constexpr (std::is_convertible_v<const BGSStoryManagerBranchNode*, const T*>) {
				return static_cast<const BGSStoryManagerBranchNode*>(this);
			}
			break;
		case FormType::StoryManagerQuestNode:
			if constexpr (std::is_convertible_v<const BGSStoryManagerQuestNode*, const T*>) {
				return static_cast<const BGSStoryManagerQuestNode*>(this);
			}
			break;
		case FormType::StoryManagerEventNode:
			if constexpr (std::is_convertible_v<const BGSStoryManagerEventNode*, const T*>) {
				return static_cast<const BGSStoryManagerEventNode*>(this);
			}
			break;
		case FormType::DialogueBranch:
			if constexpr (std::is_convertible_v<const BGSDialogueBranch*, const T*>) {
				return static_cast<const BGSDialogueBranch*>(this);
			}
			break;
		case FormType::MusicTrack:
			if constexpr (std::is_convertible_v<const BGSMusicTrackFormWrapper*, const T*>) {
				return static_cast<const BGSMusicTrackFormWrapper*>(this);
			}
			break;
		case FormType::WordOfPower:
			if constexpr (std::is_convertible_v<const TESWordOfPower*, const T*>) {
				return static_cast<const TESWordOfPower*>(this);
			}
			break;
		case FormType::Shout:
			if constexpr (std::is_convertible_v<const TESShout*, const T*>) {
				return static_cast<const TESShout*>(this);
			}
			break;
		case FormType::EquipSlot:
			if constexpr (std::is_convertible_v<const BGSEquipSlot*, const T*>) {
				return static_cast<const BGSEquipSlot*>(this);
			}
			break;
		case FormType::Relationship:
			if constexpr (std::is_convertible_v<const BGSRelationship*, const T*>) {
				return static_cast<const BGSRelationship*>(this);
			}
			break;
		case FormType::Scene:
			if constexpr (std::is_convertible_v<const BGSScene*, const T*>) {
				return static_cast<const BGSScene*>(this);
			}
			break;
		case FormType::AssociationType:
			if constexpr (std::is_convertible_v<const BGSAssociationType*, const T*>) {
				return static_cast<const BGSAssociationType*>(this);
			}
			break;
		case FormType::Outfit:
			if constexpr (std::is_convertible_v<const BGSOutfit*, const T*>) {
				return static_cast<const BGSOutfit*>(this);
			}
			break;
		case FormType::ArtObject:
			if constexpr (std::is_convertible_v<const BGSArtObject*, const T*>) {
				return static_cast<const BGSArtObject*>(this);
			}
			break;
		case FormType::MaterialObject:
			if constexpr (std::is_convertible_v<const BGSMaterialObject*, const T*>) {
				return static_cast<const BGSMaterialObject*>(this);
			}
			break;
		case FormType::MovementType:
			if constexpr (std::is_convertible_v<const BGSMovementType*, const T*>) {
				return static_cast<const BGSMovementType*>(this);
			}
			break;
		case FormType::SoundRecord:
			if constexpr (std::is_convertible_v<const BGSSoundDescriptorForm*, const T*>) {
				return static_cast<const BGSSoundDescriptorForm*>(this);
			}
			break;
		case FormType::DualCastData:
			if constexpr (std::is_convertible_v<const BGSDualCastData*, const T*>) {
				return static_cast<const BGSDualCastData*>(this);
			}
			break;
		case FormType::SoundCategory:
			if constexpr (std::is_convertible_v<const BGSSoundCategory*, const T*>) {
				return static_cast<const BGSSoundCategory*>(this);
			}
			break;
		case FormType::SoundOutputModel:
			if constexpr (std::is_convertible_v<const BGSSoundOutput*, const T*>) {
				return static_cast<const BGSSoundOutput*>(this);
			}
			break;
		case FormType::CollisionLayer:
			if constexpr (std::is_convertible_v<const BGSCollisionLayer*, const T*>) {
				return static_cast<const BGSCollisionLayer*>(this);
			}
			break;
		case FormType::ColorForm:
			if constexpr (std::is_convertible_v<const BGSColorForm*, const T*>) {
				return static_cast<const BGSColorForm*>(this);
			}
			break;
		case FormType::ReverbParam:
			if constexpr (std::is_convertible_v<const BGSReverbParameters*, const T*>) {
				return static_cast<const BGSReverbParameters*>(this);
			}
			break;
		case FormType::LensFlare:
			if constexpr (std::is_convertible_v<const BGSLensFlare*, const T*>) {
				return static_cast<const BGSLensFlare*>(this);
			}
			break;
		case FormType::VolumetricLighting:
			if constexpr (std::is_convertible_v<const BGSVolumetricLighting*, const T*>) {
				return static_cast<const BGSVolumetricLighting*>(this);
			}
			break;
		default:
			break;
		}
		return nullptr;
	}
}
