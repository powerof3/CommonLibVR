#pragma once


namespace RE
{
	class IPostAnimationChannelUpdateFunctor
	{
	public:
		inline static constexpr auto RTTI = RTTI_IPostAnimationChannelUpdateFunctor;


		virtual ~IPostAnimationChannelUpdateFunctor();	// 00

		// add
		virtual void Unk_01(void);	// 01
	};
	STATIC_ASSERT(sizeof(IPostAnimationChannelUpdateFunctor) == 0x8);
}
