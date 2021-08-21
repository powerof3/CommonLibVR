#include "RE/BooksRead.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"

namespace RE
{
	BSTEventSource<BooksRead::Event>* BooksRead::GetEventSource()
	{
		using func_t = decltype(&BooksRead::GetEventSource);
		REL::Offset<func_t> func = 0x023BC10;
		return func();
	}
}