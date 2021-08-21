#pragma once

#include "RE/NiObjectNET.h"


namespace RE
{
	class NiProperty : public NiObjectNET
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiProperty;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiProperty;


		enum class Type : SInt32
		{
			kAlpha = 0,
			kShade = 1
		};


		virtual ~NiProperty();	// 00

		// override (NiObjectNET)
		virtual const NiRTTI* GetRTTI() const override;							   // 02
		virtual void		  LoadBinary(NiStream& a_stream) override;			   // 18 - { NiObjectNET::LoadBinary(a_stream); }
		virtual void		  LinkObject(NiStream& a_stream) override;			   // 19 - { NiObjectNET::LinkObject(a_stream); }
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	   // 1A - { return NiObjectNET::RegisterStreamables(a_stream); }
		virtual void		  SaveBinary(NiStream& a_stream) override;			   // 1B - { NiObjectNET::SaveBinary(a_stream); }
		virtual bool		  IsEqual(NiObject* a_object) override;				   // 1C - { return NiObjectNET::IsEqual(a_object); }
		virtual void		  ProcessClone(NiCloningProcess& a_cloning) override;  // 1D

		// add
		virtual Type GetType() const = 0;	// 25
		virtual void Update(float a_time);	// 26
	};
	STATIC_ASSERT(sizeof(NiProperty) == 0x30);
}
