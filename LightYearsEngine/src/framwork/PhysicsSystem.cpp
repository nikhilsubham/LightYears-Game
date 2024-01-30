#include"framwork/PhysicsSystem.h"
#include<>

namespace ly
{
	std::unique_ptr<PhysicsSystem> PhysicsSystem :: physicsSystem{ nullptr };

	PhysicsSystem& PhysicsSystem::Get()
	{
		if (!physicsSystem)
		{
			physicsSystem = std::move(std::unique_ptr<PhysicsSystem>{new PhysicsSystem});
		}
		return *physicsSystem;
	}

	PhysicsSystem::PhysicsSystem()
		:mPhysicsWorld{ b2Vec2{0.f,0.f} },
		mPhysicsScal{0.01f}
	{

	}
}