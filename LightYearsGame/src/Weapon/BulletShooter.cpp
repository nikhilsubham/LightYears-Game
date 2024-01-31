#include"Weapon/BulletShooter.h"
#include "Weapon/Bullet.h"
#include <framwork/World.h>

namespace ly
{
	BulletShooter::BulletShooter(Actor* owner)
		:Shooter(owner),
		mCooldownClock(),
		mCooldownTime(0.15f)
	{

	}

	bool BulletShooter::IsOnCooldown() const
	{
		if (mCooldownClock.getElapsedTime().asSeconds() > mCooldownTime)
		{
			return false;
		}
		return true;
	}


	void BulletShooter::ShootImpl()
	{
		mCooldownClock.restart();
		std::weak_ptr<Bullet> newBullet = GetOwner()->GetWorld()->SpawnActor<Bullet>(GetOwner(), "SpaceShooterRedux/PNG/Lasers/laserBlue16.png");
		newBullet.lock()->SetActorLocation(GetOwner()->GetActorLocation());
		newBullet.lock()->SetActorRotation(GetOwner()->GetActorRotation()+180);
	}
}