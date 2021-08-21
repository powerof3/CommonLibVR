#pragma once

#include "RE/hkpShape.h"


namespace RE
{
	class hkpCdBody
	{
	public:
		const hkpShape* GetShape() const;


		// members
		const hkpShape*	 shape;		// 00
		hkpShapeKey		 shapeKey;	// 08
		UInt32			 pad0C;		// 0C
		const void*		 motion;	// 10
		const hkpCdBody* parent;	// 18
	};
	STATIC_ASSERT(sizeof(hkpCdBody) == 0x20);
}
