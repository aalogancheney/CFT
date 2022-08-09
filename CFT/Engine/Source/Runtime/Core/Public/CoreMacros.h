#pragma once

#include <memory>
#include <functional>
#include <cstdint>

#define CFT_BEGIN namespace CFT {
#define CFT_END }

#define CFT_NAMESPACE CFT::

#ifdef CFT_PLATFORM_WINDOWS
	#ifdef CFT_BUILD_DLL
		#define CFT_API __declspec(dllexport)
	#else
		#define CFT_API __declspec(dllimport)
	#endif
#endif

#define INLINE __inline
#define FORCE_INLINE __forceinline

template<typename T>
using SharedPtr = std::shared_ptr<T>;

template<typename T, typename U>
FORCE_INLINE SharedPtr<T> SharedPtrCast(SharedPtr<U> Other) { return std::static_pointer_cast<T>(Other); }

