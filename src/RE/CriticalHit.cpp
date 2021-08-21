#include "RE/CriticalHit.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSTEventSource<CriticalHit::Event>* CriticalHit::GetEventSource()
	{
		using func_t = decltype(&CriticalHit::GetEventSource);
		REL::Offset<func_t> func = 0x0635F20;
		return func();
	}
}
