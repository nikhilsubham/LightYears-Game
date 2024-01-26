#include "framwork/Application.h"
#include "framwork/World.h"
#include "framwork/Core.h"


namespace ly
{
    World::World(Application* owningApp)
        :mOwningApp(owningApp),
        mBeganPlay{false}
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
    