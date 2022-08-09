#pragma once

#include "CoreMacros.h"

CFT_BEGIN

/**
 * Uncopyable should be used as a base class for inheritance to prevent
 * the derived class from being copied.
 */
class CFT_API Uncopyable
{
private:
	// Prevent copy constructing and copy assignment.
	Uncopyable(const Uncopyable&) = delete;
	Uncopyable& operator=(const Uncopyable&) = delete;

protected:
	// Ensure derived classes can be constructed, and that derived
	// classes don't support polymorphism.
	Uncopyable() = default;
	~Uncopyable() = default;
};

CFT_END
