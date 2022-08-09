#pragma once

#include <unordered_map>
#include <memory>

#include "CoreMacros.h"
#include "RTTI.h"
#include "IService.h"
#include "ServiceProvider.h"
#include "../../Utilities/Public/HashUtilities.h"

CFT_BEGIN

class CFT_API ServiceLocator
{
public:
	template<typename T>
	void ProvideService(T* Service)
	{
		const auto& Iterator{ Services.find(T::StaticType()) };
		if (Iterator != Services.end())
		{
			Iterator->second.GetService()->OnUnregister();
			Iterator->second.ProvideService(Service);
		}
		else
		{
			Services.emplace(T::StaticType(), ServiceProvider{ Service });
		}
		Service->OnRegister();
	}

	template<typename T>
	TServiceProvider<T> LocateService()
	{
		const auto& Iterator{ Services.find(T::StaticType()) };
		if (Iterator != Services.end())
		{
			return TServiceProvider<T>{ Iterator->second };
		}
		else
		{
			// TODO: Provide a NullService to prevent any null reference errors.
			Services.emplace(T::StaticType(), ServiceProvider{ nullptr });
			const auto& NewIterator = Services.find(T::StaticType());
			return TServiceProvider<T>{ NewIterator->second };
		}
	}

private:
	unordered_pointer_map<const TypeInfo*, ServiceProvider> Services;
};

CFT_END
