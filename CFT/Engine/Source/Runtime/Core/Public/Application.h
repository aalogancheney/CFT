#pragma once

#include "CoreMacros.h"

CFT_BEGIN

class CFT_API Application
{
public:
	Application() = default;
	virtual ~Application() = default;

public:
	virtual void Run();
};

Application* CreateApplication();

CFT_END
