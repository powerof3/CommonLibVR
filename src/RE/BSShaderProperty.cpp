#include "RE/BSShaderProperty.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"

#include <numeric>


namespace RE
{
	bool BSShaderProperty::InvalidateMaterial()
	{
		using func_t = decltype(&BSShaderProperty::InvalidateMaterial);
		REL::Offset<func_t> func(Offset::BSShaderProperty::InvalidateMaterial);
		return func(this);
	}


	void BSShaderProperty::SetEffectShaderData(const BSTSmartPointer<BSEffectShaderData>& a_data)
	{
		lastRenderPassState = std::numeric_limits<SInt32>::max();
		effectData = a_data;
	}


	void BSShaderProperty::SetMaterial(BSShaderMaterial* a_material, bool a_unk1)
	{
		using func_t = decltype(&BSShaderProperty::SetMaterial);
		REL::Offset<func_t> func(Offset::BSShaderProperty::SetMaterial);
		return func(this, a_material, a_unk1);
	}


	void BSShaderProperty::SetFlags(EShaderPropertyFlag8 a_flag, bool a_toggle)
	{
		using func_t = decltype(&BSShaderProperty::SetFlags);
		REL::Offset<func_t> func(Offset::BSShaderProperty::SetFlags);
		return func(this, a_flag, a_toggle);
	}
}
