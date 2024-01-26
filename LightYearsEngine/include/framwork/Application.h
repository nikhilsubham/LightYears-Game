#pragma once
#include<SFML/Graphics.hpp>
#include<framwork/Core.h>
#include<framwork/World.h>

namespace ly
{
	class World;
	class Application
	{
	public:
		Application();
		void Run();

		template<typename WorldType>
		weak<WorldType> LoadWorld()
		{
			shared<WorldType> newWorld{ new WorldType{this} };
			currentWorld = newWorld;
			return newWorld;
		}

	private:
		void TickInternal(float deltaTime);
		void RenderInternal();

		virtual void Render();
		virtual void Tick(float deltaTime);

		sf::RenderWindow mWindow;
		float mTargetFrameRate;
		sf::Clock mTickClock;

		shared<World> currentWorld;
	};
}

	

