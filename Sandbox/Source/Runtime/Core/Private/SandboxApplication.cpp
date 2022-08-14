#include <iostream>
#include <thread>
#include <chrono>

#include <ServiceLocator.h>

#include "SandboxApplication.h"

CFT::Application* CFT::CreateApplication()
{
	return new SandboxApplication();
}

class BaseService : public CFT::IService
{
public:
	virtual void DoThing() { }
};

class Service : public BaseService
{
public:
	virtual void DoThing() override { std::cout << "Doing the thing!" << std::endl; }
};

void SandboxApplication::Run()
{
	for (int Index{ 0 }; Index < 3; ++Index)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << ".";
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << " CFT Engine is running!" << std::endl;

	CFT::ServiceLocator LocalServiceLocator;
	LocalServiceLocator.ProvideService<BaseService>(new Service());

	CFT::TServiceProvider<BaseService> BaseServiceProvider{ LocalServiceLocator.LocateService<BaseService>() };

	while (true)
	{
		BaseServiceProvider->DoThing();
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
