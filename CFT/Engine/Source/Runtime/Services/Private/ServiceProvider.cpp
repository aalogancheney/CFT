#include "IService.h"
#include "ServiceProvider.h"

CFT_BEGIN

ServiceProvider::ServiceProvider(IService* InService)
	: Generation{ 0 }
	, Service{ InService }
{

}

SharedPtr<IService> ServiceProvider::GetService() const
{
	return Service;
}

int32 ServiceProvider::GetGeneration() const
{
	return Generation;
}

void ServiceProvider::ProvideService(IService* InService)
{
	Service.reset(InService);
	++Generation;
}

CFT_END