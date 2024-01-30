#include "framwork/Application.h"
#include "framwork/Core.h"
#include "framwork/World.h"
#include "framwork/AssetManager.h"

namespace ly
{
	Application::Application(unsigned int windowWidth, unsigned int windowHeight, const std::string& title, sf::Uint32 style)
		: mWindow{ sf::VideoMode(windowWidth,windowHeight),title, style },
		mTargetFrameRate{ 60.f },
		mTickClock{},
		currentWorld{ nullptr },
		mCleanCycleClock{ },
		mCleanCycleInterval{ 2.f }
	{

	}

	void Application::Run()
	{
		mTickClock.restart();
		float accumulatedTime = 0.f;
		float targetDeltaTime = 1.f / mTargetFrameRate;
		while (mWindow.isOpen())
		{
			sf::Event windowEvent;
			while (mWindow.pollEvent(windowEvent))
			{
				if (windowEvent.type == sf::Event::EventType::Closed)
				{
					mWindow.close();
				}
			}
			accumulatedTime += mTickClock.restart().asSeconds();
			while (accumulatedTime > targetDeltaTime)
			{
				accumulatedTime -= targetDeltaTime;
				TickInternal(targetDeltaTime);
				RenderInternal();
			}
		}
	}

	sf::Vector2u Application::GetWindowSize() const
	{
		return mWindow.getSize();
	}

	void Application::TickInternal(float deltaTime)
	{
		Tick(deltaTime);
		if(currentWorld)
		{
			currentWorld->beginPlayInternal();
			currentWorld->TickInternal(deltaTime);
		}
		if (mCleanCycleClock.getElapsedTime().asSeconds() >= mCleanCycleInterval)
		{
			mCleanCycleClock.restart();
			AssetManager::get().CleanCycle();

			if (currentWorld)
			{
				currentWorld->CleanCycle();
			}
		}
	}


	void Application::RenderInternal()
	{
		mWindow.clear();
		Render();
		mWindow.display();
	}

	void Application::Render()
	{
		if (currentWorld)
		{
			currentWorld->Render(mWindow);
		}
	}

	void Application::Tick(float deltaTime)  //Function overriden in GameApplication class.
	{

	}
}
