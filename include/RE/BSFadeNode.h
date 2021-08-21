#pragma once

#include "RE/NiNode.h"


namespace RE
{
	class BSLeafAnimNode;
	class BSTreeNode;


	class BSFadeNode : public NiNode
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSFadeNode;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSFadeNode;


		virtual ~BSFadeNode();	// 00

		// override (NiNode)
		virtual const NiRTTI* GetRTTI() const override;													 // 02
		virtual BSFadeNode*	  AsFadeNode() override;													 // 05 - { return this; }
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;						 // 17
		virtual void		  LoadBinary(NiStream& a_stream) override;									 // 18
		virtual void		  LinkObject(NiStream& a_stream) override;									 // 19
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;							 // 1A
		virtual void		  SaveBinary(NiStream& a_stream) override;									 // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;										 // 1C
		virtual void		  UpdateSelectedDownwardPass(NiUpdateData& a_data, UInt32 a_arg2) override;	 // 2D
		virtual void		  OnVisible(NiCullingProcess& a_process) override;							 // 34

		// add
		virtual BSTreeNode*		AsTreeNode();	   // 3E - { return 0; }
		virtual BSLeafAnimNode* AsLeafAnimNode();  // 3F - { return 0; }


		// members
		float  unk150;		 // 150
		float  unk154;		 // 154
		float  currentFade;	 // 158
		UInt32 unk15C;		 // 15C
		UInt32 unk160;		 // 160
		UInt32 unk164;		 // 164
		float  unk168;		 // 168
		UInt32 unk16C;		 // 16C
		UInt32 unk170;		 // 170
		float  unk174;		 // 174
		UInt16 unk176;		 // 176
		UInt8  unk177;		 // 177
		UInt8  unk178;		 // 178
		UInt8  unk179;		 // 179
		SInt8  unk17A;		 // 17A
		UInt16 unk17C;		 // 17C
	};
	STATIC_ASSERT(sizeof(BSFadeNode) == 0x180);
}
