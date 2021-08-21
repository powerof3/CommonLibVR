#include "RE/BSLightingShaderMaterial.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSLightingShaderMaterial* BSLightingShaderMaterial::CreateMaterial()
	{
		REL::Offset<std::uintptr_t> vtbl(RE::Offset::BSLightingShaderMaterial::Vtbl);
		size_t size = sizeof(BSLightingShaderMaterial);

		void* memory = malloc(size);
		std::memset(memory, 0, size);
		BSLightingShaderMaterial* material = (BSLightingShaderMaterial*)memory;
		material->ctor();
		((std::uintptr_t*)memory)[0] = vtbl.GetAddress();

		return material;
	}


	BSLightingShaderMaterialBase* BSLightingShaderMaterial::ctor()
	{
		using func_t = decltype(&BSLightingShaderMaterial::ctor);
		REL::Offset<func_t> func(Offset::BSLightingShaderMaterialBase::Ctor);
		return func(this);
	}
}