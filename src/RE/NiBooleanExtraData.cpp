#include "RE/NiBooleanExtraData.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	NiBooleanExtraData* NiBooleanExtraData::Create(const BSFixedString& a_name, bool a_value)
	{
		REL::Offset<std::uintptr_t> vtbl(RE::Offset::NiBooleanExtraData::Vtbl);

		auto data = NiExtraData::Create<NiBooleanExtraData>(vtbl.GetAddress());
		if (data) {
			data->name = a_name;
			data->data = a_value;
		}

		return data;
	}
}