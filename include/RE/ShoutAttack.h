#pragma once

#include "RE/BSTEvent.h"


namespace RE
{
	class TESShout;


	struct ShoutAttack
	{
	public:
		struct Event
		{
		public:
			// members
			TESShout* shout;  // 00
		};
		static_assert(sizeof(Event) == 0x08);


		static BSTEventSource<Event>* GetEventSource();
	};
}
