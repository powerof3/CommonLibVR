#pragma once

#include "RE/BSAttachTechniques/AttachTechniqueInput.h"
#include "RE/BSFixedString.h"


namespace RE
{
	class bhkWorld;


	class RefAttachTechniqueInput : public BSAttachTechniques::AttachTechniqueInput
	{
	public:
		inline static constexpr auto RTTI = RTTI_RefAttachTechniqueInput;


		virtual ~RefAttachTechniqueInput();	 // 00

		// override (BSAttachTechniques::AttachTechniqueInput)
		virtual void Unk_01(void) override;	 // 01


		// members
		UInt64		  unk20;		 // 20
		TESRace*	  actorRace;	 // 28
		bhkWorld*	  physicsWorld;	 // 30
		UInt32		  unk38;		 // 38
		UInt32		  unk3C;		 // 3C
		BSFixedString nodeName;		 // 40
	};
	STATIC_ASSERT(sizeof(RefAttachTechniqueInput) == 0x48);
}
