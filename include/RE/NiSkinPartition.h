#pragma once

#include "RE/MemoryManager.h"
#include "RE/NiGeometryData.h"
#include "RE/NiObject.h"


namespace RE
{
	struct ID3D11Buffer;


	class NiSkinPartition : public NiObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiSkinPartition;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiSkinPartition;


		struct Vertex
		{
			enum class Flags : UInt16
			{
				kVertex = 1 << 0,
				kUV = 1 << 1,
				kUV_2 = 1 << 2,
				kNormal = 1 << 3,
				kTangent = 1 << 4,
				kColors = 1 << 5,
				kSkinned = 1 << 6,
				kLandData = 1 << 7,
				kEyeData = 1 << 8,
				kFullPrec = 1 << 10
			};


			enum class Masks : UInt64
			{
				kVERT = 0xFFFFFFFFFFFFFFF0LL,
				kUVS = 0xFFFFFFFFFFFFFF0FLL,
				kNBT = 0xFFFFFFFFFFFFF0FFLL,
				kSKCOL = 0xFFFFFFFFFFFF0FFFLL,
				kDATA = 0xFFFFFFFFFFF0FFFFLL,
				kOFFSET = 0xFFFFFF0000000000LL,
				kFLAGS = ~(kOFFSET)
			};
		};


		struct TriShape
		{
			ID3D11Buffer*	vertexBuffer;	// 00
			ID3D11Buffer*	indexBuffer;	// 08
			UInt64			vertexDesc;		// 10
			volatile UInt32 refCount;		// 18
			UInt32			pad1C;			// 1C
			UInt8*			rawVertexData;	// 20
			UInt16*			rawIndexData;	// 28
		};
		STATIC_ASSERT(sizeof(TriShape) == 0x30);


		class Partition
		{
		public:
			UInt64	  vertexDesc;	   // 00
			UInt16*	  bones;		   // 08
			float*	  weights;		   // 10
			UInt16*	  vertexMap;	   // 18
			UInt8*	  bonePalette;	   // 20
			UInt16*	  triList;		   // 28
			UInt16*	  stripLengths;	   // 30
			UInt16	  vertices;		   // 38
			UInt16	  triangles;	   // 3A
			UInt16	  numBones;		   // 3C
			UInt16	  strips;		   // 3E
			UInt16	  bonesPerVertex;  // 40
			UInt16	  pad42;		   // 42
			float	  unk44;		   // 44
			TriShape* buffData;		   // 48
		};
		STATIC_ASSERT(sizeof(Partition) == 0x50);


		virtual ~NiSkinPartition();	 // 00

		// override (NiObject)
		virtual const NiRTTI* GetRTTI() const override;							 // 02
		virtual void		  LoadBinary(NiStream& a_stream) override;			 // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			 // 19 - { NiObject::LinkObject(a_stream); }
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	 // 1A - { return NiObject::RegisterStreamables(a_stream); }
		virtual void		  SaveBinary(NiStream& a_stream) override;			 // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;				 // 1C

		// add
		virtual void Unk_25(void);	// 25

		static Vertex::Flags GetVertexFlags(UInt64 vertexDesc)
		{
			return Vertex::Flags((vertexDesc & to_underlying(Vertex::Masks::kOFFSET)) >> 44);
		}


		// members
		UInt32				   numPartitions;  // 10
		UInt32				   pad14;		   // 14
		SimpleArray<Partition> partitions;	   // 18
		UInt64				   unk20;		   // 20
	};
	STATIC_ASSERT(sizeof(NiSkinPartition) == 0x28);
}
