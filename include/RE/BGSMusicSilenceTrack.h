#pragma once

#include "RE/BGSMusicTrack.h"


namespace RE
{
	class BGSMusicSilenceTrack : public BGSMusicTrack
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMusicSilenceTrack;


		virtual ~BGSMusicSilenceTrack();  // 00

		// override (BGSMusicTrack)
		virtual void	  DoUpdate(void) override;						 // 01
		virtual void	  DoPlay() override;							 // 02
		virtual void	  DoPause() override;							 // 03
		virtual void	  DoFinish(bool a_arg1, float a_arg2) override;	 // 04
		virtual float	  GetDurationImpl() const override;				 // 05 - { return duration; }
		virtual TrackType GetType() const override;						 // 06 - "BGSMusicSilenceTrack"
		virtual void	  Load(TESFile* a_mod) override;				 // 0C


		// members
		float  duration;   // 20 - FLTV
		UInt32 pad24;	   // 24
		UInt64 playTime;   // 28
		UInt64 pauseTime;  // 30
	};
	STATIC_ASSERT(sizeof(BGSMusicSilenceTrack) == 0x38);
}
