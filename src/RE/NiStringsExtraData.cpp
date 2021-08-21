#include "RE/NiStringsExtraData.h"

#include "RE/NiTCollection.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	NiStringsExtraData* NiStringsExtraData::Create(const BSFixedString& a_name, const std::vector<BSFixedString>& a_strings)
	{
		REL::Offset<std::uintptr_t> vtbl(RE::Offset::NiStringsExtraData::Vtbl);

		auto data = NiExtraData::Create<NiStringsExtraData>(vtbl.GetAddress());
		if (data) {
			data->name = a_name;

			auto size = a_strings.size();
			data->size = static_cast<UInt32>(size);
			data->value = NiAlloc<char*>(size);

			for (size_t i = 0; i < size; i++) {
				auto string = a_strings[i];
				if (!string.empty()) {
					size_t strLength = string.length() + 1;
					data->value[i] = NiAlloc<char>(strLength);
					std::memcpy(data->value[i], string.c_str(), sizeof(char) * strLength);
				}
			}
		}
		return data;
	}


	std::optional<UInt32> NiStringsExtraData::GetIndex(const BSFixedString& a_element) const
	{
		for (UInt32 i = 0; i < size; i++) {
			if (_strnicmp(a_element.c_str(), value[i], a_element.length()) == 0) {
				return i;
			}
		}
		return std::nullopt;
	}


	bool NiStringsExtraData::Insert(const BSFixedString& a_element)
	{
		if (!a_element.empty() && GetIndex(a_element) == std::nullopt) {
			auto oldData = value;
			value = NiAlloc<char*>(++size);

			if (oldData) {
				for (UInt32 i = 0; i < size - 1; i++) {
					size_t strLength = strlen(oldData[i]) + 1;
					value[i] = NiAlloc<char>(strLength);
					std::memcpy(value[i], oldData[i], sizeof(char) * strLength);

					NiFree(oldData[i]);
				}
				NiFree(oldData);
				oldData = nullptr;
			}

			size_t strLength = a_element.length() + 1;
			value[size - 1] = NiAlloc<char>(strLength);
			std::memcpy(value[size - 1], a_element.data(), sizeof(char) * strLength);

			return true;
		}
		return false;
	}


	bool NiStringsExtraData::Remove(const BSFixedString& a_element)
	{
		if (!a_element.empty()) {
			if (auto index = GetIndex(a_element); index != std::nullopt) {
				auto oldData = value;
				value = NiAlloc<char*>(--size);

				for (UInt32 i = 0; i < size + 1; i++) {
					if (i != index) {
						size_t strLength = strlen(oldData[i]) + 1;
						value[i] = NiAlloc<char>(strLength);
						std::memcpy(value[i], oldData[i], sizeof(char) * strLength);
					}
					NiFree(oldData[i]);
				}
				NiFree(oldData);
				oldData = nullptr;

				return true;
			}
		}
		return false;
	}
}
