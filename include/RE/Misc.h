#pragma once


namespace RE
{
	class Actor;
	template <class T>
	class NiPointer;
	class Setting;
	class TESObjectREFR;


	void	 CreateRefHandle(RefHandle& a_handleOut, TESObjectREFR* a_refrTo);
	void	 DebugNotification(const char* a_notification, const char* a_soundToPlay = 0, bool a_cancelIfAlreadyQueued = true);
	Setting* GetINISetting(const char* a_name);
	bool	 LookupReferenceByHandle(const RefHandle& a_handle, NiPointer<Actor>& a_refrOut);
	bool	 LookupReferenceByHandle(const RefHandle& a_handle, NiPointer<TESObjectREFR>& a_refrOut);
	void	 PlaySound(const char* a_editorID);

	void func2FAE50();


	namespace Util
	{
		void		SanitizeTexturePath(std::string& a_path);
		std::string GetTextureName(std::string& a_path);
	}
}
