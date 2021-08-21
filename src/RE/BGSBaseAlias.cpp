#include "RE/BGSBaseAlias.h"
#include "RE/BGSRefAlias.h"


namespace RE
{
	const BSFixedString& BGSBaseAlias::GetTypeString() const
	{
		return QType();
	}


	VMTypeID BGSBaseAlias::GetVMTypeID() const
	{
		const auto& TYPE = GetTypeString();
		if (TYPE == "Ref") {
			return BGSRefAlias::VMTYPEID;
		}
		return VMTYPEID;
	}

	bool BGSBaseAlias::IsEssential() const
	{
		return (flags & FLAGS::kEssential) == FLAGS::kEssential;
	}


	bool BGSBaseAlias::IsProtected() const
	{
		return (flags & FLAGS::kProtected) == FLAGS::kProtected;
	}
	

	bool BGSBaseAlias::IsQuestObject() const
	{
		return (flags & FLAGS::kQuestObject) == FLAGS::kQuestObject;
	}
}
