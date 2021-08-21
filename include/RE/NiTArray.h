#pragma once

#include <cassert>

#include "RE/MemoryManager.h"
#include "RE/NiTCollection.h"


namespace RE
{
	template <class T, class Allocator>
	class NiTArray
	{
	public:
		using value_type = T;
		using allocator_type = Allocator;
		using size_type = UInt16;
		using reference = value_type&;
		using const_reference = const value_type&;
		using iterator = T*;
		using const_iterator = const T*;


		NiTArray(UInt32 a_maxSize = 0, UInt32 a_growBy = 1) :
			_data(0),
			_capacity(static_cast<UInt16>(a_maxSize)),
			_freeIdx(0),
			_size(0),
			_growthSize(static_cast<UInt16>(a_growBy))
		{
			if (_capacity > 0) {
				_data = allocator_type::Allocate(_capacity);
			}
		}


		virtual ~NiTArray()	 // 00
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
		// members
		T*	   _data;		 // 08
		UInt16 _capacity;	 // 10
		UInt16 _freeIdx;	 // 12
		UInt16 _size;		 // 14
		UInt16 _growthSize;	 // 16
	};
	STATIC_ASSERT(sizeof(NiTArray<void*, NiTMallocInterface<void*>>) == 0x18);


	template <class T>
	class NiTObjectArray : public NiTArray<T, NiTNewInterface<T>>
	{
	public:
		NiTObjectArray(UInt32 a_maxSize = 0, UInt32 a_growBy = 1) :
			NiTArray<T, NiTNewInterface<T>>(a_maxSize, a_growBy)
		{}
	};
	STATIC_ASSERT(sizeof(NiTObjectArray<void*>) == 0x18);


	template <class T>
	class NiTPrimitiveArray : public NiTArray<T, NiTMallocInterface<T>>
	{
	public:
		NiTPrimitiveArray(UInt32 a_maxSize = 0, UInt32 a_growBy = 1) :
			NiTArray<T, NiTMallocInterface<T>>(a_maxSize, a_growBy)
		{}
	};
	STATIC_ASSERT(sizeof(NiTPrimitiveArray<void*>) == 0x18);


	template <class T, class Allocator>
	class NiTLargeArray
	{
	public:
		using value_type = T;
		using allocator_type = Allocator;
		using size_type = UInt32;
		using reference = value_type&;
		using const_reference = const value_type&;
		using iterator = T*;
		using const_iterator = const T*;


		NiTLargeArray(UInt32 a_maxSize = 0, UInt32 a_growBy = 1) :
			_data(0),
			_capacity(a_maxSize),
			_freeIdx(0),
			_size(0),
			_growthSize(a_growBy)
		{
			if (_capacity > 0) {
				_data = allocator_type::Allocate(_capacity);
			}
		}


		virtual ~NiTLargeArray()  // 00
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
		// members
		T*	   _data;		 // 08
		UInt32 _capacity;	 // 10
		UInt32 _freeIdx;	 // 14
		UInt32 _size;		 // 18
		UInt32 _growthSize;	 // 1C
	};
	STATIC_ASSERT(sizeof(NiTLargeArray<void*, NiTMallocInterface<void*>>) == 0x20);


	template <class T>
	class NiTLargeObjectArray : public NiTLargeArray<T, NiTNewInterface<T>>
	{
	public:
		NiTLargeObjectArray(UInt32 a_maxSize = 0, UInt32 a_growBy = 1) :
			NiTLargeArray<T, NiTNewInterface<T>>(a_maxSize, a_growBy)
		{}
	};
	STATIC_ASSERT(sizeof(NiTLargeObjectArray<void*>) == 0x20);


	template <class T>
	class NiTLargePrimitiveArray : public NiTLargeArray<T, NiTMallocInterface<T>>
	{
	public:
		NiTLargePrimitiveArray(UInt32 a_maxSize = 0, UInt32 a_growBy = 1) :
			NiTLargeArray<T, NiTMallocInterface<T>>(a_maxSize, a_growBy)
		{}
	};
	STATIC_ASSERT(sizeof(NiTLargePrimitiveArray<void*>) == 0x20);


	class TESForm;
	class NiFormArray : public NiTLargePrimitiveArray<TESForm*>
	{
	public:
	};
	STATIC_ASSERT(sizeof(NiFormArray) == 0x20);
}
