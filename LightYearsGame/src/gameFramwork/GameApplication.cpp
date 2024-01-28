#include <gameFramwork/GameApplication.h>
#include <framwork/World.h>
#include <framwork/Actor.h>
#include "config.h"
#include "spaceship/Spaceship.h"


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
		testPlayerSpceship = newWorld.lock()->SpawnActor<Spaceship>();
		testPlayerSpceship.lock()->setTexture(GetResourceDir() + "SpaceShooterRedux\\PNG\\playerShip1_blue.png");
		testPlayerSpceship.lock()->SetActorLocation(sf::Vector2f(325.f, 450.f));
		testPlayerSpceship.lock()->SetActorRotation(360.f);
		testPlayerSpceship.lock()->SetVelocity(sf::Vector2f(0.f, -200.f));
		counter = 0;
	}

	void GameApplication::Tick(float deltaTime)
	{
		
	}
}