#pragma once

#include "RE/NiTCollection.h"


namespace RE
{
	template <class T, class Allocator>
	class NiTSet
	{
	public:
		using value_type = T;
		using allocator_type = Allocator;
		using size_type = UInt32;
		using reference = value_type&;
		using const_reference = const value_type&;
		using iterator = T*;
		using const_iterator = const T*;


		NiTSet(UInt32 a_initialSize = 0) :
			_data(0),
			_capacity(a_initialSize),
			_size(0)
		{
			if (_capacity > 0) {
				_data = allocator_type::Allocate(_capacity);
			}
		}


		~NiTSet()
		{
			allocator_type::Deallocate(_data);
		}


		reference operator[](size_type a_pos)
		{
			assert(a_pos < size());
			return _data[a_pos];
		}


		const_reference operator[](size_type a_pos) const
		{
			assert(a_pos < size());
			return _data[a_pos];
		}


		reference front()
		{
			return operator[](0);
		}


		const_reference front() const
		{
			return operator[](0);
		}


		reference back()
		{
			return operator[](size() - 1);
		}


		const_reference back() const
		{
			return operator[](size() - 1);
		}


		iterator begin()
		{
			return _data;
		}


		const_iterator begin() const
		{
			return _data;
		}


		const_iterator cbegin() const
		{
			return _data;
		}


		iterator end()
		{
			return _data + _size;
		}


		const_iterator end() const
		{
			return _data + _size;
		}


		const_iterator cend() const
		{
			return _data + _size;
		}


		bool empty() const
		{
			return _capacity == 0;
		}


		size_type size() const
		{
			return _size;
		}


		size_type capacity() const
		{
			return _capacity;
		}

	private:
		T*	   _data;	   // 00
		UInt32 _capacity;  // 08
		UInt32 _size;	   // 0C
	};
	STATIC_ASSERT(sizeof(NiTSet<void*, NiTMallocInterface<void*>>) == 0x10);


	template <class T>
	class NiTObjectSet : public NiTSet<T, NiTNewInterface<T>>
	{
	public:
		NiTObjectSet(UInt32 a_initialSize = 0) :
			NiTSet<T, NiTNewInterface<T>>(a_initialSize)
		{}
	};
	STATIC_ASSERT(sizeof(NiTObjectSet<void*>) == 0x10);


	template <class T>
	class NiTPrimitiveSet : public NiTSet<T, NiTMallocInterface<T>>
	{
	public:
		NiTPrimitiveSet(UInt32 a_initialSize = 0) :
			NiTSet<T, NiTMallocInterface<T>>(a_initialSize)
		{}
	};
	STATIC_ASSERT(sizeof(NiTPrimitiveSet<void*>) == 0x10);
}
