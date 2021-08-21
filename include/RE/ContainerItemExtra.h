#pragma once


namespace RE
{
	class TESForm;
	class TESGlobal;


	struct ContainerItemExtra  // COED
	{
	public:
		union Conditional
		{
			Conditional();
			~Conditional() = default;

			TESGlobal*	 global;
			std::int32_t rank;
		};
		static_assert(sizeof(Conditional) == 0x8);

		ContainerItemExtra();
		~ContainerItemExtra() = default;

		TES_HEAP_REDEFINE_NEW();

		// members
		TESForm*	owner;		  // 00
		Conditional conditional;  // 08
		float		healthMult;	  // 10
		UInt32		pad14;		  // 14
	};
	STATIC_ASSERT(sizeof(ContainerItemExtra) == 0x18);
}
