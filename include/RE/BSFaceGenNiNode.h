#pragma once

#include "RE/BSPointerHandle.h"
#include "RE/NiMatrix3.h"
#include "RE/NiNode.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class BSFaceGenAnimationData;
	class NiNode;


	class BSFaceGenNiNode : public NiNode
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSFaceGenNiNode;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSFaceGenNiNode;


		virtual ~BSFaceGenNiNode();	 // 00

		// override (NiNode)
		virtual const NiRTTI* GetRTTI() const override;											 // 02
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;				 // 17
		virtual void		  UpdateDownwardPass(NiUpdateData& a_data, UInt32 a_arg2) override;	 // 2C

		// add
		virtual void FixSkinInstances(NiNode* a_skeleton, bool a_arg2);	 // 3E


		// members
		NiMatrix3						  baseRotation;	  // 158
		UInt32							  pad17C;		  // 17C
		NiPointer<BSFaceGenAnimationData> animationData;  // 178
		float							  lastTime;		  // 180
		ActorHandle						  unk184;		  // 184
		UInt16							  flags;		  // 188
		UInt16							  pad18A;		  // 18A
		UInt32							  pad18C;		  // 18C
	};
	STATIC_ASSERT(sizeof(BSFaceGenNiNode) == 0x190);
}
