#pragma once

#include <utility>

#include "RE/FormTypes.h"


namespace RE
{
	template <class T, FormType>
	class ConcreteFormFactory;


	enum class OBJECT_TYPE : UInt32
	{
	};


	enum class OBJECT_CATEGORY_TYPE : UInt32
	{
	};


	class IFormFactory
	{
	public:
		inline static constexpr auto RTTI = RTTI_IFormFactory;


		virtual ~IFormFactory();  // 00

	protected:
		// add
		virtual TESForm* CreateImpl() = 0;	// 01

	public:
		virtual const char*			 GetFormName() const = 0;	 // 02
		virtual FormType			 GetFormType() const = 0;	 // 03
		virtual const char*			 GetObjectName() const;		 // 04 - { return 0; }
		virtual OBJECT_TYPE			 GetObjectType() const;		 // 05 - { return 106; }
		virtual OBJECT_CATEGORY_TYPE GetObjectCategory() const;	 // 06 - { return 9; }

		static std::pair<IFormFactory**, bool> GetFormFactories();
		static IFormFactory*				   GetFormFactoryByType(FormType a_formType);

		template <class T>
		static ConcreteFormFactory<T, T::FORMTYPE>* GetConcreteFormFactoryByType();

		TESForm* Create();
	};
	STATIC_ASSERT(sizeof(IFormFactory) == 0x8);
}
