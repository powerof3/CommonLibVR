#pragma once

#include "RE/BSTEvent.h"


namespace RE
{
	class TESObjectREFR;
	class TESObjectWEAP;


	struct CriticalHit
	{
	public:
		struct Event
		{
		public:
			// members
			TESObjectREFR* aggressor;	// 00
			TESObjectWEAP* weapon;		// 08
			bool		   sneakHit;	// 10
			UInt8		   pad11{ 0 };	// 11
			UInt16		   pad12{ 0 };	// 12
			UInt32		   pad14{ 0 };	// 14
		};
		static_assert(sizeof(Event) == 0x18);


		static BSTEventSource<CriticalHit::Event>* GetEventSource();
	};
}