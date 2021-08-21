#include "RE/ActorKill.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"

namespace RE
{
	BSTEventSource<ActorKill::Event>* ActorKill::GetEventSource()
	{
		using func_t = decltype(&ActorKill::GetEventSource);
		REL::Offset<func_t> func = 0x0625470;
		return func();
	}
}