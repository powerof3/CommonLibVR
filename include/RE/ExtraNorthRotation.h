#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraNorthRotation : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraNorthRotation;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kNorthRotation;


		ExtraNorthRotation();
		virtual ~ExtraNorthRotation() = default;  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kNorthRotation; }


		// members
		float  northRot;  // 10
		UInt32 pad14;	  // 14
	};
	STATIC_ASSERT(sizeof(ExtraNorthRotation) == 0x18);
}
