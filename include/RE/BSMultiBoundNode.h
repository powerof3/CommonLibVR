#pragma once

#include "RE/BSCullingProcess.h"
#include "RE/BSNiNode.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class BSMultiBound;
	class BSMultiBoundRoom;
	class NiPoint3;


	class BSMultiBoundNode : public BSNiNode
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSMultiBoundNode;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSMultiBoundNode;


		virtual ~BSMultiBoundNode();  // 00

		// override (BSNiNode)
		virtual const NiRTTI*	  GetRTTI() const override;											 // 02
		virtual BSMultiBoundNode* AsMultiBoundNode() override;										 // 06 - { return this; }
		virtual NiObject*		  CreateClone(NiCloningProcess& a_cloning) override;				 // 17
		virtual void			  LoadBinary(NiStream& a_stream) override;							 // 18
		virtual void			  LinkObject(NiStream& a_stream) override;							 // 19
		virtual bool			  RegisterStreamables(NiStream& a_stream) override;					 // 1A
		virtual void			  SaveBinary(NiStream& a_stream) override;							 // 1B
		virtual bool			  IsEqual(NiObject* a_object) override;								 // 1C
		virtual void			  UpdateDownwardPass(NiUpdateData& a_data, UInt32 a_arg2) override;	 // 2C
		virtual void			  UpdateWorldBound() override;										 // 2F
		virtual void			  OnVisible(NiCullingProcess& a_process) override;					 // 34
		virtual void			  UpdateUpwardPass(NiUpdateData& a_data) override;					 // 3D

		// add
		virtual BSMultiBoundRoom* GetMultiBoundRoom();					  // 3E - { return 0; }
		virtual bool			  QPointWithin(const NiPoint3& a_point);  // 3F
		virtual void			  Unk_40(void);							  // 40
		virtual void			  Unk_41(void);							  // 41


		// members
		NiPointer<BSMultiBound>			  multiBound;	  // 150
		BSCullingProcess::BSCPCullingType cullingMode;	  // 158
		float							  lastAccumTime;  // 15C
	};
	STATIC_ASSERT(sizeof(BSMultiBoundNode) == 0x160);
}
