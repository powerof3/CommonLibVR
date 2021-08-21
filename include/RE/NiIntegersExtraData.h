#pragma once

#include "RE/NiExtraData.h"


namespace RE
{
	class NiIntegersExtraData : public NiExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiIntegersExtraData;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiIntegersExtraData;


		virtual ~NiIntegersExtraData();	 // 00

		// override (NiExtraData)
		virtual const NiRTTI* GetRTTI() const override;							  // 02
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;  // 17
		virtual void		  LoadBinary(NiStream& a_stream) override;			  // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			  // 19 - { NiExtraData::LinkObject(a_stream); }
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	  // 1A - { return NiExtraData::RegisterStreamables(a_stream); }
		virtual void		  SaveBinary(NiStream& a_stream) override;			  // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;				  // 1C

		static NiIntegersExtraData* Create(const BSFixedString& a_name, const std::vector<SInt32>& a_integers);

		SInt32 GetIndexOf(SInt32 a_element) const;
		bool   InsertElement(SInt32 a_element);
		bool   RemoveElement(SInt32 a_element);


		// members
		UInt32	size;	// 18
		UInt32	pad;	// 1C
		SInt32* value;	// 20
	};
	STATIC_ASSERT(sizeof(NiIntegersExtraData) == 0x28);
}
