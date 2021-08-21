#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class BGSMessage;


	class ExtraTeleportName : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraTeleportName;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kTeleportName;


		virtual ~ExtraTeleportName();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kTeleportName; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return message != a_rhs->message; }


		// members
		BGSMessage* message;  // 10
	};
	STATIC_ASSERT(sizeof(ExtraTeleportName) == 0x18);
}
