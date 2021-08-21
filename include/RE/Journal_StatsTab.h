#pragma once

#include "RE/JournalTab.h"


namespace RE
{
	class Journal_StatsTab : public JournalTab
	{
	public:
		inline static constexpr auto RTTI = RTTI_Journal_StatsTab;


		virtual ~Journal_StatsTab();  // 00

		// override (JournalTab)
		virtual void Accept(CallbackProcessor* a_cbReg) override;  // 01
	};
	STATIC_ASSERT(sizeof(Journal_StatsTab) == 0x18);
}
