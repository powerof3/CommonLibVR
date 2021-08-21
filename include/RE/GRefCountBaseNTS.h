#pragma once

#include "RE/GRefCountBaseStatImpl.h"
#include "RE/GRefCountNTSImpl.h"


namespace RE
{
	template <class C, UInt32 Stat>
	class GRefCountBaseNTS : public GRefCountBaseStatImpl<GRefCountNTSImpl, Stat>
	{
	public:
		enum
		{
			kStatType = Stat
		};


		GRefCountBaseNTS() = default;
	};
}
