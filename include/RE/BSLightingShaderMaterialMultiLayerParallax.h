#pragma once

#include "RE/BSLightingShaderMaterialBase.h"


namespace RE
{
	class NiSourceTexture;


	class BSLightingShaderMaterialMultiLayerParallax : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterialMultiLayerParallax;


		virtual ~BSLightingShaderMaterialMultiLayerParallax();	// 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial* Create() override;																												 // 01
		virtual void			  CopyMembers(BSShaderMaterial* a_src) override;																					 // 02
		virtual UInt32			  ComputeCRC32(void) override;																										 // 04
		virtual Feature			  GetFeature() const override;																										 // 06 - { return Feature::kMultilayerParallax; }
		virtual void			  OnLoadTextureSet(UInt64 a_arg1, BSTextureSet* a_textureSet) override;																 // 08
		virtual void			  ClearTextures() override;																											 // 09
		virtual void			  ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN) override;	 // 0A
		virtual void			  GetTextures(void) override;																										 // 0B
		virtual void			  SaveBinary(NiStream& a_stream) override;																							 // 0C
		virtual void			  LoadBinary(NiStream& a_stream) override;																							 // 0D

		static BSLightingShaderMaterialMultiLayerParallax* CreateMaterial();


		// members
		NiPointer<NiSourceTexture> layerTexture;			  // A0
		NiPointer<NiSourceTexture> envTexture;				  // A8
		NiPointer<NiSourceTexture> envMaskTexture;			  // B0
		float					   parallaxLayerThickness;	  // B8
		float					   parallaxRefractionScale;	  // BC
		float					   parallaxInnerLayerUScale;  // C0
		float					   parallaxInnerLayerVScale;  // C4
		float					   envmapScale;				  // C8
		UInt32					   padCC;					  // CC


	private:
		BSLightingShaderMaterialMultiLayerParallax* ctor();
	};
	STATIC_ASSERT(sizeof(BSLightingShaderMaterialMultiLayerParallax) == 0xD0);
}
