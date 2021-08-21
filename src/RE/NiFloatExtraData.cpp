#include "RE/NiFloatExtraData.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	NiFloatExtraData* NiFloatExtraData::Create(const BSFixedString& a_name, float a_value)
	{
		REL::Offset<std::uintptr_t> vtbl(RE::Offset::NiFloatExtraData::Vtbl);

		auto data = NiExtraData::Create<NiFloatExtraData>(vtbl.GetAddress());
		if (data) {
			data->name = a_name;
			data->data = a_value;
		}

		return data;
	}
}