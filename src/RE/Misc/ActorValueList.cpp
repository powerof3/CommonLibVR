#include "RE/ActorValueList.h"

#include "RE/Offsets.h"
#include "RE/ActorValueInfo.h"


namespace RE
{
	ActorValueList* ActorValueList::GetSingleton()
	{
		REL::Offset<ActorValueList**> singleton(Offset::ActorValueList::Singleton);
		return *singleton;
	}


	ActorValueInfo* ActorValueList::GetActorValue(ActorValue a_actorValue)
	{
		return actorValues && (a_actorValue < ActorValue::kTotal) ? actorValues[to_underlying(a_actorValue)] : nullptr;
	}
}