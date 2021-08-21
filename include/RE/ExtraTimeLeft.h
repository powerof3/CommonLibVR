#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraTimeLeft : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraTimeLeft;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kTimeLeft;


		virtual ~ExtraTimeLeft();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kTimeLeft; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return time != a_rhs->time; }


		// members
		float  time;   // 10
		UInt32 pad14;  // 14
	};
	STATIC_ASSERT(sizeof(ExtraTimeLeft) == 0x18);
}
