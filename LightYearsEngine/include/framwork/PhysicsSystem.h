#pragma once
#include <memory>
#include<box2d/b2_world.h>

namespace ly
{
	class PhysicsSystem
	{
	public:
		static PhysicsSystem& Get();
	protected:
		PhysicsSystem();
	private:
		static std::unique_ptr<PhysicsSystem> physicsSystem;
		b2World mPhysicsWorld;
		float mPhysicsScal;
	};
}