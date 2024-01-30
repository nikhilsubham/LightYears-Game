#pragma once
#include<framwork/Actor.h>

namespace ly
{
	class Spaceship : public Actor
	{
	public:
		Spaceship(World*owningWorld, const std::string& texturePath ="");
		virtual void Tick(float delataTime) override;
		void SetVelocity(const sf::Vector2f& newVel);
		sf::Vector2f GetVelocity() const { return mVelocity; };
		virtual void Shoot();

	private:
		sf::Vector2f mVelocity;
	};
}

