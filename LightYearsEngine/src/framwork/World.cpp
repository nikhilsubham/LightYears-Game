#include "framwork/World.h"
#include "framwork/Core.h"
#include "framwork/Actor.h"


namespace ly
{
    World::World(Application* owningApp)
        :mOwningApp(owningApp),
        mBeganPlay{false},
        mActors(),
        mPendingActors()
    {

    }

    void World::beginPlayInternal()
    {
        if (!mBeganPlay)
        {
            mBeganPlay = true;
            BeginPlay();
        }
    }

    void World::TickInternal(float deltaTime)
    {
        for (shared<Actor> actor : mPendingActors)
        {
            mActors.push_back(actor);
            actor->BeginPlayInternal();
        }
        mPendingActors.clear();

        for (shared<Actor> actor : mActors)
        {
            actor->Tick(deltaTime);
        }
        Tick(deltaTime);
    }

    World::~World()
    {

    }

    void World::BeginPlay()
    {
        LOG("Begin play");
    }

    void World::Tick(float deltaTime)
    {
        LOG("Ticking at framerate %f", 1.f / deltaTime);
    }
}
    