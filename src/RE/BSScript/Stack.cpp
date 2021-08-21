#include "RE/BSScript/Stack.h"

#include "RE/BSScript/IStackCallbackFunctor.h"
#include "RE/BSScript/Internal/CodeTasklet.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	namespace BSScript
	{
		Stack::~Stack()
		{
			Dtor();
			memzero(this);
		}


		UInt32 Stack::GetPageForFrame(const StackFrame* a_frame) const
		{
			for (UInt32 i = 0; i < pages.size(); ++i) {
				auto& pair = pages[i];
				if (pair.page->IsInRange(a_frame)) {
					return i;
				}
			}
			assert(false);
			return static_cast<UInt32>(-1);
		}


		Variable& Stack::GetStackFrameVariable(const StackFrame* a_frame, UInt32 a_index, UInt32 a_pageHint)
		{
			using func_t = decltype(&Stack::GetStackFrameVariable);
			REL::Offset<func_t> func = 0x129A720;
			return func(this, a_frame, a_index, a_pageHint);
		}


		void Stack::Dtor()
		{
			using func_t = decltype(&Stack::Dtor);
			REL::Offset<func_t> func(Offset::BSScript::Stack::Dtor);
			return func(this);
		}
	}
}
