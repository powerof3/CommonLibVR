#pragma once


namespace RE
{
	class BGSLocation;
	class TESObjectREFR;


	struct TESActorLocationChangeEvent
	{
	public:
		// members
		TESObjectREFR* actor;
		BGSLocation*   oldLoc;
		BGSLocation*   newLoc;
	};
	static_assert(sizeof(TESActorLocationChangeEvent) == 0x18);
}