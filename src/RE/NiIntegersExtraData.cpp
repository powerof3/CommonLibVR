#include "RE/NiIntegersExtraData.h"

#include "RE/NiTCollection.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	NiIntegersExtraData* NiIntegersExtraData::Create(const BSFixedString& a_name, const std::vector<SInt32>& a_integers)
	{
		REL::Offset<std::uintptr_t> vtbl(RE::Offset::NiIntegersExtraData::Vtbl);

		auto data = NiExtraData::Create<NiIntegersExtraData>(vtbl.GetAddress());
		if (data) {
			data->name = a_name.c_str();
			data->size = static_cast<UInt32>(a_integers.size());

			data->value = NiAlloc<SInt32>(a_integers.size());
			memcpy(data->value, a_integers.data(), a_integers.size() * sizeof(SInt32));
		}

		return data;
	}


	SInt32 NiIntegersExtraData::GetIndexOf(SInt32 a_element) const
	{
		for (UInt32 i = 0; i < size; i++) {
			if (value[i] == a_element) {
				return i;
			}
		}

		return -1;
	}


	bool NiIntegersExtraData::InsertElement(SInt32 a_element)
	{
		auto index = GetIndexOf(a_element);

		if (index == -1) {
			auto temp = NiAlloc<SInt32>(++size);

			for (SInt32 i = 0; i < size - 1; i++) {
				temp[i] = value[i];
			}
			temp[size - 1] = a_element;
			NiFree(value);
			value = temp;

			return true;
		}

		return false;
	}


	bool NiIntegersExtraData::RemoveElement(SInt32 a_element)
	{
		auto index = GetIndexOf(a_element);

		if (index != -1) {
			auto temp = NiAlloc<SInt32>(--size);

			for (SInt32 i = 0; i < size + 1; i++) {
				if (i != index) {
					temp[i] = value[i];
				}
			}
			NiFree(value);
			value = temp;

			return true;
		}

		return false;
	}
}