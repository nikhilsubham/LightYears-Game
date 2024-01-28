#include <SFML/Graphics.hpp>
#include "framwork/World.h"
#include "framwork/Core.h"
#include "framwork/Actor.h"
#include "framwork/Application.h"


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

        for (auto iter = mActors.begin(); iter != mActors.end();)
        {
            if (iter->get()->isPendigDestroy())
            {
                iter = mActors.erase(iter);
            }
            else
            {
                (*iter)->TickInternal(deltaTime);
                ++iter;
            }
        }
        Tick(deltaTime);
    }

    void World::Render(sf::RenderWindow& window)
    {
        for (auto& actor : mActors)
        {
            actor->Render(window);
        }
    } 

    World::~World()
    {

    }

    sf::Vector2u World::GetWindowSize() const
    {
        return mOwningApp->GetWindowSize();
    }

    void World::BeginPlay()
    {
        //LOG("Begin play");
    }

    void World::Tick(float deltaTime)
    {
        //LOG("Ticking at framerate %f", 1.f / deltaTime);
    }
}
    