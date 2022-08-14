#pragma once

#include "CoreMacros.h"

CFT_BEGIN

struct DefaultPlatformTypes
{
	using uint8 = unsigned char;
	using uint16 = unsigned short int;
	using uint32 = unsigned int;
	using uint64 = unsigned long long;

	using int8 = signed char;
	using int16 = signed short int;
	using int32 = signed;
	using int64 = signed long long;
};

CFT_END
