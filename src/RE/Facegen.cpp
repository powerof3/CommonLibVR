#include "RE/FaceGen.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	FaceGen* FaceGen::GetSingleton()
	{
		REL::Offset<FaceGen**> singleton(Offset::FaceGen::Singleton);
		return *singleton;
	}


	void FaceGen::RegenerateHead(BSFaceGenNiNode* a_headNode, BGSHeadPart* a_head, TESNPC* a_npc)
	{
		using func_t = decltype(&FaceGen::RegenerateHead);
		REL::Offset<func_t> func(Offset::FaceGen::RegenerateHead);
		return func(this, a_headNode, a_head, a_npc);
	}
}