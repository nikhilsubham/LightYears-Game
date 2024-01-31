#include "Weapon/Bullet.h"



namespace ly
{
	Bullet::Bullet(World* world, Actor* owner, const std::string& texturePath, float speed, float damage)
		:Actor{world, texturePath},
		mOwner{owner},
		mSpeed(speed),
		mDamage(damage)
	{

	}

	void Bullet::SetSpeed(float newSpeed)
	{
		mSpeed = newSpeed;
	}

	void Bullet::SetDamage(float newDaamge)
	{
		mDamage = newDaamge;
	}

	void Bullet::Tick(float deltaTime)
	{
		Actor::Tick(deltaTime);
		Move(deltaTime);
		if (IsActorOutofWindowBounds())
		{
			Destroy();
		}
	}

	void Bullet::BeginPlay()
	{
		Actor::BeginPlay();
		SetEnablePhysics(true);
	}

	void Bullet::Move(float deltaTime)
	{
		AddActorLocationOffset(GetActorForwardDirection() * mSpeed * deltaTime);
	}
}