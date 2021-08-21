#include "RE/PlayerInputHandler.h"


namespace RE
{
	bool PlayerInputHandler::IsEnabled() const
	{
		return enabled != 0;
	}


	void PlayerInputHandler::SetEnabled(bool a_enable)
	{
		enabled = a_enable ? 1 : 0;
	}
}
