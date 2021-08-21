#include "RE/BGSRefAlias.h"

#include "RE/TESQuest.h"
#include "RE/Actor.h"


namespace RE
{
	TESObjectREFR* BGSRefAlias::GetReference()
	{
		TESObjectREFR* ref = nullptr;
		ObjectRefHandle handle;

		auto owner = owningQuest;
		if (owner) {
			owner->CreateRefHandleByAliasID(handle, aliasID);

			auto refPtr = handle.get();
			ref = refPtr.get();
		}

		return ref;
	}


	Actor* BGSRefAlias::GetActorReference()
	{
		auto ref = GetReference();
		return ref ? ref->As<Actor>() : nullptr;
	}
}
