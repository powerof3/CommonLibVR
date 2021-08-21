#pragma once

#include "RE/NiExtraData.h"

#include <optional>


namespace RE
{
	class NiStringsExtraData : public NiExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiStringsExtraData;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiStringsExtraData;


		virtual ~NiStringsExtraData();	// 00

		// override (NiExtraData)
		virtual const NiRTTI* GetRTTI() const override;							  // 02
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;  // 17
		virtual void		  LoadBinary(NiStream& a_stream) override;			  // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			  // 19 - { NiExtraData::LinkObject(a_stream); }
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	  // 1A - { return NiExtraData::RegisterStreamables(a_stream); }
		virtual void		  SaveBinary(NiStream& a_stream) override;			  // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;				  // 1C

		static NiStringsExtraData* Create(const BSFixedString& a_name, const std::vector<BSFixedString>& a_strings);

		std::optional<UInt32> GetIndex(const BSFixedString& a_element) const;
		bool						 Insert(const BSFixedString& a_element);
		bool						 Remove(const BSFixedString& a_element);


		// members
		UInt32 size;   // 18
		UInt32 pad1C;  // 1C
		char** value;  // 20
	};
	STATIC_ASSERT(sizeof(NiStringsExtraData) == 0x28);
}
