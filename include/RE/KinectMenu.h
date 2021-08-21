#pragma once

#include <string_view>

#include "RE/BSTEvent.h"
#include "RE/GFxValue.h"
#include "RE/IMenu.h"


namespace RE
{
	class MenuOpenCloseEvent;


	// menuDepth = 6
	// flags = kAllowSaving | kCustomRendering | kAssignCursorToRenderer
	// context = kNone
	class KinectMenu :
		public IMenu,							 // 00
		public BSTEventSink<MenuOpenCloseEvent>	 // 30
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_KinectMenu;
		constexpr static std::string_view MENU_NAME = "Kinect Menu";


		virtual ~KinectMenu();	// 00

		// override (IMenu)
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;  // 04

		// override (BSTEventSink<MenuOpenCloseEvent>)
		virtual BSEventNotifyControl ProcessEvent(const MenuOpenCloseEvent* a_event, BSTEventSource<MenuOpenCloseEvent>* a_eventSource) override;  // 01


		// members
		GFxValue root;	// 38 - "Menu_mc"
	};
	STATIC_ASSERT(sizeof(KinectMenu) == 0x50);
}
