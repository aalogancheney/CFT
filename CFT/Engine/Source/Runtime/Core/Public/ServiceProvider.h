#pragma once

#include <memory>

#include "CoreMacros.h"
#include "IService.h"

CFT_BEGIN

class ServiceProvider
{
public:
	ServiceProvider(IService* InService)
		: Generation{ 0 }
		, Service{ InService }
	{

	}

public:
	FORCE_INLINE SharedPtr<IService> GetService() const { return Service; }

	FORCE_INLINE int GetGeneration() const { return Generation; }

	void ProvideService(IService* InService)
	{
		Service.reset(InService);
		++Generation;
	}

private:
	int Generation;
	SharedPtr<IService> Service;
};

template<typename T>
class CFT_API TServiceProvider
{
public:
	TServiceProvider(const ServiceProvider& InServiceProvider)
		: CachedGeneration{ -1 }
		, Provider{ InServiceProvider }
		, CachedService{ nullptr }
	{

	}

public:
	SharedPtr<T> operator->() { return GetService(); }

private:
	SharedPtr<T> GetService()
	{
		if (CachedGeneration != Provider.GetGeneration())
		{
			CachedService = Cast<T>(Provider.GetService());
			CachedGeneration = Provider.GetGeneration();
		}
		return CachedService;
	}

private:
	int CachedGeneration;
	SharedPtr<T> CachedService;
	const ServiceProvider& Provider;
};

CFT_END
