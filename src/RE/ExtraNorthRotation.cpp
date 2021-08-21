#include "RE/ExtraNorthRotation.h"


namespace RE
{
	ExtraNorthRotation::ExtraNorthRotation() :
		BSExtraData(),
		northRot(0.0F),
		pad14(0)
	{
		REL::Offset<std::uintptr_t> vtbl = 0x15A40D0;
		((std::uintptr_t*)this)[0] = vtbl.GetAddress();
	}


	ExtraDataType ExtraNorthRotation::GetType() const
	{
		return ExtraDataType::kNorthRotation;
	}
}
