#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class BGSKeyword;
	class TESObjectREFR;


	class ExtraMissingLinkedRefIDs : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraMissingLinkedRefIDs;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kMissingLinkedRefIDs;


		struct Entry
		{
		public:
			// members
			BGSKeyword* keyword;	  // 00
			FormID		linkedRefID;  // 08
			UInt32		pad0C;		  // 0C
		};
		STATIC_ASSERT(sizeof(Entry) == 0x10);


		// a variation of a small array
		struct Array
		{
		public:
			using value_type = Entry;
			using size_type = UInt32;
			using reference = value_type&;
			using iterator = Entry*;


			union Data
			{
				Entry* entryPtr;
				Entry  entry[1];
			};
			STATIC_ASSERT(sizeof(Data) == 0x10);


			reference operator[](size_type a_pos);
			iterator  begin() noexcept;
			iterator  end() noexcept;
			size_type size() const noexcept;


			// members
			Data   _data;	// 00
			UInt32 _size;	// 10
			UInt32 _pad14;	// 14
		};
		STATIC_ASSERT(sizeof(Array) == 0x18);


		virtual ~ExtraMissingLinkedRefIDs();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kMissingLinkedRefIDs; }

		TESObjectREFR* GetLinkedRef(BGSKeyword* a_keyword);


		// members
		Array entries;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraMissingLinkedRefIDs) == 0x28);
}
