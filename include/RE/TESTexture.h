#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSString.h"
#include "RE/BaseFormComponent.h"


namespace RE
{
	class TESTexture : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESTexture;


		virtual ~TESTexture();	// 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01
		virtual void ClearDataComponent() override;						// 02
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual UInt32		GetMaxAllowedSize();					 // 04 - { return 0; }
		virtual const char* GetAsNormalFile(BSString& a_out) const;	 // 05
		virtual const char* GetDefaultPath() const;					 // 06 - { return "Textures\\"; }


		// members
		BSFixedString textureName;	// 08 - ICON
	};
	STATIC_ASSERT(sizeof(TESTexture) == 0x10);
}
