#include "RE/TESQuest.h"

#include "RE/BGSStoryTeller.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	TESQuestStage::operator bool() const
	{
		return *reinterpret_cast<const std::uintptr_t*>(this) != 0;
	}


	ObjectRefHandle& TESQuest::CreateRefHandleByAliasID(ObjectRefHandle& a_handle, UInt32 a_aliasID)
	{
		using func_t = decltype(&TESQuest::CreateRefHandleByAliasID);
		REL::Offset<func_t> func = 0x0388110;
		return func(this, a_handle, a_aliasID);
	}


	bool TESQuest::EnsureQuestStarted(bool& a_result, bool a_startNow)
	{
		using func_t = decltype(&TESQuest::EnsureQuestStarted);
		REL::Offset<func_t> func(Offset::TESQuest::EnsureQuestStarted);
		return func(this, a_result, a_startNow);
	}


	UInt16 TESQuest::GetCurrentStageID() const
	{
		return currentStage;
	}


	bool TESQuest::IsActive() const
	{
		return (data.flags & QuestFlag::kActive) != QuestFlag::kNone;
	}


	bool TESQuest::IsCompleted() const
	{
		return (data.flags & QuestFlag::kCompleted) != QuestFlag::kNone;
	}


	bool TESQuest::IsEnabled() const
	{
		return (data.flags & QuestFlag::kEnabled) != QuestFlag::kNone;
	}


	bool TESQuest::IsRunning() const
	{
		return !IsStopping() && !promoteTask;
	}


	bool TESQuest::IsStarting() const
	{
		return IsEnabled() && (data.flags == QuestFlag::kStopStart || promoteTask);
	}


	bool TESQuest::IsStopped() const
	{
		return (data.flags & (QuestFlag::kEnabled | QuestFlag::kStageWait)) == QuestFlag::kNone;
	}


	bool TESQuest::IsStopping() const
	{
		return !IsEnabled() && data.flags == QuestFlag::kStopStart;
	}


	void TESQuest::Reset()
	{
		using func_t = decltype(&TESQuest::Reset);
		REL::Offset<func_t> func(Offset::TESQuest::ResetQuest);
		return func(this);
	}


	void TESQuest::ResetAndUpdate()
	{
		Reset();

		auto enabled = IsEnabled();
		if (enabled != StartsEnabled()) {
			auto storyTeller = BGSStoryTeller::GetSingleton();
			if (storyTeller) {
				if (enabled) {
					storyTeller->BeginStartUpQuest(this);
				} else {
					storyTeller->BeginShutDownQuest(this);
				}
			}
		}
	}


	void TESQuest::SetEnabled(bool a_set)
	{
		if (a_set) {
			data.flags |= QuestFlag::kEnabled;
		} else {
			data.flags &= ~QuestFlag::kEnabled;
		}
		AddChange(ChangeFlags::kQuestFlags);
	}


	bool TESQuest::Start()
	{
		if (eventID != QuestEvent::kNone) {
			_DMESSAGE("Attempting to start event scoped quest outside of story manager");
			return false;
		}

		bool result;
		return EnsureQuestStarted(result, true);
	}


	bool TESQuest::StartsEnabled() const
	{
		return (data.flags & QuestFlag::kStartsEnabled) != QuestFlag::kNone;
	}


	void TESQuest::Stop()
	{
		if (IsEnabled()) {
			SetEnabled(false);
		}
	}
}
