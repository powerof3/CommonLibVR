#include "RE/LocationDiscovery.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSTEventSource<LocationDiscovery::Event>* LocationDiscovery::GetEventSource()
	{
		using func_t = decltype(&LocationDiscovery::GetEventSource);
		REL::Offset<func_t> func = 0x06EE380;
		return func();
	}
}
