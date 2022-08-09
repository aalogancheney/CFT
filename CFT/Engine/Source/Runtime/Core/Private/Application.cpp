#include "../Public/Application.h"

CFT_BEGIN

Application* CreateApplication()
{
	return new Application();
}

void Application::Run()
{
	while (true);
}

CFT_END
