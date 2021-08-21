#include "RE/DragonSoulsGained.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"

namespace RE
{
	BSTEventSource<DragonSoulsGained::Event>* DragonSoulsGained::GetEventSource()
	{
		using func_t = decltype(&DragonSoulsGained::GetEventSource);
		REL::Offset<func_t> func = 0x062C3C0;
		return func();
	}
}