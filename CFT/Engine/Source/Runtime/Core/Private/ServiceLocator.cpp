#include "../Public/ServiceLocator.h"

CFT_BEGIN

//template<typename T>
//void ServiceLocator::ProvideService(T* Service)
//{
//	const auto& Iterator{ Services.find(T::StaticType()) };
//	if (Iterator != Services.end())
//	{
//		Iterator->second->Service->OnUnregister();
//		Iterator->second->Service.reset(Service);
//	}
//	else
//	{
//		Services.emplace(T::StaticType(), ServiceProvider{ std::shared_ptr<IService>(Service) });
//	}
//	Service->OnRegister();
//}
//
//template<typename T>
//const ServiceProvider& ServiceLocator::LocateService() const
//{
//	const auto& Iterator{ Services.find(T::StaticType()) };
//	if (Iterator != Services.end())
//	{
//		return Iterator->second;
//	}
//}

CFT_END
