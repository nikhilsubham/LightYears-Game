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

	/*	template<typename ActorType>
		weak<ActorType> SpawnActor()
		{
			shared<ActorType>newActor{ new ActorType{this} };
			mPendingActors.push_back(newActor);
			return newActor;
		}  */

		template<typename ActorType, typename...  Args>
		std::weak_ptr<ActorType> SpawnActor(Args... args)
		{
			std::shared_ptr<ActorType> newActor = std::make_shared<ActorType>(this, args...);
			mPendingActors.push_back(newActor);
			return newActor;
		}  

		sf::Vector2u GetWindowSize() const;
		void CleanCycle();

	private:
		void BeginPlay();
		void Tick(float deltaTime);
		Application* mOwningApp;
		bool mBeganPlay;

		std::vector<std::shared_ptr<Actor>> mActors;
		std::vector<std::shared_ptr<Actor>> mPendingActors;
	};
}

