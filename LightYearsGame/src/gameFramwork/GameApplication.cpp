#include <gameFramwork/GameApplication.h>
#include <framwork/World.h>
#include <framwork/Actor.h>
#include <framwork/AssetManager.h>
#include "config.h"
#include "player/PlayerSpaceship.h"


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
		AssetManager::get().SetAssetRootDirectory(GetResourceDir());
		std::weak_ptr<World> newWorld = LoadWorld<World>();
		testPlayerSpceship = newWorld.lock()->SpawnActor<PlayerSpaceship>();
		testPlayerSpceship.lock()->SetActorLocation(sf::Vector2f(325.f, 450.f));
		testPlayerSpceship.lock()->SetActorRotation(360.f);
		//testPlayerSpceship.lock()->SetVelocity(sf::Vector2f(0.f, -200.f));

		std::weak_ptr<Spaceship>  testSpceship = newWorld.lock()->SpawnActor<Spaceship>("SpaceShooterRedux\\PNG\\playerShip1_blue.png");
		//testSpceship.lock()->setTexture("SpaceShooterRedux\\PNG\\playerShip1_blue.png"); //Not needed as we can pass in constructor only
		testSpceship.lock()->SetActorLocation(sf::Vector2f(100.f, 50.f));
		counter = 0.f;
	}

	void GameApplication::Tick(float deltaTime)
	{
		counter += deltaTime;
		if (counter > 10.f)
		{
			if (!testPlayerSpceship.expired())
			{
				testPlayerSpceship.lock()->Destroy();
			}
		}
	}
}