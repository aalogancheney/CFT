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
		#define CFT_EXTERN
	#else
		#define CFT_API __declspec(dllimport)
		#define CFT_EXTERN extern
	#endif
#endif

#define INLINE __inline
#define FORCE_INLINE __forceinline
#define NO_DISCARD [[nodiscard]]
