#include "RE/ConeProjectile.h"


namespace RE
{
	float ConeProjectile::GetHeight() const
	{
		return initialCollisionSphereRadius * 2.0f;
	}
}