#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraRadius : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraRadius;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kRadius;


		virtual ~ExtraRadius();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kRadius; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return radius != a_rhs->radius; }


		// members
		float  radius;	// 10
		UInt32 pad14;	// 14
	};
	STATIC_ASSERT(sizeof(ExtraRadius) == 0x18);
}
