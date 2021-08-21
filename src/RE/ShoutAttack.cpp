#include "RE/ShoutAttack.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSTEventSource<ShoutAttack::Event>* ShoutAttack::GetEventSource()
	{
		using func_t = decltype(&ShoutAttack::GetEventSource);
		REL::Offset<func_t> func = 0x06EE740;
		return func();
	}
}