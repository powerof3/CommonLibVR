#include "RE/BSGeometry.h"

#include "RE/BSLightingShaderMaterialFacegenTint.h"
#include "RE/BSLightingShaderProperty.h"
#include "RE/NiColor.h"
#include "RE/NiRTTI.h"
#include "RE/NiSkinPartition.h"


namespace RE
{
	bool BSGeometry::HasVertexFlag(NiSkinPartition::Vertex::Flags a_flag) const
	{
		return (NiSkinPartition::GetVertexFlags(vertexDesc) & a_flag) == a_flag;
	}

	
	void BSGeometry::SwitchToFaceTint()
	{
		using Feature = BSShaderMaterial::Feature;
		using Flag = BSShaderProperty::EShaderPropertyFlag8;

		//auto effect = properties[States::kEffect];
		auto lightingShader = lightingShaderProp_cast();
		if (lightingShader) {
			auto material = static_cast<BSLightingShaderMaterialBase*>(lightingShader->material);
			if (material && material->GetFeature() == Feature::kFaceGen) {
				auto facegenTint = BSLightingShaderMaterialFacegenTint::CreateMaterial();
				if (facegenTint) {
					facegenTint->CopyBaseMembers(material);
					lightingShader->SetFlags(Flag::kFace, false);
					lightingShader->SetFlags(Flag::kFaceGenRGBTint, true);
					lightingShader->SetMaterial(facegenTint, true);
					lightingShader->InitializeShader(this);
					facegenTint->~BSLightingShaderMaterialFacegenTint();
					free(facegenTint);
				}
			}
		}
	}
}
