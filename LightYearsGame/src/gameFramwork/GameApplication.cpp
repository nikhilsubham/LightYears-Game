#include <gameFramwork/GameApplication.h>
#include <framwork/World.h>
#include <framwork/Actor.h>
#include "config.h"


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
		actorToDestroy.lock()->setTexture(GetResourceDir() + "SpaceShooterRedux\\PNG\\playerShip1_blue.png");
		actorToDestroy.lock()->SetActorLocation(sf::Vector2f(325.f, 450.f));
		actorToDestroy.lock()->SetActorRotation(-90.f);
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