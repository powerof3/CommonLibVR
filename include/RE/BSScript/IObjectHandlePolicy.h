#pragma once

#include "RE/FormTypes.h"


namespace RE
{
	class BSFixedString;
	class TESForm;


	namespace BSScript
	{
		struct IObjectHandlePolicy
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSScript__IObjectHandlePolicy;


			virtual ~IObjectHandlePolicy();	 // 00

			// add
			virtual bool	 HandleIsType(VMTypeID a_typeID, VMHandle a_handle) const = 0;				   // 01
			virtual bool	 IsHandleObjectAvailable(VMHandle a_handle) const = 0;						   // 02
			virtual VMHandle EmptyHandle() const = 0;													   // 03
			virtual VMHandle GetHandleForObject(VMTypeID a_typeID, const void* a_srcData) const = 0;	   // 04
			virtual bool	 HasParent(VMHandle a_handle) const = 0;									   // 05
			virtual VMHandle GetParentHandle(VMHandle a_handle) const = 0;								   // 06
			virtual VMHandle GetHandleScriptsMovedFrom(VMHandle a_handle) const = 0;					   // 07
			virtual void*	 GetObjectForHandle(VMTypeID a_typeID, VMHandle a_handle) const = 0;		   // 08
			virtual void	 PersistHandle(VMHandle a_handle) = 0;										   // 09
			virtual void	 ReleaseHandle(VMHandle a_handle) = 0;										   // 0A
			virtual void	 ConvertHandleToString(VMHandle a_handle, BSFixedString& a_strOut) const = 0;  // 0B

			bool	 HandleIsType(FormType a_typeID, VMHandle a_handle);
			VMHandle GetHandleForObject(FormType a_typeID, const TESForm* a_srcData);
			TESForm* GetObjectForHandle(FormType a_typeID, VMHandle a_handle);
		};
		STATIC_ASSERT(sizeof(IObjectHandlePolicy) == 0x8);
	}
}
