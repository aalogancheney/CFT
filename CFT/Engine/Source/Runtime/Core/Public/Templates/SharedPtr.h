#pragma once

#include <memory>

template<typename T>
using SharedPtr = std::shared_ptr<T>;

template<typename T, typename U>
FORCE_INLINE SharedPtr<T> SharedPtrCast(SharedPtr<U> Other) { return std::static_pointer_cast<T>(Other); }
