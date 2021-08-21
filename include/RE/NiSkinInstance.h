#pragma once

#include "RE/NiObject.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class NiAVObject;
	class NiTransform;
	class NiSkinData;
	class NiSkinPartition;


	class NiSkinInstance : public NiObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiSkinInstance;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiSkinInstance;


		virtual ~NiSkinInstance();	// 00

		// override (NiObject)
		virtual const NiRTTI* GetRTTI() const override;							  // 02
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;  // 17
		virtual void		  LoadBinary(NiStream& a_stream) override;			  // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			  // 19
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	  // 1A
		virtual void		  SaveBinary(NiStream& a_stream) override;			  // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;				  // 1C
		virtual void		  PostLinkObject(NiStream& a_stream) override;		  // 1E - { return; }

		// add
		virtual void Unk_25(void);	// 25

		static NiSkinInstance* Create();


		// members
		NiPointer<NiSkinData>	   skinData;					  // 10
		NiPointer<NiSkinPartition> skinPartition;				  // 18
		NiAVObject*				   rootParent;					  // 20
		NiAVObject**			   bones;						  // 28
		const NiTransform**		   boneWorldTransforms;			  // 30
		UInt32					   frameID;						  // 38
		UInt32					   numMatrices;					  // 3C
		UInt32					   numRegisters;				  // 40
		UInt32					   allocatedSize;				  // 44
		void*					   boneMatrices;				  // 48
		void*					   prevBoneMatrices;			  // 50
		void*					   skinToWorldWorldToSkinMatrix;  // 58
		UInt64					   unk60;						  // 60 - no lock in VR
	};
	STATIC_ASSERT(sizeof(NiSkinInstance) == 0x68);
}
