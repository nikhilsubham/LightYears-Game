#pragma once
#include <SFML/System.hpp>
#include "weapon/Shooter.h"

namespace ly
{
	class BulletShooter : public Shooter
	{
	public:
		BulletShooter(Actor* owner);

		virtual bool IsOnCooldown() const override;
		//virtual void IncrementLevel(int amt = 1) override;

	private:
		virtual void ShootImpl() override;
		sf::Clock mCooldownClock;
		float mCooldownTime;
		std::string mBulletTexturePath;
	};
}
