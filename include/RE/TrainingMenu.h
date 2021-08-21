#pragma once

#include <string_view>

#include "RE/ActorValues.h"
#include "RE/BSTEvent.h"
#include "RE/GFxValue.h"
#include "RE/IMenu.h"


namespace RE
{
	class MenuOpenCloseEvent;


	// menuDepth = 3
	// flags = kPausesGame | kUsesMenuContext | kUpdateUsesCursor
	// kUsesCursor if gamepad disabled
	// context = kNone
	class TrainingMenu :
		public IMenu,							 // 00
		public BSTEventSink<MenuOpenCloseEvent>	 // 30
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_TrainingMenu;
		constexpr static std::string_view MENU_NAME = "Training Menu";


		virtual ~TrainingMenu();  // 00

		// override (IMenu)
		virtual void			   Accept(CallbackProcessor* a_cbReg) override;	   // 01
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;  // 04

		// override (BSTEventSink<MenuOpenCloseEvent>)
		virtual BSEventNotifyControl ProcessEvent(const MenuOpenCloseEvent* a_event, BSTEventSource<MenuOpenCloseEvent>* a_eventSource) override;  // 01


		// members
		void*	   unk38;			 // 38 - smart ptr
		ActorValue skill;			 // 40
		UInt32	   unk44;			 // 44
		GFxValue   trainingMenuObj;	 // 48 - MovieClip
		GFxValue   skillName;		 // 60 - TextField
		GFxValue   skillMeter;		 // 78 - Components.Meter
		GFxValue   trainerSkill;	 // 90 - TextField
		GFxValue   timesTrained;	 // A8 - TextField
		GFxValue   trainCost;		 // C0 - TextField
		GFxValue   currentGold;		 // D8 - TextField
	};
	STATIC_ASSERT(sizeof(TrainingMenu) == 0xF0);
}
