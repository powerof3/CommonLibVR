#pragma once

#include <type_traits>

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"
#include "RE/FormTypes.h"


namespace RE
{
	enum class LOCK_LEVEL : UInt32
	{
		kUnlocked = static_cast<std::underlying_type_t<LOCK_LEVEL>>(-1),
		kVeryEasy = 0,
		kEasy = 1,
		kAverage = 2,
		kHard = 3,
		kVeryHard = 4,
		kRequiresKey = 5
	};


	struct REFR_LOCK
	{
		enum class Flag : UInt8
		{
			kNone = 0,
			kLocked = 1 << 0,
			kLeveled = 1 << 2
		};


		LOCK_LEVEL GetLockLevel(const TESObjectREFR* a_containerRef) const;
		void	   SetLocked(bool a_locked);


		// members
		SInt8	baseLevel;	// 00
		UInt8	pad01;		// 01
		UInt16	pad02;		// 02
		UInt32	pad04;		// 04
		TESKey* key;		// 08
		Flag	flags;		// 10
		UInt8	pad11;		// 11
		UInt16	pad12;		// 12
		UInt32	numTries;	// 14
		UInt32	unk18;		// 18
		UInt32	pad1C;		// 1C
	};
	STATIC_ASSERT(sizeof(REFR_LOCK) == 0x20);


	class ExtraLock : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraLock;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kLock;


		virtual ~ExtraLock();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kLock; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		REFR_LOCK* lock;  // 10
	};
	STATIC_ASSERT(sizeof(ExtraLock) == 0x18);
}
