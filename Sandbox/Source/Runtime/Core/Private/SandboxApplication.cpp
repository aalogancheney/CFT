#include <iostream>
#include <thread>
#include <chrono>

#include "../Public/SandboxApplication.h"

CFT::Application* CFT::CreateApplication()
{
	return new SandboxApplication();
}

void SandboxApplication::Run()
{
	for (int Index{ 0 }; Index < 6; ++Index)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << ".";
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << " CFT Engine is running!" << std::endl;

	while (true);
}
