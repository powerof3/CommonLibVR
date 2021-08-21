#pragma once

#include <cstdarg>

#include "RE/GFxLogBase.h"
#include "RE/GFxState.h"


namespace RE
{
	class GFxLog :
		public GFxState,		   // 00
		public GFxLogBase<GFxLog>  // 18
	{
	public:
		inline static constexpr auto RTTI = RTTI_GFxLog;


		GFxLog();
		virtual ~GFxLog() = default;  // 00

		// add
		virtual void LogMessageVarg(LogMessageType a_messageType, const char* a_fmt, va_list a_argList);  // 01

		void LogMessageByType(LogMessageType a_messageType, const char* a_fmt, ...);
	};
	STATIC_ASSERT(sizeof(GFxLog) == 0x20);
}
