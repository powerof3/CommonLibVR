#pragma once

#include "RE/BSTempEffect.h"
#include "RE/BSTempEffectDebris.h"
#include "RE/BSTempEffectGeometryDecal.h"
#include "RE/BSTempEffectParticle.h"
#include "RE/BSTempEffectSPG.h"
#include "RE/BSTempEffectSimpleDecal.h"
#include "RE/BSTempEffectWeaponBlood.h"
#include "RE/ModelReferenceEffect.h"
#include "RE/ReferenceEffect.h"
#include "RE/ShaderReferenceEffect.h"
#include "RE/SummonPlacementEffect.h"


namespace RE
{
	template <
		class T,
		std::enable_if_t<
			BSTempEffect_Impl::is_valid_as_expr_v<T>,
			int>>
	constexpr T* BSTempEffect::As() noexcept
	{
		return const_cast<T*>(
			static_cast<const BSTempEffect*>(this)->As<T>());
	}


	template <
		class T,
		std::enable_if_t<
			BSTempEffect_Impl::is_valid_as_expr_v<T>,
			int>>
	constexpr const T* BSTempEffect::As() const noexcept
	{
		switch (GetType()) {
		case TEMP_EFFECT_TYPE::kTerrain:
			if constexpr (std::is_convertible_v<const BSTempEffect*, const T*>) {
				return static_cast<const BSTempEffect*>(this);
			}
			break;
		case TEMP_EFFECT_TYPE::kWeaponBlood:
			if constexpr (std::is_convertible_v<const BSTempEffectWeaponBlood*, const T*>) {
				return static_cast<const BSTempEffectWeaponBlood*>(this);
			}
			break;
		case TEMP_EFFECT_TYPE::kDecal:
			if constexpr (std::is_convertible_v<const BSTempEffectSimpleDecal*, const T*>) {
				return static_cast<const BSTempEffectSimpleDecal*>(this);
			}
			break;
		case TEMP_EFFECT_TYPE::kGeometryDecal:
			if constexpr (std::is_convertible_v<const BSTempEffectGeometryDecal*, const T*>) {
				return static_cast<const BSTempEffectGeometryDecal*>(this);
			}
			break;
		case TEMP_EFFECT_TYPE::kParticle:
			if constexpr (std::is_convertible_v<const BSTempEffectParticle*, const T*>) {
				return static_cast<const BSTempEffectParticle*>(this);
			}
			break;
		case TEMP_EFFECT_TYPE::kDebris:
			if constexpr (std::is_convertible_v<const BSTempEffectDebris*, const T*>) {
				return static_cast<const BSTempEffectDebris*>(this);
			}
			break;
		case TEMP_EFFECT_TYPE::kSPG:
			if constexpr (std::is_convertible_v<const BSTempEffectSPG*, const T*>) {
				return static_cast<const BSTempEffectSPG*>(this);
			}
			break;
		case TEMP_EFFECT_TYPE::kDefault:
			if constexpr (std::is_convertible_v<const BSTempEffect*, const T*>) {
				return static_cast<const BSTempEffect*>(this);
			}
			break;
		case TEMP_EFFECT_TYPE::kRefDefault:
			if constexpr (std::is_convertible_v<const ReferenceEffect*, const T*>) {
				return static_cast<const ReferenceEffect*>(this);
			}
			break;
		case TEMP_EFFECT_TYPE::kRefModel:
			if constexpr (std::is_convertible_v<const ModelReferenceEffect*, const T*>) {
				return static_cast<const ModelReferenceEffect*>(this);
			}
			break;
		case TEMP_EFFECT_TYPE::kRefShader:
			if constexpr (std::is_convertible_v<const ShaderReferenceEffect*, const T*>) {
				return static_cast<const ShaderReferenceEffect*>(this);
			}
			break;
		case TEMP_EFFECT_TYPE::kMagicSummon:
			if constexpr (std::is_convertible_v<const SummonPlacementEffect*, const T*>) {
				return static_cast<const SummonPlacementEffect*>(this);
			}
			break;
		}
		return nullptr;
	}
}
