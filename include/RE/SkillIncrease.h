#pragma once

#include "RE/ActorValues.h"
#include "RE/BSTEvent.h"


namespace RE
{
	class PlayerCharacter;


	struct SkillIncrease
	{
	public:
		struct Event
		{
		public:
			// members
			PlayerCharacter* player;	  // 00
			ActorValue		 actorValue;  // 08
			UInt32			 pad0C;		  // 0C
		};
		static_assert(sizeof(Event) == 0x10);


		static BSTEventSource<Event>* GetEventSource();
	};
}