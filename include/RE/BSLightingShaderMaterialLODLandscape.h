#pragma once

#include "RE/BSLightingShaderMaterialBase.h"


namespace RE
{
	class NiSourceTexture;


	class BSLightingShaderMaterialLODLandscape : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterialLODLandscape;


		virtual ~BSLightingShaderMaterialLODLandscape();  // 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial* Create() override;																												 // 01
		virtual void			  CopyMembers(BSShaderMaterial* a_src) override;																					 // 02
		virtual Feature			  GetFeature() const override;																										 // 06 - { return Feature::kLODLandNoise; }
		virtual void			  ClearTextures() override;																											 // 09
		virtual void			  ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN) override;	 // 0A
		virtual void			  GetTextures(void) override;																										 // 0B

		static BSLightingShaderMaterialLODLandscape* CreateMaterial();


		// members
		NiPointer<NiSourceTexture> parentDiffuseTexture;   // A0
		NiPointer<NiSourceTexture> parentNormalTexture;	   // A8
		NiPointer<NiSourceTexture> landscapeNoiseTexture;  // B0
		float					   terrainTexOffsetX;	   // B4
		float					   terrainTexOffsetY;	   // B8
		float					   terrainTexFade;		   // BC


	private:
		BSLightingShaderMaterialLODLandscape* ctor();
	};
	STATIC_ASSERT(sizeof(BSLightingShaderMaterialLODLandscape) == 0xC8);
}
