#pragma once

#include <cstdint>
#include <unordered_map>

#include "../../Core/Public/CoreMacros.h"

CFT_BEGIN

template<typename T>
struct PointerHash
{
	inline size_t operator()(const T* InPointer) const
	{
		uintptr_t Address{ reinterpret_cast<uintptr_t>(InPointer) };
#if SIZE_MAX < UINTPTR_MAX
		Address %= SIZE_MAX;
#endif
		return Address;
	}
};

template<typename Key, typename Value>
using unordered_pointer_map = std::unordered_map<Key, Value, PointerHash<typename std::remove_pointer<Key>::type>>;

CFT_END
