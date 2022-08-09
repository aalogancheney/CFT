#pragma once

#include "Core/Public/CoreMacros.h"
#include <iostream>

#ifdef CFT_PLATFORM_WINDOWS

extern CFT_NAMESPACE Application* CFT_NAMESPACE CreateApplication();

int main(int argc, char** argv)
{
	auto Application = CFT_NAMESPACE CreateApplication();
	Application->Run();
	delete Application;
}

#endif
