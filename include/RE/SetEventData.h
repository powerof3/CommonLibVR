#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSTArray.h"


namespace RE
{
	struct SetEventData
	{
	public:
		// members
		BSFixedString				  eventName;  // 00
		BSTSmallArray<BSFixedString>* clipNames;  // 08
		bool						  unk10;	  // 10
		UInt8						  pad11;	  // 11
		UInt16						  pad12;	  // 12
		UInt32						  pad14;	  // 14
	};
	STATIC_ASSERT(sizeof(SetEventData) == 0x18);
}
