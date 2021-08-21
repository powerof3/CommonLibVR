#pragma once

#include "RE/NiPoint3.h"


namespace RE
{
	class BSTaskPool
	{
	public:
		static BSTaskPool* GetSingleton();

		static bool ShouldUseTaskPool();

		UInt32 QueueBulletWaterDisplacementTask(float a_scale, const RE::NiPoint3& a_pos);  // 45
	};
};
