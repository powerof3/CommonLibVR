#include "RE/TaskQueueInterface.h"

#include "REL/Relocation.h"


namespace RE
{
	TaskQueueInterface* TaskQueueInterface::GetSingleton()
	{
		REL::Offset<TaskQueueInterface**> singleton(0x2ffd778);	 // SE is 2f38978  VR is 2ffd778
		return *singleton;
	}
}
