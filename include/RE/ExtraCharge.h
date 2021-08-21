#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraCharge : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraCharge;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kCharge;


		ExtraCharge();
		virtual ~ExtraCharge() = default;  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kCharge; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return charge != a_rhs->charge; }


		// members
		float  charge;	// 10
		UInt32 pad14;	// 14
	};
	STATIC_ASSERT(sizeof(ExtraCharge) == 0x18);
}
