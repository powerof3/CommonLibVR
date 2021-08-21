#include "RE/BSLightingShaderProperty.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"

#include <numeric>


namespace RE
{
	void BSLightingShaderProperty::CopyMembers(BSLightingShaderProperty* a_other)
	{
		flags = a_other->flags;
		alpha = a_other->alpha;
		lastRenderPassState = std::numeric_limits<SInt32>::max();
		if ((a_other->flags & EShaderPropertyFlag::kOwnEmit) == EShaderPropertyFlag::kOwnEmit) {
			emissiveColor->red = a_other->emissiveColor->red;
			emissiveColor->green = a_other->emissiveColor->green;
			emissiveColor->blue = a_other->emissiveColor->blue;
		} else {
			if ((flags & EShaderPropertyFlag::kOwnEmit) == EShaderPropertyFlag::kOwnEmit) {
				free(emissiveColor);
			}
			emissiveColor = a_other->emissiveColor;
			SetFlags(EShaderPropertyFlag8::kOwnEmit, false);
		}
		projectedUVParams = a_other->projectedUVParams;
		projectedUVColor = a_other->projectedUVColor;
		emissiveMult = a_other->emissiveMult;
	}


	void BSLightingShaderProperty::InvalidateTextures(UInt32 unk1)
	{
		using func_t = decltype(&BSLightingShaderProperty::InvalidateTextures);
		REL::Offset<func_t> func(Offset::BSLightingShaderProperty::InvalidateTextures);
		return func(this, unk1);
	}
}