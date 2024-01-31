#include <box2D/b2_body.h>
#include <box2D/b2_contact.h>
#include <box2D/b2_fixture.h>
#include <box2D/b2_polygon_shape.h>
#include <box2D/b2_contact.h>

#include"framwork/PhysicsSystem.h"
#include "framwork/MathUtility.h"
#include "framwork/Actor.h"

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

	void PhysicsSystem::Step(float deltaTime)
	{
		processPendingRemoveListeners();
		mPhysicsWorld.Step(deltaTime, mVelocityIterations, mPositionIterations);
	}


	b2Body* PhysicsSystem::AddListener(Actor* listener)
	{
		if (listener->isPendigDestroy()) return nullptr;

		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;

		bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(listener);

		bodyDef.position.Set(listener->GetActorLocation().x * GetPhysicsScale(), listener->GetActorLocation().y * GetPhysicsScale());
		bodyDef.angle = DegreesToRadians(listener->GetActorRotation());

		b2Body* body = mPhysicsWorld.CreateBody(&bodyDef);

		b2PolygonShape shape;
		auto bound = listener->GetActorGlobalBounds();
		shape.SetAsBox(bound.width / 2.f * GetPhysicsScale(), bound.height / 2.f * GetPhysicsScale());

		b2FixtureDef fixtureDef;
		fixtureDef.shape = &shape;
		fixtureDef.density = 1.0f;
		fixtureDef.friction = 0.3f;
		fixtureDef.isSensor = true;

		body->CreateFixture(&fixtureDef);

		return body;
	}

	void PhysicsSystem::RemoveListener(b2Body* bodyToRemove)
	{
		mPendingRemoveListeners.insert(bodyToRemove);
	}

	void PhysicsSystem::Cleanup()
	{
		physicsSystem = std::move(std::unique_ptr<PhysicsSystem>{new PhysicsSystem});
	}

	PhysicsSystem::PhysicsSystem()
		:mPhysicsWorld{ b2Vec2{0.f,0.f} },
		mPhysicsScale{0.01f},
		mVelocityIterations{ 8 },
		mPositionIterations{ 3 },
		mContactListener{},
		mPendingRemoveListeners{}
	{
		mPhysicsWorld.SetContactListener(&mContactListener);
		mPhysicsWorld.SetAllowSleeping(false);
	}

	void PhysicsSystem::processPendingRemoveListeners()
	{
		for (auto listeners : mPendingRemoveListeners)
		{
			mPhysicsWorld.DestroyBody(listeners);
		}
		mPendingRemoveListeners.clear();
	}

	void PhysicsContactListener::BeginContact(b2Contact* contact)
	{
		Actor* ActorA = reinterpret_cast<Actor*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
		Actor* ActorB = reinterpret_cast<Actor*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);

		if (ActorA && !ActorA->isPendigDestroy())
		{
			ActorA->OnActorBeginOverlap(ActorB);
		}
		if (ActorB && !ActorB->isPendigDestroy())
		{
			ActorB->OnActorBeginOverlap(ActorA);
		}
	}

	void PhysicsContactListener::EndContact(b2Contact* contact)
	{
		//LOG("End Contect");
		Actor* ActorA = nullptr;
		Actor* ActorB = nullptr;

		if (contact->GetFixtureA() && contact->GetFixtureA()->GetBody())
		{
			ActorA = reinterpret_cast<Actor*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
		}

		if (contact->GetFixtureB() && contact->GetFixtureB()->GetBody())
		{
			ActorB = reinterpret_cast<Actor*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);
		}

		if (ActorA && !ActorA->isPendigDestroy())
		{
			ActorA->OnActorEndOverlap(ActorB);
		}

		if (ActorB && !ActorB->isPendigDestroy())
		{
			ActorB->OnActorEndOverlap(ActorA);
		}
	}
}