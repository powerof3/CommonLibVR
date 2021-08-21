#pragma once

#include "RE/BSFixedString.h"
#include "RE/NiObject.h"


namespace RE
{
	class NiExtraData : public NiObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiExtraData;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiExtraData;


		virtual ~NiExtraData();	 // 00

		// override (NiObject)
		virtual const NiRTTI* GetRTTI() const override;							 // 02
		virtual void		  LoadBinary(NiStream& a_stream) override;			 // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			 // 19 - { return; }
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	 // 1A
		virtual void		  SaveBinary(NiStream& a_stream) override;			 // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;				 // 1C

		// add
		virtual bool IsStreamable() const;	// 25 - { return true; }
		virtual bool IsCloneable() const;	// 26 - { return true; }

		static NiExtraData* Create(std::size_t a_size, std::uintptr_t a_vtbl);
		template <class T>
		static T* Create(std::uintptr_t a_vtbl);

		const BSFixedString& GetName() const;
		void				 SetName(const BSFixedString& a_name);


		// members
		BSFixedString name;	 // 10
	};
	STATIC_ASSERT(sizeof(NiExtraData) == 0x18);


	template <class T>
	T* NiExtraData::Create(std::uintptr_t a_vtbl)
	{
		void* memory = malloc(sizeof(T));
		std::memset(memory, 0, sizeof(T));
		T* xData = (T*)memory;
		((std::uintptr_t*)memory)[0] = a_vtbl;
		return xData;
	}
}
