#pragma once

#include "RE/BSAtomic.h"
#include "RE/BSShaderMaterial.h"
#include "RE/NiColor.h"
#include "RE/NiSourceTexture.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class BSTextureSet;
	class NiStream;


	class BSLightingShaderMaterialBase : public BSShaderMaterial
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterialBase;


		virtual ~BSLightingShaderMaterialBase();  // 00

		// override (BSShaderMaterial)
		virtual BSShaderMaterial* Create() override = 0;							// 01
		virtual void			  CopyMembers(BSShaderMaterial* a_other) override;	// 02
		virtual bool			  DoIsCopy(BSShaderMaterial* a_other) override;		// 03
		virtual UInt32			  ComputeCRC32(void) override;						// 04
		virtual BSShaderMaterial* GetDefault() override;							// 05
		virtual Feature			  GetFeature() const override;						// 06 - { return Feature::kDefault; }
		virtual Type			  GetType() const override;							// 07 - { return Type::kLighting; }

		// add
		virtual void OnLoadTextureSet(UInt64 a_arg1, BSTextureSet* a_textureSet);															   // 08
		virtual void ClearTextures();																										   // 09
		virtual void ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN);  // 0A
		virtual void GetTextures(void);																										   // 0B
		virtual void SaveBinary(NiStream& a_stream);																						   // 0C
		virtual void LoadBinary(NiStream& a_stream);																						   // 0D

		static BSLightingShaderMaterialBase* CreateMaterial(Feature a_feature);

		void					CopyBaseMembers(BSLightingShaderMaterialBase* other);
		NiPointer<BSTextureSet> GetTextureSet() const;
		void					SetTextureSet(BSTextureSet* a_textureSet);


		// members
		NiColor					   specularColor;					// 38
		UInt32					   pad44;							// 44
		NiPointer<NiSourceTexture> diffuseTexture;					// 48
		SInt32					   diffuseRenderTargetSourceIndex;	// 50
		UInt32					   pad54;							// 54
		NiPointer<NiSourceTexture> normalTexture;					// 58
		NiPointer<NiSourceTexture> rimSoftLightingTexture;			// 60
		NiPointer<NiSourceTexture> specularBackLightingTexture;		// 68
		SInt32					   textureClampMode;				// 70
		SInt32					   pad74;							// 70
		NiPointer<BSTextureSet>	   textureSet;						// 78
		float					   materialAlpha;					// 80
		float					   refractionPower;					// 84
		float					   specularPower;					// 88
		float					   specularColorScale;				// 8C
		float					   subSurfaceLightRolloff;			// 90
		float					   rimLightPower;					// 94
		mutable BSSpinLock		   unk98;							// 98 - lock?
	};
	STATIC_ASSERT(sizeof(BSLightingShaderMaterialBase) == 0xA0);
}
