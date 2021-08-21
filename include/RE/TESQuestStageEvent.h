#pragma once


namespace RE
{
	struct TESQuestStageEvent
	{
	public:
		// members
		void*		  finishedCallback;	 // 00
		FormID		  formID;			 // 08
		UInt16		  stage;			 // 0C
		UInt8		  unk0E;			 // 0E
		UInt8		  pad0F;			 // 0F
	};
	static_assert(sizeof(TESQuestStageEvent) == 0x10);
}
