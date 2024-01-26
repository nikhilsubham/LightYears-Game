#include <gameFramwork/GameApplication.h>
#include <framwork/World.h>
#include<framwork/Actor.h>


ly::Application* GetApplication()
{
	return new ly::GameApplication();
}

namespace ly
{
	class World;
	GameApplication::GameApplication()
	{
		weak<World> newWorld = LoadWorld<World>();
		newWorld.lock()->SpawnActor<Actor>();
		newWorld.lock()->SpawnActor<Actor>(); 
		newWorld.lock()->SpawnActor<Actor>();
		newWorld.lock()->SpawnActor<Actor>();
	}
}