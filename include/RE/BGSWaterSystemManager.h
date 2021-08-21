#pragma once

#include "RE/BSAtomic.h"
#include "RE/BSFixedString.h"
#include "RE/BSPointerHandle.h"
#include "RE/BSTArray.h"
#include "RE/BSTSingleton.h"
#include "RE/NiPoint2.h"
#include "RE/NiPoint3.h"
#include "RE/NiSmartPointer.h"
#include "RE/NiTPointerMap.h"


namespace RE
{
	class BSTriShape;
	class NiNode;
	class TESObjectCELL;
	class TESWorldSpace;
	class WadingWaterData;
	class TESWaterObject;


	class BGSWaterSystemManager : public BSTSingletonSDM<BGSWaterSystemManager>
	{
	public:
		static BGSWaterSystemManager* GetSingleton();

		void CreateBulletWaterDisplacement(const RE::NiPoint3& a_pos, float a_scale);


		// members
		UInt32										 pad00;					   // 000
		BSFixedString*								 type;					   // 008
		UInt32										 unk10;					   // 010
		UInt32										 pad014;				   // 014
		UInt32										 unk18;					   // 018
		UInt32										 unk1C;					   // 01C
		BSTArray<TESWaterObject*>					 waterObjects;			   // 020
		BSTArray<void*>								 unk038;				   // 038 - TESWaterReflection
		BSTArray<void*>								 unk050;				   // 050
		BSTArray<void*>								 unk068;				   // 068
		UInt32										 unk080;				   // 080
		NiPoint2									 unk084;				   // 084
		UInt32										 pad08C;				   // 08C
		NiPointer<NiNode>							 proceduralWaterNode;	   // 090
		UInt64										 unk098;				   // 098
		UInt32										 reflectionExteriorCount;  // 0A0
		UInt32										 reflectionInteriorCount;  // 0A4
		TESWorldSpace*								 worldSpace;			   // 0A8
		bool										 state;					   // 0B0
		UInt8										 pad0B1;				   // 0B1
		UInt16										 pad0B2;				   // 0B2
		UInt32										 unk0B4;				   // 0B4
		UInt8										 unk0B8;				   // 0B8
		UInt8										 pad0B9;				   // 0B9
		SInt8										 unk0BA;				   // 0BA
		UInt8										 pad0BB;				   // 0BB
		UInt32										 unk0BC;				   // 0BC
		float										 pad0C0;				   // 0C0
		bool										 waterRadiusState;		   // 0C4
		UInt8										 pad0C5;				   // 0C5
		UInt8										 unk0C6;				   // 0C6
		bool										 showProcedualWater;	   // 0C7
		UInt8										 unk0C8;				   // 0C8
		UInt8										 padC9;					   // 0C9
		UInt16										 padCA;					   // 0CA
		UInt32										 unk0CC;				   // 0CC
		UInt32										 unk0D0;				   // 0D0
		float										 unk0D4;				   // 0D4
		NiTPointerMap<ActorHandle, WadingWaterData*> wadingWaterData;		   // 0D8
		UInt64										 unk0F8;				   // 0F8
		UInt64										 unk100;				   // 108
		UInt32										 unk108;				   // 108
		UInt32										 pad10C;				   // 10C
		UInt8										 unk110;				   // 110
		UInt8										 pad111;				   // 111
		UInt16										 pad112;				   // 112
		UInt32										 pad114;				   // 114
		TESObjectCELL*								 unk118;				   // 118
		mutable BSSpinLock							 lock;					   // 120
		NiPointer<BSTriShape>						 waterShape;			   // 128
	};
	static_assert(sizeof(BGSWaterSystemManager) == 0x130);
};