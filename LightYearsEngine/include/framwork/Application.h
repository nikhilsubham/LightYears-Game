#pragma once
#include<SFML/Graphics.hpp>
#include<framwork/Core.h>

namespace ly
{
	class World;
	class Application
	{
	public:
		Application(unsigned int windowWidth, unsigned int windowHeight, const std::string&title, sf::Uint32 style);
		void Run();

		template<typename WorldType>
		std::weak_ptr<WorldType> LoadWorld()
		{
			std::shared_ptr<WorldType> newWorld = std::make_shared<WorldType>(this);
			currentWorld = newWorld;
			return newWorld;
		}

		sf::Vector2u GetWindowSize() const;

	private:
		void TickInternal(float deltaTime);
		void RenderInternal();

		virtual void Render();
		virtual void Tick(float deltaTime);

		sf::RenderWindow mWindow;
		float mTargetFrameRate;
		sf::Clock mTickClock;

		std::shared_ptr<World> currentWorld;
		sf::Clock mCleanCycleClock;
		float mCleanCycleInterval;
	};
}

	

