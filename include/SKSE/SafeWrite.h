#pragma once

#include <nonstd/span.hpp>


namespace SKSE
{
	bool SafeWriteBuf(std::uintptr_t a_dst, const void* a_src, std::size_t a_count);
	bool SafeWrite8(std::uintptr_t a_dst, UInt8 a_data);
	bool SafeWrite16(std::uintptr_t a_dst, UInt16 a_data);
	bool SafeWrite32(std::uintptr_t a_dst, UInt32 a_data);
	bool SafeWrite64(std::uintptr_t a_dst, UInt64 a_data);

	inline void safe_write(std::uintptr_t a_dst, const void* a_src, std::size_t a_count)
	{
		DWORD				  old{ 0 };
		[[maybe_unused]] BOOL success{ false };
		success = VirtualProtect(reinterpret_cast<void*>(a_dst), a_count, PAGE_EXECUTE_READWRITE, std::addressof(old));
		if (success != 0) {
			std::memcpy(reinterpret_cast<void*>(a_dst), a_src, a_count);
			success = VirtualProtect(reinterpret_cast<void*>(a_dst), a_count, old, std::addressof(old));
		}

		assert(success != 0);
	}


	template <class T>
	inline void safe_write(std::uintptr_t a_dst, const T& a_data)
	{
		safe_write(a_dst, std::addressof(a_data), sizeof(T));
	}


	template <class T>
	inline void safe_write(std::uintptr_t a_dst, nonstd::span<T> a_data)
	{
		safe_write(a_dst, a_data.data(), a_data.size_bytes());
	}
}
