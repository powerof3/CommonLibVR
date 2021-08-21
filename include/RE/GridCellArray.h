#pragma once

#include "RE/GridArray.h"
#include "RE/NiPoint3.h"


namespace RE
{
	class TESObjectCELL;

	class GridCellArray : public GridArray
	{
	public:
		inline static constexpr auto RTTI = RTTI_GridCellArray;


		virtual ~GridCellArray();  // 00

		// override (GridArray)
		virtual void Unk_02(void) override;	 // 02
		virtual void Unk_03(void) override;	 // 03
		virtual void Unk_05(void) override;	 // 05
		virtual void Unk_06(void) override;	 // 06
		virtual void Unk_07(void) override;	 // 07
		virtual void Unk_08(void) override;	 // 08

		[[nodiscard]] TESObjectCELL* GetCell(UInt32 a_x, UInt32 a_y) const noexcept
		{
			return (a_x < length && a_y < length) ?
						 cells[(a_x * length) + a_y] :
						 nullptr;
		};

		// members
		TESObjectCELL** cells;	// 18 - (memory allocated using 0x8 * numGrids * numGrids)
		NiPoint3		unk20;	// 20
		bool			unk2C;	// 2C
	};
	static_assert(sizeof(GridCellArray) == 0x30);
};