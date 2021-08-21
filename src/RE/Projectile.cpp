#include "RE/Projectile.h"

#include "RE/FormTraits.h"
#include "RE/BGSProjectile.h"


namespace RE
{
	float Projectile::GetHeight() const
	{
		auto base = GetObjectReference();
		auto projectile = base ? base->As<BGSProjectile>() : nullptr;
		return projectile ? projectile->data.collisionRadius * 2 : 0.0f;
	}
}