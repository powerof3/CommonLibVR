#pragma once

#include "RE/IUIMessageData.h"


namespace RE
{
	class GFxEvent;


	class BSUIScaleformData : public IUIMessageData
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSUIScaleformData;


		virtual ~BSUIScaleformData();  // 00


		// members
		GFxEvent* scaleformEvent;  // 10
	};
	STATIC_ASSERT(sizeof(BSUIScaleformData) == 0x18);
}
