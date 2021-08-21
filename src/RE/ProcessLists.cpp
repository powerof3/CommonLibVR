#include "RE/ProcessLists.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"

#include "RE/TESObjectREFR.h"
#include "RE/ShaderReferenceEffect.h"

namespace RE
{
	ProcessLists* ProcessLists::GetSingleton()
	{
		REL::Offset<ProcessLists**> singleton(Offset::ProcessLists::Singleton);
		return *singleton;
	}


	void ProcessLists::GetMagicEffects(std::function<bool(BSTempEffect& a_tempEffect)> a_fn)
	{
		BSSpinLockGuard locker(magicEffectsLock);

		for (auto& tempEffectPtr : magicEffects) {
			const auto& tempEffect = tempEffectPtr.get();
			if (tempEffect) {
				if (!a_fn(*tempEffect)) {
					break;
				}
			}
		}
	}


	void ProcessLists::StopCombatAndAlarmOnActor(Actor* a_actor, bool a_dontEndAlarm)
	{
		using func_t = decltype(&ProcessLists::StopCombatAndAlarmOnActor);
		REL::Offset<func_t> func(Offset::ProcessLists::StopCombatAndAlarmOnActor);
		return func(this, a_actor, a_dontEndAlarm);
	}


	void ProcessLists::StopAllShaders(TESObjectREFR& a_ref)
	{
		/*auto handle = a_ref.CreateRefHandle();
		GetMagicEffects([&](BSTempEffect& a_tempEffect) {
			const auto referenceEffect = a_tempEffect.As<ShaderReferenceEffect>();
			if (referenceEffect && referenceEffect->target == handle) {
				referenceEffect->finished = true;
			}
			return true;
		});*/
	}
}
