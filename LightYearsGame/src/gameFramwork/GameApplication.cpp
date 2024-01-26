#include <gameFramwork/GameApplication.h>
#include <framwork/World.h>


ly::Application* GetApplication()
{
	return new ly::GameApplication();
}

namespace ly
{
	class World;
	GameApplication::GameApplication()
	{
		LoadWorld<World>();
	}
}