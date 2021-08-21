#pragma once

#include "RE/BSTSmartPointer.h"
#include "RE/BSTempEffect.h"
#include "RE/NiMatrix3.h"
#include "RE/NiPoint3.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class BSGeometry;
	class NiAVObject;
	class BGSTextureSet;
	class QueuedTempEffect;


	class BSTempEffectGeometryDecal : public BSTempEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSTempEffectGeometryDecal;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSTempEffectGeometryDecal;


		virtual ~BSTempEffectGeometryDecal();  // 00

		virtual const NiRTTI*	 GetRTTI() const override;		 // 02
		virtual void			 Initialize() override;			 // 25
		virtual void			 Attach() override;				 // 26
		virtual bool			 Update(float a_arg1) override;	 // 28
		virtual NiAVObject*		 Get3D() const override;		 // 29
		virtual TEMP_EFFECT_TYPE GetType() const override;		 // 2C - { return kGeometryDecal; }


		// members
		NiPointer<BSGeometry>			  decal;				   // 30
		NiPointer<BSGeometry>			  attachedGeometry;		   // 38
		NiPointer<NiNode>				  attachedGeometryParent;  // 40
		NiPointer<NiNode>				  decalNode;			   // 48
		BSTSmartPointer<QueuedTempEffect> queuedDecal;			   // 50
		BGSTextureSet*					  texSet;				   // 58
		BGSTextureSet*					  texSet2;				   // 60
		NiMatrix3						  rotation;				   // 68
		NiPoint3						  origin;				   // 8C
		NiPoint3						  direction;			   // 98
		float							  width;				   // A4
		UInt32							  unkA8;				   // A8
		UInt32							  flags;				   // AC
		bool							  unkB0;				   // B0
	};
	static_assert(sizeof(BSTempEffectGeometryDecal) == 0xB8);
}
