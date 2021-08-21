#include "RE/BSLightingShaderMaterialSnow.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSLightingShaderMaterialSnow* BSLightingShaderMaterialSnow::CreateMaterial()
	{
		auto material = malloc<BSLightingShaderMaterialSnow>();
		material->ctor();
		return material;
	}


	BSLightingShaderMaterialSnow* BSLightingShaderMaterialSnow::ctor()
	{
		using func_t = decltype(&BSLightingShaderMaterialSnow::ctor);
		REL::Offset<func_t> func(Offset::BSLightingShaderMaterialSnow::Ctor);
		return func(this);
	}
}