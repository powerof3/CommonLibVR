#pragma once

#include "RE/BaseFormComponent.h"

#include "RE/MemoryManager.h"

#include <optional>


namespace RE
{
	class SpellItem;
	class TESLevSpell;
	class TESShout;


	class TESSpellList : BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESSpellList;


		struct SpellData  // SPLO
		{
			SpellData();
			~SpellData() = default;

			TES_HEAP_REDEFINE_NEW();

			bool				  AddLevSpell(TESLevSpell* a_spell);
			bool				  AddShout(TESShout* a_spell);
			bool				  AddSpell(SpellItem* a_spell);
			std::optional<UInt32> GetIndex(SpellItem* a_spell);
			std::optional<UInt32> GetIndex(TESLevSpell* a_spell);
			std::optional<UInt32> GetIndex(TESShout* a_spell);
			bool				  RemoveSpell(SpellItem* a_spell);


			// members
			SpellItem**	  spells;		 // 00
			TESLevSpell** levSpells;	 // 08
			TESShout**	  shouts;		 // 10
			UInt32		  numSpells;	 // 18
			UInt32		  numlevSpells;	 // 1C
			UInt32		  numShouts;	 // 20
			UInt32		  pad24;		 // 24
		};
		STATIC_ASSERT(sizeof(SpellData) == 0x28);


		virtual ~TESSpellList();  // 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01 - { return; }
		virtual void ClearDataComponent() override;						// 02
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03


		// members
		SpellData* actorEffects;  // 08 - SPLO
	};
	STATIC_ASSERT(sizeof(TESSpellList) == 0x10);
}
