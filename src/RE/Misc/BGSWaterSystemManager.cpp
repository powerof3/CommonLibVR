#include "RE/BGSWaterSystemManager.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BGSWaterSystemManager* BGSWaterSystemManager::GetSingleton()
	{
		REL::Offset<BGSWaterSystemManager**> singleton(Offset::BGSWaterSystemManager::Singleton);
		return *singleton;
	}

	void BGSWaterSystemManager::CreateBulletWaterDisplacement(const RE::NiPoint3& a_pos, float a_scale)
	{
		using func_t = decltype(&BGSWaterSystemManager::CreateBulletWaterDisplacement);
		REL::Offset<func_t> func(Offset::BGSWaterSystemManager::CreateBulletWaterDisplacement);
		return func(this, a_pos, a_scale);
	}
}