#include "RE/BGSSaveLoadManager.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BGSSaveLoadManager* BGSSaveLoadManager::GetSingleton()
	{
		REL::Offset<BGSSaveLoadManager**> singleton(Offset::BGSSaveLoadManager::Singleton);
		return *singleton;
	}


	void BGSSaveLoadManager::Save(const char* a_fileName)
	{
		Save_Impl(2, 0, a_fileName);
	}


	void BGSSaveLoadManager::Load(const char* a_fileName)
	{
		Load_Impl(a_fileName, -1, 0, true);
	}


	void BGSSaveLoadManager::Load(const char* a_fileName, bool a_checkForMods)
	{
		Load_Impl(a_fileName, -1, 0, a_checkForMods);
	}


	bool BGSSaveLoadManager::Save_Impl(SInt32 a_deviceID, UInt32 a_outputStats, const char* a_fileName)
	{
		using func_t = decltype(&BGSSaveLoadManager::Save_Impl);
		REL::Offset<func_t> func(Offset::BGSSaveLoadManager::Save);
		return func(this, a_deviceID, a_outputStats, a_fileName);
	}


	bool BGSSaveLoadManager::Load_Impl(const char* a_fileName, SInt32 a_deviceID, UInt32 a_outputStats, bool a_checkForMods)
	{
		using func_t = decltype(&BGSSaveLoadManager::Load_Impl);
		REL::Offset<func_t> func(Offset::BGSSaveLoadManager::Load);
		return func(this, a_fileName, a_deviceID, a_outputStats, a_checkForMods);
	}


	bool BGSSaveLoadManager::PopulateSaveList()
	{
		using func_t = decltype(&BGSSaveLoadManager::PopulateSaveList);
		REL::Offset<func_t> func(0x00590320);
		return func(this);
	}
}
