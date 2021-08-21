#pragma once

#include "RE/BSLightingShaderMaterialBase.h"


namespace RE
{
	class BSLightingShaderMaterial : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterial;


		virtual ~BSLightingShaderMaterial();  // 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial* Create() override;			// 01
		virtual Feature			  GetFeature() const override;	// 06 - { return Feature::kDefault; }

		static BSLightingShaderMaterial* CreateMaterial();


	private:
		BSLightingShaderMaterialBase* ctor();
	};
	STATIC_ASSERT(sizeof(BSLightingShaderMaterial) == 0xA0);
}
