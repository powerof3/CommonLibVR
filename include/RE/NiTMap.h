#pragma once

#include "RE/NiTDefaultAllocator.h"
#include "RE/NiTMapBase.h"


namespace RE
{
	template <class Key, class T>
	class NiTMap : public NiTMapBase<NiTDefaultAllocator<NiTMapItem<Key, T>>, Key, T>
	{
	private:
		using Base = NiTMapBase<NiTDefaultAllocator<NiTMapItem<Key, T>>, Key, T>;

	public:
		using key_type = typename Base::key_type;
		using mapped_type = typename Base::mapped_type;
		using value_type = typename Base::value_type;
		using size_type = typename Base::size_type;


		NiTMap(UInt32 a_hashSize = 37) :
			Base(a_hashSize)
		{}


		virtual ~NiTMap()  // 00
		{}

	protected:
		using Base::_allocator;


		// override (NiTMapBase)
		virtual value_type* malloc_value() override	 // 05
		{
			return static_cast<value_type*>(_allocator.Allocate());
		}


		virtual void free_value(value_type* a_value) override  // 06
		{
			if (a_value) {
				a_value->~value_type();
				_allocator.Deallocate(a_value);
			}
		}
	};
	STATIC_ASSERT(sizeof(NiTMap<void*, void*>) == 0x20);
}
