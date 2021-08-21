#include "RE/BSLightingShaderMaterialFacegen.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSLightingShaderMaterialFacegen* BSLightingShaderMaterialFacegen::CreateMaterial()
	{
		auto material = malloc<BSLightingShaderMaterialFacegen>();
		material->ctor();
		return material;
	}


	BSLightingShaderMaterialFacegen* BSLightingShaderMaterialFacegen::ctor()
	{
		using func_t = decltype(&BSLightingShaderMaterialFacegen::ctor);
		REL::Offset<func_t> func(Offset::BSLightingShaderMaterialFacegen::Ctor);
		return func(this);
	}
}