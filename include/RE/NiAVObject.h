#pragma once

#include "RE/BSShaderMaterial.h"
#include "RE/NiBound.h"
#include "RE/NiObjectNET.h"
#include "RE/NiSmartPointer.h"
#include "RE/NiTransform.h"
#include "RE/BSLightingShaderProperty.h"


namespace RE
{
	class BSFixedString;
	class NiAlphaProperty;
	class NiAVObject;
	class NiCollisionObject;
	class NiColor;
	class NiColorA;
	class NiCullingProcess;
	class NiNode;
	class NiPoint3;
	class TESObjectREFR;
	class BSGeometry;


	class NiUpdateData
	{
	public:
		enum class Flag : UInt32
		{
			kDirty = 1 << 0,
		};


		float time;	  // 0
		Flag  flags;  // 4
	};
	STATIC_ASSERT(sizeof(NiUpdateData) == 0x8);


	class PerformOpFunc
	{
	public:
		virtual ~PerformOpFunc();  // 00

		// add
		virtual bool operator()(NiAVObject* a_object);	// 01
	};
	STATIC_ASSERT(sizeof(PerformOpFunc) == 0x8);


	class NiAVObject : public NiObjectNET
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiAVObject;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiAVObject;


		enum class Flag : UInt32
		{
			kNone = 0,
			kHidden = 1 << 0,
			kSelectiveUpdate = 1 << 1,
			kSelectiveUpdateTransforms = 1 << 2,
			kSelectiveUpdateController = 1 << 3,
			kSelectiveUpdateRigid = 1 << 4,
			kDisplayObject = 1 << 5,
			kDisableSorting = 1 << 6,
			kSelectiveUpdateTransformsOverride = 1 << 7,
			kSaveExternalGeometryData = 1 << 9,
			kNoDecals = 1 << 10,
			kAlwaysDraw = 1 << 11,
			kMeshLOD = 1 << 12,
			kFixedBound = 1 << 13,
			kTopFadeNode = 1 << 14,
			kIgnoreFade = 1 << 15,
			kNoAnimSyncX = 1 << 16,
			kNoAnimSyncY = 1 << 17,
			kNoAnimSyncZ = 1 << 18,
			kNoAnimSyncS = 1 << 19,
			kNoDismember = 1 << 20,
			kNoDismemberValidity = 1 << 21,
			kRenderUse = 1 << 22,
			kMaterialsApplied = 1 << 23,
			kHighDetail = 1 << 24,
			kForceUpdate = 1 << 25,
			kPreProcessedNode = 1 << 26
		};


		enum class ALPHA_MODE : UInt8
		{
			kAll = 0,
			kSkin
		};


		virtual ~NiAVObject();	// 00

		// override (NiObjectNET)
		virtual const NiRTTI* GetRTTI() const override;							   // 02
		virtual void		  LoadBinary(NiStream& a_stream) override;			   // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			   // 19
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	   // 1A
		virtual void		  SaveBinary(NiStream& a_stream) override;			   // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;				   // 1C
		virtual void		  ProcessClone(NiCloningProcess& a_cloning) override;  // 1D

		// add
		virtual void		UpdateControllers(NiUpdateData& a_data);  // 25
		virtual void		Unk_VRFunc(void); 
		virtual void		PerformOp(PerformOpFunc& a_func);																	// 26
		virtual void		AttachProperty(NiAlphaProperty* a_property);														// 27 - { return; }
		virtual void		SetMaterialNeedsUpdate(bool a_needsUpdate);															// 28 - { return; }
		virtual void		SetDefaultMaterialNeedsUpdateFlag(bool a_flag);														// 29 - { return; }
		virtual NiAVObject* GetObjectByName(const BSFixedString& a_name);														// 2A
		virtual void		SetSelectiveUpdateFlags(bool& a_selectiveUpdate, bool a_selectiveUpdateTransforms, bool& a_rigid);	// 2B
		virtual void		UpdateDownwardPass(NiUpdateData& a_data, UInt32 a_arg2);											// 2C
		virtual void		UpdateSelectedDownwardPass(NiUpdateData& a_data, UInt32 a_arg2);									// 2D
		virtual void		UpdateRigidDownwardPass(NiUpdateData& a_data, UInt32 a_arg2);										// 2E
		virtual void		UpdateWorldBound();																					// 2F - { return; }
		virtual void		UpdateWorldData(NiUpdateData* a_data);																// 30
		virtual void		UpdateTransformAndBounds(NiUpdateData& a_data);														// 31
		virtual void		PreAttachUpdate(NiNode* a_parent, NiUpdateData& a_data);											// 32
		virtual void		PostAttachUpdate();																					// 33
		virtual void		OnVisible(NiCullingProcess& a_process);																// 34 - { return; }

		bool		   GetAppCulled() const;
		BSGeometry*	   GetFirstGeometryOfShaderType(BSShaderMaterial::Feature a_type);
		TESObjectREFR* GetUserData() const;
		bool		   HasShaderType(BSShaderMaterial::Feature a_type);
		void		   SetAppCulled(bool a_cull);
		bool		   SetMotionType(UInt32 a_motionType, bool a_arg2 = true, bool a_arg3 = false, bool a_allowActivate = true);
		void		   SetRigidConstraints(bool a_enable, UInt8 a_arg2 = 1, UInt32 a_arg3 = 1);
		void		   TintScenegraph(const NiColorA& a_color);
		void		   Update(NiUpdateData& a_data);
		void		   UpdateBodyTint(const NiColor& a_color);
		void		   UpdateHairColor(const NiColor& a_color);
		void		   UpdateMaterialAlpha(float a_alpha, bool a_onlySkin);
		void		   ToggleNode(bool a_hide);
		void		   UpdateRigidBodySettings(UInt32 a_type, UInt32 a_arg2);

		BSLightingShaderProperty* temp_nicast(BSGeometry* a_geometry);

		// members
		NiNode*						 parent;		   // 030
		UInt32						 parentIndex;	   // 038
		UInt32						 unk03C;		   // 03C
		NiPointer<NiCollisionObject> collisionObject;  // 040
		NiTransform					 local;			   // 048
		NiTransform					 world;			   // 07C
		NiTransform					 previousWorld;	   // 0B0
		NiBound						 worldBound;	   // 0E4
		float						 unkF4;			   // 0F4
		float						 unkF8;			   // 0F8
		float						 unkFC;			   // 0FC
		float						 unk100;		   // 100
		float						 unk104;		   // 104
		float						 unk108;		   // 108
		Flag						 flagsVR;		   // 10C
		TESObjectREFR*				 userData;		   // 110
		float						 unk118;		   // 118
		UInt32						 unk11C;		   // 11C
		UInt8						 unk120[8];		   // 120 - bitfield
		UInt64						 unk128;		   // 128
		UInt32						 unk130;		   // 130
		UInt32						 unk134;		   // 134
	};
	STATIC_ASSERT(sizeof(NiAVObject) == 0x138);
}
