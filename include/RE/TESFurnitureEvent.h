#pragma once

#include "RE/NiSmartPointer.h"


namespace RE
{
	class TESObjectREFR;


	struct TESFurnitureEvent
	{
	public:
		enum class FurnitureEventType : UInt32
		{
			kEnter = 0,
			kExit = 1
		};


		// members
		NiPointer<TESObjectREFR> actor;			   // 00
		NiPointer<TESObjectREFR> targetFurniture;  // 08
		FurnitureEventType		 type;			   // 10
	};
	static_assert(sizeof(TESFurnitureEvent) == 0x18);
}
