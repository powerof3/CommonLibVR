#include "RE/DisarmedEvent.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSTEventSource<DisarmedEvent::Event>* DisarmedEvent::GetEventSource()
	{
		using func_t = decltype(&DisarmedEvent::GetEventSource);
		REL::Offset<func_t> func = 0x0625650;
		return func();
	}
}