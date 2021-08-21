#include "RE/Misc.h"

#include "RE/INIPrefSettingCollection.h"
#include "RE/INISettingCollection.h"
#include "RE/NiSmartPointer.h"
#include "RE/Offsets.h"
#include "RE/Setting.h"
#include "RE/TESObjectREFR.h"
#include "REL/Relocation.h"


namespace RE
{
	bool LookupReferenceByHandle_ActorImpl(const RefHandle& a_handle, NiPointer<Actor>& a_refrOut)
	{
		using func_t = decltype(&LookupReferenceByHandle_ActorImpl);
		REL::Offset<func_t> func(Offset::LookupReferenceByHandle);
		return func(a_handle, a_refrOut);
	}


	bool LookupReferenceByHandle_RefrImpl(const RefHandle& a_handle, NiPointer<TESObjectREFR>& a_refrOut)
	{
		using func_t = decltype(&LookupReferenceByHandle_RefrImpl);
		REL::Offset<func_t> func(Offset::LookupReferenceByHandle);
		return func(a_handle, a_refrOut);
	}


	void CreateRefHandle(RefHandle& a_handleOut, TESObjectREFR* a_refTo)
	{
		using func_t = decltype(&CreateRefHandle);
		REL::Offset<func_t> func(Offset::CreateRefHandle);
		return func(a_handleOut, a_refTo);
	}


	void DebugNotification(const char* a_notification, const char* a_soundToPlay, bool a_cancelIfAlreadyQueued)
	{
		using func_t = decltype(&DebugNotification);
		REL::Offset<func_t> func(Offset::DebugNotification);
		return func(a_notification, a_soundToPlay, a_cancelIfAlreadyQueued);
	}


	Setting* GetINISetting(const char* a_name)
	{
		Setting* setting = nullptr;

		auto iniPrefs = INIPrefSettingCollection::GetSingleton();
		setting = iniPrefs ? iniPrefs->GetSetting(a_name) : nullptr;
		if (!setting) {
			auto ini = INISettingCollection::GetSingleton();
			setting = ini ? ini->GetSetting(a_name) : nullptr;
		}
		return setting;
	}


	bool LookupReferenceByHandle(const RefHandle& a_handle, NiPointer<Actor>& a_refrOut)
	{
		return LookupReferenceByHandle_ActorImpl(a_handle, a_refrOut);
	}


	bool LookupReferenceByHandle(const RefHandle& a_handle, NiPointer<TESObjectREFR>& a_refrOut)
	{
		return LookupReferenceByHandle_RefrImpl(a_handle, a_refrOut);
	}


	void PlaySound(const char* a_editorID)
	{
		using func_t = decltype(&PlaySound);
		REL::Offset<func_t> func(Offset::PlaySound);
		return func(a_editorID);
	}


	void func2FAE50()
	{
		using func_t = decltype(&func2FAE50);
		REL::Offset<func_t> func(Offset::func2FAE50);
		return func();
	}


	namespace Util
	{
		void SanitizeTexturePath(std::string& a_path)
		{
			std::for_each(a_path.begin(), a_path.end(), [](char& c) {
				c = ::tolower(c);
			});

			a_path = std::regex_replace(a_path, std::regex("/+|\\\\+"), "\\");
			a_path = std::regex_replace(a_path, std::regex("^\\\\+"), "");
			a_path = std::regex_replace(a_path, std::regex(R"(.*?[^\s]textures\\|^textures\\)", std::regex_constants::icase), "");
		}

		std::string GetTextureName(std::string& a_path)
		{
			const int idx = a_path.find_last_of("\\/");
			if (std::string::npos != idx) {
				return a_path.substr(idx + 1);
			}
			return std::string();
		}
	}
}
