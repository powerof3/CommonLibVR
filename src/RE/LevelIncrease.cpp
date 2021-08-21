#include "RE/LevelIncrease.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSTEventSource<LevelIncrease::Event>* LevelIncrease::GetEventSource()
	{
		using func_t = decltype(&LevelIncrease::GetEventSource);
		REL::Offset<func_t> func = 0x069E620;
		return func();
	}
}