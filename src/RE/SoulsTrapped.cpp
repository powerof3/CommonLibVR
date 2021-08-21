#include "RE/SoulsTrapped.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSTEventSource<SoulsTrapped::Event>* SoulsTrapped::GetEventSource()
	{
		using func_t = decltype(&SoulsTrapped::GetEventSource);
		REL::Offset<func_t> func = 0x063FC50;
		return func();
	}
	
	
	void SoulsTrapped::SendEvent(Actor* a_trapper, Actor* a_target)
	{
		Event e = { a_trapper, a_target };
		auto source = GetEventSource();
		if (source) {
			source->SendEvent(std::addressof(e));
		}
	}
}
