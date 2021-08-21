#pragma once


namespace RE
{
	class ImageSpaceEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_ImageSpaceEffect;


		virtual ~ImageSpaceEffect();  // 00

		// add
		virtual void Unk_01(void);	// 01
		virtual void Unk_02(void);	// 02 - { return; }
		virtual void Unk_03(void);	// 03 - { return; }
		virtual void Unk_04(void);	// 04 - { return; }
		virtual void Unk_05(void);	// 05 - { return; }
		virtual void Unk_06(void);	// 06
		virtual void Unk_07(void);	// 07 - { return 0; }
		virtual void Unk_08(void);	// 08 - { return 0; }
		virtual void Unk_09(void);	// 09 - { return 0; }


		// members
		UInt64 unk08;  // 08
		UInt64 unk10;  // 10
		UInt64 unk18;  // 18
		UInt64 unk20;  // 20
		UInt64 unk28;  // 28
		UInt64 unk30;  // 30
		UInt64 unk38;  // 38
		UInt64 unk40;  // 40
		UInt64 unk48;  // 48
		UInt64 unk50;  // 50
		UInt64 unk58;  // 58
		UInt64 unk60;  // 60
		UInt64 unk68;  // 68
		UInt64 unk70;  // 70
		UInt64 unk78;  // 78
		UInt64 unk80;  // 80
		UInt64 unk88;  // 88
	};
	STATIC_ASSERT(sizeof(ImageSpaceEffect) == 0x90);
}
