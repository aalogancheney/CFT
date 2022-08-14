#pragma once

#include "Core.h"

CFT_BEGIN

class IService;

class ServiceProvider
{
public:
	CFT_API ServiceProvider(class IService* InService);

public:
	CFT_API SharedPtr<class IService> GetService() const;
	CFT_API void ProvideService(class IService* InService);

	CFT_API int32 GetGeneration() const;

private:
	int32 Generation;
	SharedPtr<class IService> Service;
};

template<typename T>
class TServiceProvider
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
	int32 CachedGeneration;
	SharedPtr<T> CachedService;
	const ServiceProvider& Provider;
};

CFT_END
