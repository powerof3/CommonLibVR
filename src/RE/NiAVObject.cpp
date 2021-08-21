#include "RE/NiAVObject.h"

#include <functional>

#include "RE/BSEffectShaderData.h"
#include "RE/BSGeometry.h"
#include "RE/BSGraphics/State.h"
#include "RE/BSLightingShaderMaterialFacegenTint.h"
#include "RE/BSLightingShaderMaterialHairTint.h"
#include "RE/BSLightingShaderProperty.h"
#include "RE/BSShaderMaterial.h"
#include "RE/BSShaderProperty.h"
#include "RE/BSTSmartPointer.h"
#include "RE/BSVisit.h"
#include "RE/NiColor.h"
#include "RE/NiNode.h"
#include "RE/NiProperty.h"
#include "RE/NiRTTI.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	bool NiAVObject::GetAppCulled() const
	{
		return (flagsVR & Flag::kHidden) != Flag::kNone;
	}


	BSGeometry* NiAVObject::GetFirstGeometryOfShaderType(BSShaderMaterial::Feature a_type)
	{
		BSGeometry* firstGeometry = nullptr;

		BSVisit::TraverseScenegraphGeometries(this, [&](BSGeometry* a_geometry) -> BSVisit::BSVisitControl {
			if (a_type == BSShaderMaterial::Feature::kNone) {
				firstGeometry = a_geometry;
				return BSVisit::BSVisitControl::kStop;
			}

			//auto effect = a_geometry->properties[BSGeometry::States::kEffect];
			auto lightingShader = a_geometry->lightingShaderProp_cast();
			if (lightingShader) {
				const auto material = lightingShader->material;
				if (material && material->GetFeature() == a_type) {
					firstGeometry = a_geometry;
					return BSVisit::BSVisitControl::kStop;
				}
			}

			return BSVisit::BSVisitControl::kContinue;
		});

		return firstGeometry;
	}


	TESObjectREFR* NiAVObject::GetUserData() const
	{
		if (userData) {
			return userData;
		}

		if (parent) {
			return parent->GetUserData();
		}

		return nullptr;
	}


	bool NiAVObject::HasShaderType(BSShaderMaterial::Feature a_type)
	{
		bool hasShaderType = false;

		BSVisit::TraverseScenegraphGeometries(this, [&](BSGeometry* a_geometry) -> BSVisit::BSVisitControl {
			//auto effect = a_geometry->properties[BSGeometry::States::kEffect];
			auto lightingShader = a_geometry->lightingShaderProp_cast();
			if (lightingShader) {
				auto material = lightingShader->material;
				if (material && material->GetFeature() == a_type) {
					hasShaderType = true;
					return BSVisit::BSVisitControl::kStop;
				}
			}
			return BSVisit::BSVisitControl::kContinue;
		});

		return hasShaderType;
	}


	void NiAVObject::SetAppCulled(bool a_cull)
	{
		a_cull ? flagsVR |= Flag::kHidden : flagsVR &= ~Flag::kHidden;
	}


	bool NiAVObject::SetMotionType(UInt32 a_motionType, bool a_arg2, bool a_arg3, bool a_allowActivate)
	{
		using func_t = decltype(&NiAVObject::SetMotionType);
		REL::Offset<func_t> func(Offset::NiAVObject::SetMotionType);
		return func(this, a_motionType, a_arg2, a_arg3, a_allowActivate);
	}


	void NiAVObject::SetRigidConstraints(bool a_enable, UInt8 a_arg2, UInt32 a_arg3)
	{
		using func_t = decltype(&NiAVObject::SetRigidConstraints);
		REL::Offset<func_t> func = 0xE09CA0;
		return func(this, a_enable, a_arg2, a_arg3);
	}


	void NiAVObject::TintScenegraph(const NiColorA& a_color)
	{
		auto gState = RE::BSGraphics::State::GetSingleton();
		BSTSmartPointer<BSEffectShaderData> newShaderData(new RE::BSEffectShaderData());
		newShaderData->fillColor = a_color;
		newShaderData->baseTexture = gState->defaultTextureWhite;

		BSVisit::TraverseScenegraphGeometries(this, [&](BSGeometry* a_geometry) -> BSVisit::BSVisitControl {
			auto effect = a_geometry->properties[BSGeometry::States::kEffect];
			auto shaderProp = netimmerse_cast<BSShaderProperty*>(effect.get());
			if (shaderProp && shaderProp->AcceptsEffectData()) {
				auto shaderData = shaderProp->effectData;
				if (!shaderData || shaderData->baseTexture == gState->defaultTextureWhite) {
					shaderProp->SetEffectShaderData(newShaderData);
				}
			}

			return BSVisit::BSVisitControl::kContinue;
		});
	}


	void NiAVObject::Update(NiUpdateData& a_data)
	{
		using func_t = decltype(&NiAVObject::Update);
		REL::Offset<func_t> func(Offset::NiAVObject::Update);
		return func(this, a_data);
	}


	void NiAVObject::UpdateBodyTint(const NiColor& a_color)
	{
		BSVisit::TraverseScenegraphGeometries(this, [&](BSGeometry* a_geometry) -> BSVisit::BSVisitControl {
			using State = BSGeometry::States;
			using Feature = BSShaderMaterial::Feature;

			//auto effect = a_geometry->properties[State::kEffect].get();
			//if (effect) {
				auto lightingShader = a_geometry->lightingShaderProp_cast();
				if (lightingShader) {
					auto material = lightingShader->material;
					if (material && material->GetFeature() == Feature::kFaceGenRGBTint) {
						auto facegenTint = static_cast<BSLightingShaderMaterialFacegenTint*>(material);
						facegenTint->tintColor = a_color;
					}
				}
			//}

			return BSVisit::BSVisitControl::kContinue;
		});
	}


	void NiAVObject::UpdateHairColor(const NiColor& a_color)
	{
		BSVisit::TraverseScenegraphGeometries(this, [&](BSGeometry* a_geometry) -> BSVisit::BSVisitControl {
			using State = BSGeometry::States;
			using Feature = BSShaderMaterial::Feature;

			//auto effect = a_geometry->properties[State::kEffect].get();
			//if (effect) {
				auto lightingShader = a_geometry->lightingShaderProp_cast();
				if (lightingShader) {
					auto material = lightingShader->material;
					if (material && material->GetFeature() == Feature::kHairTint) {
						auto hairTint = static_cast<BSLightingShaderMaterialHairTint*>(material);
						hairTint->tintColor = a_color;
					}
				}
			//}

			return BSVisit::BSVisitControl::kContinue;
		});
	}


	void NiAVObject::UpdateMaterialAlpha(float a_alpha, bool a_onlySkin)
	{
		BSVisit::TraverseScenegraphGeometries(this, [&](BSGeometry* a_geometry) -> BSVisit::BSVisitControl {
			using Feature = BSShaderMaterial::Feature;

			//auto effect = a_geometry->properties[BSGeometry::States::kEffect].get();
			//if (effect) {
				auto lightingShader = a_geometry->lightingShaderProp_cast();
				if (lightingShader) {
					auto material = static_cast<BSLightingShaderMaterialBase*>(lightingShader->material);
					if (material) {
						if (a_onlySkin) {
							auto const feature = material->GetFeature();
							if (feature != Feature::kFaceGen && feature != Feature::kFaceGenRGBTint) {
								return BSVisit::BSVisitControl::kContinue;
							}
						}
						material->materialAlpha = a_alpha;
					}
				}
			//}

			return BSVisit::BSVisitControl::kContinue;
		});
	}


	void NiAVObject::ToggleNode(bool a_hide)
	{
		BSVisit::TraverseScenegraphObjects(this, [&](NiAVObject* a_object) -> BSVisit::BSVisitControl {
			a_object->SetAppCulled(a_hide);

			return BSVisit::BSVisitControl::kContinue;
		});
	}


	void NiAVObject::UpdateRigidBodySettings(UInt32 a_type, UInt32 a_arg2)
	{
		using func_t = decltype(&NiAVObject::UpdateRigidBodySettings);
		REL::Offset<func_t> func = 0xE03370;
		return func(this, a_type, a_arg2);
	}


	BSLightingShaderProperty* NiAVObject::temp_nicast(BSGeometry* a_geometry)
	{
		if (auto effect = a_geometry->properties[BSGeometry::States::kEffect].get(); effect) {
			if (auto rtti = effect->GetRTTI(); rtti) {
				const std::string name(rtti->GetName());
				if (name == "BSLightingShaderProperty") {
					return static_cast<RE::BSLightingShaderProperty*>(effect);
				}
			}
		}
		return nullptr;
	}
}
