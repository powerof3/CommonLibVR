#include "RE/BSLightingShaderMaterialEnvmap.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSLightingShaderMaterialEnvmap* BSLightingShaderMaterialEnvmap::CreateMaterial()
	{
		auto material = malloc<BSLightingShaderMaterialEnvmap>();
		material->ctor();
		return material;
	}


	BSLightingShaderMaterialEnvmap* BSLightingShaderMaterialEnvmap::ctor()
	{
		using func_t = decltype(&BSLightingShaderMaterialEnvmap::ctor);
		REL::Offset<func_t> func(Offset::BSLightingShaderMaterialEnvmap::Ctor);
		return func(this);
	}
}
