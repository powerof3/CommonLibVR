#include "RE/NiIntegerExtraData.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	NiIntegerExtraData* NiIntegerExtraData::Create(const BSFixedString& a_name, SInt32 a_value)
	{
		REL::Offset<std::uintptr_t> vtbl(RE::Offset::NiIntegerExtraData::Vtbl);

		auto data = NiExtraData::Create<NiIntegerExtraData>(vtbl.GetAddress());
		if (data) {
			data->name = a_name;
			data->value = a_value;
		}

		return data;
	}
}