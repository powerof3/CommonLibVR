#include "RE/BSLightingShaderMaterialEye.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSLightingShaderMaterialEye* BSLightingShaderMaterialEye::CreateMaterial()
	{
		auto material = malloc<BSLightingShaderMaterialEye>();
		material->ctor();
		material->eyeCenter[0] = NiPoint3(-2.397175, 7.572490, 3.750610);
		material->eyeCenter[1] = NiPoint3(2.397175, 7.572490, 3.750610);
		return material;
	}


	BSLightingShaderMaterialEye* BSLightingShaderMaterialEye::ctor()
	{
		using func_t = decltype(&BSLightingShaderMaterialEye::ctor);
		REL::Offset<func_t> func(Offset::BSLightingShaderMaterialEye::Ctor);
		return func(this);
	}
}
