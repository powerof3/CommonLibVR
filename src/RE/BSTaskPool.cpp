#include "RE/BSTaskPool.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSTaskPool* BSTaskPool::GetSingleton()
	{
		REL::Offset<BSTaskPool**> singleton(Offset::BSTaskPool::Singleton);
		return *singleton;
	}

	bool BSTaskPool::ShouldUseTaskPool()
	{
		using func_t = decltype(&BSTaskPool::ShouldUseTaskPool);
		REL::Offset<func_t> func(Offset::BSTaskPool::ShouldUseTaskPool);
		return func();
	}


	UInt32 BSTaskPool::QueueBulletWaterDisplacementTask(float a_scale, const RE::NiPoint3& a_pos)
	{
		using func_t = decltype(&BSTaskPool::QueueBulletWaterDisplacementTask);
		REL::Offset<func_t> func(Offset::BSTaskPool::QueueBulletWaterDisplacementTask);
		return func(this, a_scale, a_pos);
	}
}