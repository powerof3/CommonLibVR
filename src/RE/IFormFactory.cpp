#include "RE/IFormFactory.h"

#include "REL/Relocation.h"


namespace RE
{
	std::pair<IFormFactory**, bool> IFormFactory::GetFormFactories()
	{
		struct Factories
		{
			IFormFactory* data[to_underlying(FormType::Max)];
		};

		REL::Offset<Factories*> formFactories = 0x1F88B40;
		REL::Offset<bool*> formFactoriesInitialized = 0x1F88B13;
		return std::make_pair(formFactories->data, *formFactoriesInitialized);
	}


	IFormFactory* IFormFactory::GetFormFactoryByType(FormType a_formType)
	{
		auto formFactories = GetFormFactories();
		return formFactories.second ? formFactories.first[static_cast<UInt32>(a_formType)] : nullptr;
	}


	TESForm* IFormFactory::Create()
	{
		return CreateImpl();
	}
}
