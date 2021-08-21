#include "RE/SkillIncrease.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSTEventSource<SkillIncrease::Event>* SkillIncrease::GetEventSource()
	{
		using func_t = decltype(&SkillIncrease::GetEventSource);
		REL::Offset<func_t> func = 0x069E710;
		return func();
	}
}