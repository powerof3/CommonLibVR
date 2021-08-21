#pragma once

#include "RE/BSAtomic.h"
#include "RE/BSPointerHandle.h"
#include "RE/BSSoundHandle.h"
#include "RE/BSTList.h"
#include "RE/FormTypes.h"
#include "RE/ImpactResults.h"
#include "RE/MagicSystem.h"
#include "RE/NiSmartPointer.h"
#include "RE/NiTransform.h"
#include "RE/TESObjectREFR.h"


namespace RE
{
	class BGSExplosion;
	class BGSMaterialType;
	class bhkCollisionObject;
	class bhkSimpleShapePhantom;
	class EffectSetting;
	class MagicItem;
	class QueuedFile;
	class NiPointLight;
	class NonActorMagicCaster;


	class Explosion : public TESObjectREFR
	{
	public:
		inline static constexpr auto RTTI = RTTI_Explosion;


		enum class Flags : UInt32
		{
			kNone = 0,
			kInWater = 1 << 5
		};


		virtual ~Explosion();  // 00

		// override (TESObjectREFR)
		virtual void		 SaveGame(BGSSaveFormBuffer* a_buf) override;							// 0E
		virtual void		 Revert(BGSLoadFormBuffer* a_buf) override;								// 12
		virtual void		 SetActorCause(ActorCause* a_cause) override;							// 50 - { actorCause = a_cause; }
		virtual ActorCause*	 GetActorCause() const override;										// 51 - { return actorCause; }
		virtual MagicCaster* GetMagicCaster(MagicSystem::CastingSource a_source) override;			// 5C
		virtual void		 InitHavok() override;													// 66
		virtual void		 Release3DRelatedData() override;										// 6B
		virtual Explosion*	 AsExplosion() override;												// 8E
		virtual bool		 OnAddCellPerformQueueReference(TESObjectCELL& a_cell) const override;	// 90 - { return false; }

		// add
		virtual void Unk_A2(void);	// A2 - { return 0; }
		virtual void Unk_A3(void);	// A3 - { return 0; }
		virtual void Unk_A4(void);	// A4 - { return 0; }

		// members
		UInt64					unk98;		   // 098
		float					unkA0;		   // 0A0
		float					unkA4;		   // 0A4
		float					unkA8;		   // 0A8
		float					radius;		   // 0AC
		float					imodRadius;	   // 0B0
		float					unkB4;		   // 0B4
		bhkSimpleShapePhantom*	unkB8;		   // 0B8
		UInt64					unkC0;		   // 0C0
		UInt64					unkC8;		   // 0C8
		BSSoundHandle			sound01;	   // 0D0
		BSSoundHandle			sound02;	   // 0DC
		NiPointer<NiPointLight> light;		   // 0E8
		UInt32					unkF0;		   // 0F0
		UInt32					unkF4;		   // 0F4
		UInt32					unkF8;		   // 0F8
		UInt32					padFC;		   // 0FC
		NiPointer<ActorCause>	actorCause;	   // 100
		NonActorMagicCaster*	magicCaster;   // 108
		TESObjectWEAP*			weaponSource;  // 110
		UInt32					unk118;		   // 118
		NiPoint3				unk11C;		   // 11C
		NiPoint3				unk128;		   // 128
		float					unk134;		   // 134
		float					unk138;		   // 138
		Flags					flags;		   // 13C
	};
	static_assert(sizeof(Explosion) == 0x140);
}
