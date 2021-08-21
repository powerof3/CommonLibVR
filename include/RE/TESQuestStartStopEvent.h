#pragma once


namespace RE
{
	struct TESQuestStartStopEvent
	{
	public:
		// members
		FormID		  formID;	// 00
		bool		  started;	// 04
		UInt8		  unk05;	// 05
		UInt16		  pad06;	// 06
	};
	static_assert(sizeof(TESQuestStartStopEvent) == 0x8);
}