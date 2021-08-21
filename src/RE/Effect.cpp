#include "RE/Effect.h"
#include "SKSE/Utilities.h"


namespace RE
{
	Effect::EffectItem::EffectItem() :
		magnitude(0.0),
		area(0),
		duration(0)
	{}


	Effect::Effect() :
		effectItem(),
		pad0C(0),
		baseEffect(nullptr),
		cost(0.0),
		pad1C(0),
		conditions()
	{}


	bool Effect::IsMatch(EffectSetting* a_base, float a_mag, UInt32 a_area, UInt32 a_dur, float a_cost)
	{
		namespace FLOAT = SKSE::UTIL::FLOAT;

		return baseEffect == a_base && FLOAT::essentiallyEqual(effectItem.magnitude, a_mag) && effectItem.area == a_area && effectItem.duration == a_dur && FLOAT::essentiallyEqual(cost, a_cost);
	}
}
