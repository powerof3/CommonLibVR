#include "RE/BGSProjectile.h"


namespace RE
{
	UInt32 BGSProjectile::GetType() const
	{
		using Type = BGSProjectileData::Type;

		if ((data.types & Type::kMissile) == Type::kMissile) {
			return 1;
		}
		if ((data.types & Type::kGrenade) == Type::kGrenade) {
			return 2;
		}
		if ((data.types & Type::kBeam) == Type::kBeam) {
			return 3;
		}
		if ((data.types & Type::kFlamethrower) == Type::kFlamethrower) {
			return 4;
		}
		if ((data.types & Type::kCone) == Type::kCone) {
			return 5;
		}
		if ((data.types & Type::kBarrier) == Type::kBarrier) {
			return 6;
		}
		if ((data.types & Type::kArrow) == Type::kArrow) {
			return 7;
		}
		return 0;
	}
}