#pragma once

#include "RE/BSTArray.h"
#include "RE/NiAVObject.h"
#include "RE/NiFrustum.h"
#include "RE/NiPoint3.h"
#include "RE/NiRect.h"


namespace RE
{
	class NiCamera : public NiAVObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiCamera;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiCamera;


		virtual ~NiCamera();  // 00

		// override (NiAVObject)
		virtual const NiRTTI* GetRTTI() const override;							  // 02
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;  // 17 - { return this; }
		virtual void		  LoadBinary(NiStream& a_stream) override;			  // 18 - { return; }
		virtual void		  LinkObject(NiStream& a_stream) override;			  // 19 - { return; }
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	  // 1A
		virtual void		  SaveBinary(NiStream& a_stream) override;			  // 1B - { return; }
		virtual bool		  IsEqual(NiObject* a_object) override;				  // 1C
		virtual void		  UpdateWorldBound() override;						  // 2F - { return; }
		virtual void		  UpdateWorldData(NiUpdateData* a_data) override;	  // 30

		static bool WorldPtToScreenPt3(const float a_matrix[4][4], const NiRect<float>& a_port, const NiPoint3& a_point, float& a_xOut, float& a_yOut, float& a_zOut, float a_zeroTolerance);


		// members
		float			worldToCam[4][4];  // 138
		NiFrustum*		viewFrustumPtr;	   // 178
		BSTArray<void*> unk180;			   // 180
		BSTArray<void*> unk198;			   // 198
		BSTArray<void*> unk1B0;			   // 1B0
		UInt32			unk1C8;			   // 1C8
		NiFrustum		viewFrustum;	   // 1CC
		float			minNearPlaneDist;  // 1E8
		float			maxFarNearRatio;   // 1EC
		NiRect<float>	port;			   // 1F0
		float			lodAdjust;		   // 200
	};
	STATIC_ASSERT(sizeof(NiCamera) == 0x208);
}
