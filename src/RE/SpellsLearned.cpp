#include "RE/SpellsLearned.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSTEventSource<SpellsLearned::Event>* SpellsLearned::GetEventSource()
	{
		using func_t = decltype(&SpellsLearned::GetEventSource);
		REL::Offset<func_t> func = 0x063FD40;
		return func();
	}


	void SpellsLearned::SendEvent(SpellItem* a_spell)
	{
		Event e = { a_spell };
		auto source = GetEventSource();
		if (source) {
			source->SendEvent(std::addressof(e));
		}
	}
}