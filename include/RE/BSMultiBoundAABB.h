#pragma once

#include "RE/BSMultiBoundShape.h"
#include "RE/NiPoint3.h"


namespace RE
{
	class BSMultiBoundAABB : public BSMultiBoundShape
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSMultiBoundAABB;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSMultiBoundAABB;

		virtual ~BSMultiBoundAABB();  // 00

		// override (NiObject)
		virtual const NiRTTI* GetRTTI() const override;							  // 02
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;  // 17
		virtual void		  LoadBinary(NiStream& a_stream) override;			  // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			  // 19
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	  // 1A
		virtual void		  SaveBinary(NiStream& a_stream) override;			  // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;				  // 1C
		virtual UInt32		  GetType() override;								  // 25 - { return 1; }
		virtual float		  GetLength() override;								  // 26
		virtual bool		  Unk_27() override;								  // 27
		virtual void		  Unk_28() override;								  // 28
		virtual bool		  Unk_29() override;								  // 29
		virtual void		  Unk_2A() override;								  // 2A
		virtual void		  Unk_2B() override;								  // 2B
		virtual bool		  WithinPoint(const NiPoint3& a_pos) override;		  // 2C
		virtual void		  SetCenter(const NiPoint3& a_center) override;		  // 2D
		virtual void		  Unk_2E() override;								  // 2E

		// members
		UInt32	 pad18;	  // 18
		NiPoint3 center;  // 1C - world coordinates
		UInt32	 pad28;	  // 28
		NiPoint3 size;	  // 2C
		UInt32	 pad38;	  // 38
		UInt32	 pad3C;	  // 3C
	};
	static_assert(sizeof(BSMultiBoundAABB) == 0x40);
}
