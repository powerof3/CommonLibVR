#pragma once

#include "RE/NiPoint3.h"
#include "RE/PlayerInputHandler.h"
#include "RE/TESCameraState.h"


namespace RE
{
	class NiNode;


	class FirstPersonState :
		public TESCameraState,	   // 00
		public PlayerInputHandler  // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_FirstPersonState;


		virtual ~FirstPersonState();  // 00

		// override (TESCameraState)
		virtual void Begin() override;												 // 01
		virtual void End() override;												 // 02
		virtual void Update(BSTSmartPointer<TESCameraState>& a_nextState) override;	 // 03
		virtual void GetRotation(NiQuaternion& a_rotation) override;				 // 04
		virtual void GetTranslation(NiPoint3& a_translation) override;				 // 05
		virtual void SaveGame(BGSSaveFormBuffer* a_buf) override;					 // 06
		virtual void LoadGame(BGSLoadFormBuffer* a_buf) override;					 // 07
		virtual void Revert(BGSLoadFormBuffer* a_buf) override;						 // 08

		// override (PlayerInputHandler)
		virtual bool CanProcess(InputEvent* a_event) override;											// 01
		virtual void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_movementData) override;	// 04


		// members
		NiPoint3	lastPosition;			  // 30
		NiPoint3	lastFrameSpringVelocity;  // 3C
		NiPoint3	dampeningOffset;		  // 48
		UInt32		pad54;					  // 54
		NiAVObject* firstPersonCameraObj;	  // 58
		NiNode*		firstPersonFOVControl;	  // 60
		float		sittingRotation;		  // 68
		float		unk6C;					  // 6C
		float		unk70;					  // 70
		float		currentPitchOffset;		  // 74 - [-100, 100]
		float		targetPitchOffset;		  // 78 - [-100, 100]
		float		unk7C;					  // 7C
		UInt32		unk80;					  // 80
		bool		cameraOverride;			  // 84
		bool		cameraPitchOverride;	  // 85
		UInt16		unk86;					  // 86
		UInt64		unk88;					  // 88
	};
	STATIC_ASSERT(sizeof(FirstPersonState) == 0x90);
}
