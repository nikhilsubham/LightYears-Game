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
		:Application(650, 900, "Light Years", sf::Style::Titlebar | sf::Style::Close)
	{
		weak<World> newWorld = LoadWorld<World>();
		newWorld.lock()->SpawnActor<Actor>();
		actorToDestroy = newWorld.lock()->SpawnActor<Actor>();
		actorToDestroy.lock()->setTexture("D:\\Game_Development\\LightYears\\LightYearsGame\\assets\\assets\\SpaceShooterRedux\\PNG\\playerShip1_blue.png");
		counter = 0;
	}

	void GameApplication::Tick(float deltaTime)
	{
		counter +=  deltaTime;

		if (counter > 2.f)
		{
			if (!actorToDestroy.expired())
			{
				actorToDestroy.lock()->Destroy();
			}
		}
	}
}