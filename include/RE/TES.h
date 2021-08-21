#pragma once

#include "RE/BSTEvent.h"
#include "RE/BSTList.h"
#include "RE/ICellAttachDetachEventSource.h"


namespace RE
{
	namespace BSResource
	{
		struct ArchiveStreamOpenedEvent;
	}


	class BSSystemEvent;
	class GridCellArray;
	struct PositionPlayerEvent;
	class Sky;
	class TESNPC;
	class TESObjectCELL;
	class TESWorldSpace;


	class TES :
		public ICellAttachDetachEventSource,						// 000
		public BSTEventSink<BSResource::ArchiveStreamOpenedEvent>,	// 060
		public BSTEventSink<PositionPlayerEvent>					// 068
	{
	public:
		inline static constexpr auto RTTI = RTTI_TES;


		struct NPCDeadCount
		{
			TESNPC* npc;		// 00
			UInt16	deadCount;	// 08
		};


		class SystemEventAdapter : public BSTEventSink<BSSystemEvent>
		{
		public:
			inline static constexpr auto RTTI = RTTI_TES;


			virtual ~SystemEventAdapter();	// 00

			// override (BSTEventSink<BSSystemEvent>)
			virtual BSEventNotifyControl ProcessEvent(const BSSystemEvent* a_event, BSTEventSource<BSSystemEvent>* a_eventSource) override;	 // 01


			// members
			UInt64 unk08;  // 08
		};
		STATIC_ASSERT(sizeof(SystemEventAdapter) == 0x10);


		virtual ~TES();	 // 00

		// override (BSTEventSink<BSResource::ArchiveStreamOpenedEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BSResource::ArchiveStreamOpenedEvent* a_event, BSTEventSource<BSResource::ArchiveStreamOpenedEvent>* a_eventSource) override;  // 01 - { return BSEventNotifyControl::kContinue; }

		// override (BSTEventSink<PositionPlayerEvent>)
		virtual BSEventNotifyControl ProcessEvent(const PositionPlayerEvent* a_event, BSTEventSource<PositionPlayerEvent>* a_eventSource) override;	 // 01

		static TES* GetSingleton();


		// members
		UInt64						unk070;				 // 070
		GridCellArray*				gridCells;			 // 078
		UInt64						unk080;				 // 080
		UInt64						unk088;				 // 088
		UInt64						unk090;				 // 090
		UInt64						unk098;				 // 098
		UInt64						unk0A0;				 // 0A0
		UInt64						unk0A8;				 // 0A8
		UInt64						unk0B0;				 // 0B0
		UInt64						unk0B8;				 // 0B8
		TESObjectCELL*				interiorCell;		 // 0C0
		TESObjectCELL**				interiorCellBuffer;	 // 0C8
		void*						unk0D0;				 // 0D0
		UInt64						unk0D8;				 // 0D8
		UInt64						unk0E0;				 // 0E0
		UInt64						unk0E8;				 // 0E8
		UInt64						unk0F0;				 // 0F0
		UInt64						unk0F8;				 // 0F8
		Sky*						sky;				 // 100
		UInt64						unk108;				 // 108
		UInt64						unk110;				 // 110
		UInt64						unk118;				 // 118
		UInt64						unk120;				 // 120
		UInt64						unk128;				 // 128
		UInt64						unk130;				 // 130
		UInt64						unk138;				 // 138
		TESWorldSpace*				worldSpace;			 // 140
		BSSimpleList<NPCDeadCount*> npcDeadCount;		 // 148
		void*						unk158;				 // 158 - smart ptr
		void*						unk160;				 // 160 - smart ptr
		void*						unk168;				 // 168 - smart ptr
		void*						unk170;				 // 170 - smart ptr
		UInt64						unk178;				 // 178
		UInt64						unk180;				 // 180
		UInt64						unk188;				 // 188
		UInt64						unk190;				 // 190
		UInt64						unk198;				 // 198
		UInt64						unk1A0;				 // 1A0
		UInt64						unk1A8;				 // 1A8
		UInt64						unk1B0;				 // 1B0
		UInt64						unk1B8;				 // 1B8
		UInt64						unk1C0;				 // 1C0
		UInt64						unk1C8;				 // 1C8
		UInt64						unk1D0;				 // 1D0
		UInt64						unk1D8;				 // 1D8
		UInt64						unk1E0;				 // 1E0
		UInt64						unk1E8;				 // 1E8
		UInt64						unk1F0;				 // 1F0
		UInt64						unk1F8;				 // 1F8
		UInt64						unk200;				 // 200
		UInt64						unk208;				 // 208
		UInt64						unk210;				 // 210
		UInt64						unk218;				 // 218
		UInt64						unk220;				 // 220
		UInt64						unk228;				 // 228
		UInt64						unk230;				 // 230
		UInt64						unk238;				 // 238
		UInt64						unk240;				 // 240
		UInt64						unk248;				 // 248
		UInt64						unk250;				 // 250
		UInt64						unk258;				 // 258
		UInt64						unk260;				 // 260
		UInt64						unk268;				 // 268
		UInt64						unk270;				 // 270
		UInt64						unk278;				 // 278
		UInt64						unk280;				 // 280
		UInt64						unk288;				 // 288
		SystemEventAdapter			unk290;				 // 290
		UInt64						unk2A0;				 // 2A0
		UInt64						unk2A8;				 // 2A8
		UInt64						unk2B0;				 // 2B0
	};
	STATIC_ASSERT(sizeof(TES) == 0x2B8);
}
