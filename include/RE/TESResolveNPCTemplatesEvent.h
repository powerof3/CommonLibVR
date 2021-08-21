#pragma once

namespace RE
{
	struct TESResolveNPCTemplatesEvent
	{
	public:
		// members
		FormID templateID;	// 00
		UInt32 pad04;		// 04
	};
	static_assert(sizeof(TESResolveNPCTemplatesEvent) == 0x8);
}