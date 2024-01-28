#pragma once
#include "framwork/Core.h"

namespace ly
{
	class Actor;
	class Application;
	class World
	{
	public:
		World(Application* owningApp);
		void beginPlayInternal();
		void TickInternal(float deltaTime);
		void Render(sf::RenderWindow& window);

		virtual ~World();

		template<typename ActorType>
		weak<ActorType> SpawnActor()
		{
			shared<ActorType>newActor{ new ActorType{this} };
			mPendingActors.push_back(newActor);
			return newActor;
		}

		sf::Vector2u GetWindowSize() const;

	private:
		void BeginPlay();
		void Tick(float deltaTime);
		Application* mOwningApp;
		bool mBeganPlay;

		List<shared<Actor>> mActors;
		List<shared<Actor>> mPendingActors;
	};
}

