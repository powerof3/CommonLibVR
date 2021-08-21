#include "RE/BSLightingShaderMaterialHairTint.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSLightingShaderMaterialHairTint* BSLightingShaderMaterialHairTint::CreateMaterial()
	{
		auto material = malloc<BSLightingShaderMaterialHairTint>();
		material->ctor();
		return material;
	}


	BSLightingShaderMaterialHairTint* BSLightingShaderMaterialHairTint::ctor()
	{
		using func_t = decltype(&BSLightingShaderMaterialHairTint::ctor);
		REL::Offset<func_t> func(Offset::BSLightingShaderMaterialHairTint::Ctor);
		return func(this);
	}
}