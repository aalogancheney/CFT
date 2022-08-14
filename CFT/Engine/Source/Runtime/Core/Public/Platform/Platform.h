#pragma once

#if CFT_PLATFORM_WINDOWS
#include "Windows/WindowsPlatform.h"
#endif

// Make these types available at the global namespace.

using uint8 = CFT_NAMESPACE PlatformTypes::uint8;
using uint16 = CFT_NAMESPACE PlatformTypes::uint16;
using uint32 = CFT_NAMESPACE PlatformTypes::uint32;
using uint64 = CFT_NAMESPACE PlatformTypes::uint64;

using int8 = CFT_NAMESPACE PlatformTypes::int8;
using int16 = CFT_NAMESPACE PlatformTypes::int16;
using int32 = CFT_NAMESPACE PlatformTypes::int32;
using int64 = CFT_NAMESPACE PlatformTypes::int64;
