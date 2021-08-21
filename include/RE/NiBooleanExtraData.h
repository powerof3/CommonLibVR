#pragma once

#include "RE/NiExtraData.h"


namespace RE
{
	class NiBooleanExtraData : public NiExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiBooleanExtraData;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiBooleanExtraData;


		virtual ~NiBooleanExtraData();	// 00

		// override (NiExtraData)
		virtual const NiRTTI* GetRTTI() const override;							  // 02
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;  // 17
		virtual void		  LoadBinary(NiStream& a_stream) override;			  // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			  // 19 - { NiExtraData::LinkObject(a_stream); }
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	  // 1A - { return NiExtraData::RegisterStreamables(a_stream); }
		virtual void		  SaveBinary(NiStream& a_stream) override;			  // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;				  // 1C

		static NiBooleanExtraData* Create(const BSFixedString& a_name, bool a_value);


		// members
		bool data;	// 18
	};
	STATIC_ASSERT(sizeof(NiBooleanExtraData) == 0x20);
}