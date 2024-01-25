#include "EntryPoint.h"
#include "framwork/Application.h"

int main()
{
	ly::Application* app = GetApplication();
	app->Run();
	delete app;
}