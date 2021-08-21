#pragma once

#include "RE/BSLightingShaderMaterialBase.h"


namespace RE
{
	class BSLightingShaderMaterialFacegenTint : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterialFacegenTint;


		virtual ~BSLightingShaderMaterialFacegenTint();	 // 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial* Create() override;								// 01
		virtual void			  CopyMembers(BSShaderMaterial* a_other) override;	// 02
		virtual UInt32			  ComputeCRC32(void) override;						// 04
		virtual Feature			  GetFeature() const override;						// 06 - { return Feature::kFaceGenRGBTint; }
		virtual void			  SaveBinary(NiStream& a_stream) override;			// 0C
		virtual void			  LoadBinary(NiStream& a_stream) override;			// 0D

		static BSLightingShaderMaterialFacegenTint* CreateMaterial();


		// members
		NiColor tintColor;	// A0
		UInt32	padAC;		// AC


	private:
		BSLightingShaderMaterialFacegenTint* ctor();
	};
	STATIC_ASSERT(sizeof(BSLightingShaderMaterialFacegenTint) == 0xB0);
}
