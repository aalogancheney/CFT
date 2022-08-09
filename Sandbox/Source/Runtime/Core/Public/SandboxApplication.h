#pragma once

#include <Runtime/CFT.h>

class SandboxApplication : public CFT::Application
{
public:
	virtual void Run() override;
};

CFT::Application* CFT::CreateApplication();
