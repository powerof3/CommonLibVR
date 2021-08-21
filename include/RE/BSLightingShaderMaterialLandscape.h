#pragma once

#include "RE/BSLightingShaderMaterialBase.h"


namespace RE
{
	class NiSourceTexture;


	class BSLightingShaderMaterialLandscape : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterialLandscape;


		virtual ~BSLightingShaderMaterialLandscape();  // 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial* Create() override;																												 // 01
		virtual void			  CopyMembers(BSShaderMaterial* a_src) override;																					 // 02
		virtual Feature			  GetFeature() const override;																										 // 06 - { return Feature::kMultiTexLandLODBlend; }
		virtual void			  ClearTextures() override;																											 // 09
		virtual void			  ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN) override;	 // 0A
		virtual void			  GetTextures(void) override;																										 // 0B

		static BSLightingShaderMaterialLandscape* CreateMaterial();


		// members
		UInt32					   numLandscapeTextures;		// 0A0
		UInt32					   pad0A4;						// 0A4
		NiPointer<NiSourceTexture> landscapeDiffuseTexture[5];	// 0A8
		NiPointer<NiSourceTexture> landscapeNormalTexture[5];	// 0D0
		NiPointer<NiSourceTexture> terrainOverlayTexture;		// 0F8
		NiPointer<NiSourceTexture> terrainNoiseTexture;			// 100
		NiColorA				   landBlendParams;				// 108
		float					   textureIsSnow[6];			// 118
		float					   textureIsSpecPower[6];		// 130
		float					   terrainTexOffsetX;			// 148
		float					   terrainTexOffsetY;			// 14C
		float					   terrainTexFade;				// 150
		UInt32					   pad154;						// 154


	private:
		BSLightingShaderMaterialLandscape* ctor();
	};
	STATIC_ASSERT(sizeof(BSLightingShaderMaterialLandscape) == 0x158);
}
