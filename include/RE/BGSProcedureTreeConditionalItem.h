#pragma once

#include "RE/IProcedureTreeItem.h"
#include "RE/TESCondition.h"


namespace RE
{
	class BGSProcedureTreeConditionalItem : public IProcedureTreeItem
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSProcedureTreeConditionalItem;


		virtual ~BGSProcedureTreeConditionalItem();	 // 00

		// override (IProcedureTreeItem)
		virtual void Unk_01(void) override;			 // 01
		virtual void Unk_02(void) override;			 // 02
		virtual void Load(TESFile* a_mod) override;	 // 03
		virtual void Unk_07(void) override;			 // 07


		// members
		TESCondition conditions;  // 08
	};
	STATIC_ASSERT(sizeof(BGSProcedureTreeConditionalItem) == 0x10);
}
