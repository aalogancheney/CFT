#pragma once

#include "CoreMacros.h"
#include "RTTI/RTTI.h"

CFT_BEGIN

class CFT_API IService
{
DECL_RTTI_BASE(IService)

public:
	virtual ~IService() = default;

public:
	virtual void OnRegister() { }
	virtual void OnUnregister() { }
};

CFT_END

// Use: DECL_SERVICE(SuperClass)
#define DECL_SERVICE(d,s) \
private: \
	using Super = s; \
	static const CFT_NAMESPACE TypeInfo sType; \
public: \
	FORCE_INLINE static const CFT_NAMESPACE TypeInfo* StaticType() { return &sType; } \
	FORCE_INLINE const CFT_NAMESPACE TypeInfo* GetType() const override { return &sType; } \
private: \

// Use: IMPL_SERVICE(SelfClass, SuperClass)
#define IMPL_SERVICE(d,s) \
const CFT_NAMESPACE TypeInfo d::sType(s::StaticType());
