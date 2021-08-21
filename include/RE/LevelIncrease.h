#pragma once

#include "RE/BSTEvent.h"


namespace RE
{
	class PlayerCharacter;


	struct LevelIncrease
	{
	public:
		struct Event
		{
		public:
			// members
			PlayerCharacter* player;	// 00
			UInt16			 newLevel;	// 08
			UInt16			 pad0A;		// 0A
			UInt32			 pad0C;		// 0C
		};
		static_assert(sizeof(Event) == 0x10);


		static BSTEventSource<Event>* GetEventSource();
	};
}