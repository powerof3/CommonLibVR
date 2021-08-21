#pragma once

#include "RE/BSTEvent.h"


namespace RE
{
	struct DragonSoulsGained
	{
	public:
		struct Event
		{
		public:
			// members
			float  souls;  // 00
			UInt32 pad04;  // 04
		};
		static_assert(sizeof(Event) == 0x08);


		static BSTEventSource<Event>* GetEventSource();
	};
}
