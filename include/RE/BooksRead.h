#pragma once

#include "RE/BSTEvent.h"


namespace RE
{
	class TESObjectBOOK;


	struct BooksRead
	{
	public:
		struct Event
		{
		public:
			// members
			TESObjectBOOK* book;		// 00
			bool		   unk08;		// 08
			UInt8		   pad11{ 0 };	// 09
			UInt16		   pad12{ 0 };	// 10
		};
		static_assert(sizeof(Event) == 0x10);


		static BSTEventSource<Event>* GetEventSource();
	};
}