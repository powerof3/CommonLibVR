#pragma once

#include "RE/BSTEvent.h"


namespace RE
{
	class Actor;


	struct ActorKill
	{
	public:
		struct Event
		{
		public:
			// members
			Actor* killer;	// 00
			Actor* victim;	// 08
		};
		static_assert(sizeof(Event) == 0x10);


		static BSTEventSource<Event>* GetEventSource();
	};
}