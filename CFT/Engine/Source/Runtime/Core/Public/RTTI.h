#pragma once

#include <cstdint>
#include <functional>
#include <memory>

#include "CoreMacros.h"

CFT_BEGIN

class CFT_API TypeInfo
{
public:
	TypeInfo(const TypeInfo* InSuper)
		: Super{ InSuper }
	{

	}

public:
	FORCE_INLINE bool IsExactly(const TypeInfo* Other) const { return this == Other; }
	FORCE_INLINE const TypeInfo* SuperType() const { return Super; }

private:
	const TypeInfo* Super;
};

template<typename Other, typename This>
bool IsA(SharedPtr<This> ptr)
{
	for (const TypeInfo* Type = ptr->GetType(); Type != nullptr; Type = Type->SuperType())
	{
		if (Type->IsExactly(Other::StaticType()))
		{
			return true;
		}
	}
	return false;
}

template<typename Other, typename This>
SharedPtr<Other> Cast(SharedPtr<This> ptr)
{
	if (IsA<Other>(ptr))
	{
		return SharedPtrCast<Other>(ptr);
	}
	return nullptr;
}

CFT_END

#define DECL_RTTI_BASE(d) \
private: \
	static const CFT_NAMESPACE TypeInfo sType; \
public: \
	FORCE_INLINE static const CFT_NAMESPACE TypeInfo* StaticType() { return &sType; } \
	FORCE_INLINE virtual const CFT_NAMESPACE TypeInfo* GetType() const { return &sType; } \
private: \

#define IMPL_RTTI_BASE(t) \
const CFT_NAMESPACE TypeInfo t::sType{ nullptr };
