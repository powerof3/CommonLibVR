#include "RE/BSGraphics/State.h"

#include "REL/Relocation.h"


namespace RE
{
	namespace BSGraphics
	{
		State* State::GetSingleton()
		{
			//REL::Offset<State*> singleton = REL::ID(524998);
			REL::Offset<State*> singleton = 0x03186C10;
			return singleton.GetType();
		}
	}
}
