#include <framwork/Actor.h>
#include "spaceship/Spaceship.h"


namespace ly
{
	Spaceship::Spaceship(World* owningWorld, const std::string& texturePath)
		:Actor{owningWorld, texturePath},
		mVelocity()
	{

	}
	
	void Spaceship::Tick(float delataTime)
	{
		Actor::Tick(delataTime);
		AddActorLocationOffset(GetVelocity() * delataTime);
	}

	void Spaceship::SetVelocity(const sf::Vector2f& newVel)
	{
		mVelocity = newVel;
	}
}