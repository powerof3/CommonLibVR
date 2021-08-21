#pragma once

#include "RE/FormTypes.h"
#include "RE/TESBoundAnimObject.h"


namespace RE
{
	class TESSound : public TESBoundAnimObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESSound;
		inline static constexpr auto FORMTYPE = FormType::Sound;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESSound();  // 00

		// override (TESBoundAnimObject)
		virtual void		InitializeData() override;					  // 04
		virtual bool		Load(TESFile* a_mod) override;				  // 06
		virtual void		InitItemImpl() override;					  // 13
		virtual bool		SetFormEditorID(const char* a_str) override;  // 33
		virtual void		UnClone3D(TESObjectREFR* a_ref) override;	  // 41
		virtual NiAVObject* Clone3D(TESObjectREFR* a_ref) override;		  // 4A - { return 0; }


		// members
		BGSSoundDescriptorForm* descriptor;	 // 30 - SDSC
	};
	STATIC_ASSERT(sizeof(TESSound) == 0x38);
}
