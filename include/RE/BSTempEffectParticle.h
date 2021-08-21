#pragma once

#include "RE/BSSoundHandle.h"
#include "RE/BSTSmartPointer.h"
#include "RE/BSTempEffect.h"
#include "RE/NiSmartPointer.h"
#include "RE/NiTransform.h"


namespace RE
{
	class BGSParticleObjectCloneTask;
	class NiAVObject;
	class NiNode;


	class BSTempEffectParticle : public BSTempEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSTempEffectParticle;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSTempEffectParticle;


		virtual ~BSTempEffectParticle();  // 00

		virtual const NiRTTI*	 GetRTTI() const override;		 // 02
		virtual void			 Detach() override;				 // 27
		virtual bool			 Update(float a_arg1) override;	 // 28
		virtual TEMP_EFFECT_TYPE GetType() const override;		 // 2C - { return kParticle; }


		// members
		NiPointer<NiAVObject>						particle3D;			// 30
		BSTSmartPointer<BGSParticleObjectCloneTask> cloneTask;			// 38
		const char*									modelName;			// 40
		NiPointer<NiNode>							dynamicCellNode;	// 48
		NiTransform									particleTransform;	// 50
		UInt32										flags;				// 84
		NiPointer<NiAVObject>						unk88;				// 88
		NiTransform									unk88Transform;		// 90
		UInt32										padC4;				// C4
		std::uint64_t								unkC8;				// C8
		BSSoundHandle								sound1;				// D0
		BSSoundHandle								sound2;				// DC
		std::uint8_t								unkE8;				// E8
		std::uint8_t								padE9;				// E9
		std::uint16_t								unkEA;				// EA
		UInt32										unkEC;				// EC
	};
	static_assert(sizeof(BSTempEffectParticle) == 0xF0);
};
