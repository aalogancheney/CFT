#pragma once

#include "CFT.h"

class SandboxApplication : public CFT::Application
{
public:
	virtual void Run() override;
};

CFT::Application* CFT::CreateApplication();
