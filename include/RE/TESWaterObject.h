#pragma once

#include "RE/BSTArray.h"
#include "RE/NiPlane.h"
#include "RE/NiRefObject.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class BSTriShape;
	class NiAVObject;
	class TESWaterForm;
	class TESWaterDisplacement;
	class TESWaterNormals;
	class TESWaterReflections;
	class BSMultiBoundAABB;


	class TESWaterObject : public NiRefObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESWaterObject;

		virtual ~TESWaterObject();	// 00


		// members
		NiPlane							plane;		   // 10
		NiPointer<BSTriShape>			shape;		   // 20
		NiPointer<NiAVObject>			fadeNode;	   // 28
		TESWaterForm*					waterForm;	   // 30
		std::uint64_t					unk38;		   // 38
		NiPointer<TESWaterReflections>	reflections;   // 40
		NiPointer<TESWaterDisplacement> displacement;  // 48
		NiPointer<TESWaterNormals>		normals;	   // 50
		BSTArray<BSMultiBoundAABB*>		multiBounds;   // 58
		UInt8							flags;		   // 70
		UInt8							pad71;		   // 71
		UInt16							pad72;		   // 72
		UInt32							pad74;		   // 74
	};
	static_assert(sizeof(TESWaterObject) == 0x78);
}
