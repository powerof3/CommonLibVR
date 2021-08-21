#include "RE/BGSKeyword.h"

#include "RE/ConcreteFormFactory.h"
#include "RE/IFormFactory.h"

namespace RE
{
	BGSKeyword* BGSKeyword::CreateKeyword(const BSFixedString& a_formEditorID)
	{
		auto factory = IFormFactory::GetConcreteFormFactoryByType<BGSKeyword>();
		auto keyword = factory->Create();
		keyword->formEditorID = a_formEditorID;
		return keyword;
	}
}
