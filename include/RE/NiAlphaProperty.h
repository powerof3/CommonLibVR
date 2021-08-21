#pragma once

#include "RE/NiProperty.h"


namespace RE
{
	class NiAlphaProperty : public NiProperty
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiAlphaProperty;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiAlphaProperty;


		enum class AlphaFunction : UInt32
		{
			kOne = 0,
			kZero = 1,
			kSrcColor = 2,
			kInvSrcColor = 3,
			kDestColor = 4,
			kInvDestColor = 5,
			kSrcAlpha = 6,
			kInvSrcAlpha = 7,
			kDestAlpha = 8,
			kInvDestAlpha = 9,
			kSrcAlphaSat = 10
		};


		virtual ~NiAlphaProperty();	 // 00

		// override (NiProperty)
		virtual const NiRTTI* GetRTTI() const override;							  // 02
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;  // 17
		virtual void		  LoadBinary(NiStream& a_stream) override;			  // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			  // 19 - { NiProperty::LinkObject(a_stream); }
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	  // 1A - { return NiProperty::RegisterStreamables(a_stream); }
		virtual void		  SaveBinary(NiStream& a_stream) override;			  // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;				  // 1C
		virtual Type		  GetType() const override;							  // 25 - { return Type::kAlpha; }


		// members
		UInt64 unk30;  // 30
	};
	STATIC_ASSERT(sizeof(NiAlphaProperty) == 0x38);
}
