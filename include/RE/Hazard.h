#pragma once

#include "RE/BSPointerHandle.h"
#include "RE/BSSoundHandle.h"
#include "RE/FormTypes.h"
#include "RE/NiSmartPointer.h"
#include "RE/TESObjectREFR.h"


namespace RE
{
	class BGSHazard;
	class NiLight;


	class Hazard : public TESObjectREFR
	{
	public:
		inline static constexpr auto RTTI = RTTI_Hazard;
		inline static constexpr auto FORMTYPE = FormType::PlacedHazard;


		enum class Flags : UInt32
		{
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
			};
		};


		virtual ~Hazard();	// 00

		// override (TESObjectREFR)
		virtual void SaveGame(BGSSaveFormBuffer* a_buf) override;							// 0E
		virtual void LoadGame(BGSLoadFormBuffer* a_buf) override;							// 0F
		virtual void FinishLoadGame(BGSLoadFormBuffer* a_buf) override;						// 11
		virtual void Revert(BGSLoadFormBuffer* a_buf) override;								// 12
		virtual void InitItemImpl() override;												// 13
		virtual void SetActorCause(ActorCause* a_cause) override;							// 50
		virtual void Release3DRelatedData() override;										// 6B
		virtual bool OnAddCellPerformQueueReference(TESObjectCELL& a_cell) const override;	// 90 - { return false; }

		// add
		virtual void Unk_A2(void);				  // A2
		virtual void Unk_A3(void);				  // A3 - { return; }
		virtual bool IsNotGeneratedForm() const;  // A4 - { return TESDataHandler::GetSingleton()->IsGeneratedFormID(formID) == 0; }


		// members
		void*			   hazardDBHandle;	// 98
		ActorHandle		   ownerActor;		// A0
		float			   age;				// A4
		float			   lifetime;		// A8
		float			   targetTimer;		// AC
		float			   radius;			// B0
		float			   magnitude;		// B4
		BGSHazard*		   hazard;			// B8
		NiPointer<NiLight> light;			// C0
		BSSoundHandle	   sound;			// C8
		Flags			   flags;			// D4
	};
	STATIC_ASSERT(sizeof(Hazard) == 0xD8);
}
