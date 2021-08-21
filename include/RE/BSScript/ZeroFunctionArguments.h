#pragma once

#include "RE/BSScript/IFunctionArguments.h"


namespace RE
{
	namespace BSScript
	{
		class ZeroFunctionArguments : public IFunctionArguments
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSScript__ZeroFunctionArguments;


			// override (IFunctionArguments)
			virtual bool operator()(BSScrapArray<Variable>& a_dst) const override;	// 01
		};
		STATIC_ASSERT(sizeof(ZeroFunctionArguments) == 0x8);
	}
}
