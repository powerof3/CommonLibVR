#pragma once

#include "RE/ActorValues.h"


namespace RE
{
	class ActorValueInfo;


	class ActorValueList
	{
	public:
		static ActorValueList* GetSingleton();

		ActorValueInfo* GetActorValue(ActorValue a_actorValue);


		// members
		UInt32			unk00;											 // 00
		UInt32			pad04;											 // 04
		ActorValueInfo* actorValues[to_underlying(ActorValue::kTotal)];	 // 08
	};
}
