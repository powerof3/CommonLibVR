#include "RE/ItemHarvested.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSTEventSource<TESHarvestedEvent::ItemHarvested>* TESHarvestedEvent::GetEventSource()
	{
		using func_t = decltype(&TESHarvestedEvent::GetEventSource);
		REL::Offset<func_t> func = 0x01AD250;
		return func();
	}
}