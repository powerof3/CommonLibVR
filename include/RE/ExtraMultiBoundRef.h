#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"
#include "RE/FormTypes.h"


namespace RE
{
	class ExtraMultiBoundRef : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraMultiBoundRef;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kMultiBoundRef;


		virtual ~ExtraMultiBoundRef();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kMultiBoundRef; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return boundRef != a_rhs->boundRef; }

		// members
		TESObjectREFR* boundRef;  // 10
	};
	STATIC_ASSERT(sizeof(ExtraMultiBoundRef) == 0x18);
}
