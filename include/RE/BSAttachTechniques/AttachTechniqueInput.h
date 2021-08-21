#pragma once


namespace RE
{
	class NiNode;


	namespace BSAttachTechniques
	{
		struct AttachTechniqueInput
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSAttachTechniques__AttachTechniqueInput;


			virtual ~AttachTechniqueInput();  // 00

			// add
			virtual void Unk_01(void);	// 01


			// members
			NiPointer<NiNode> current3DRoot;  // 08 - smart ptr
			NiPointer<NiNode> attachedArt;	  // 10 - smart ptr
			UInt32			  unk18;		  // 18
			UInt32			  unk1C;		  // 1C
		};
		STATIC_ASSERT(sizeof(AttachTechniqueInput) == 0x20);
	}
}
