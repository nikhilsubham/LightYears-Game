#include "framwork/Application.h"
#include "framwork/Core.h"
#include "framwork/World.h"

namespace ly
{
	Application::Application(unsigned int windowWidth, unsigned int windowHeight, const std::string& title, sf::Uint32 style)
		: mWindow{ sf::VideoMode(windowWidth,windowHeight),title, style},
		mTargetFrameRate{ 60.f },
		mTickClock{},
		currentWorld{ nullptr }
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

	void Application::TickInternal(float deltaTime)
	{
		LOG("TickInternal class of Applocation.cpp file");
		Tick(deltaTime);
		if(currentWorld)
		{
			currentWorld->beginPlayInternal();
			currentWorld->TickInternal(deltaTime);
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
		sf::RectangleShape rect{ sf::Vector2f{100,100} };
		rect.setFillColor(sf::Color::Yellow);
		rect.setOrigin(50, 50);
		rect.setPosition(mWindow.getSize().x / 2.f, mWindow.getSize().y / 2.f);
		mWindow.draw(rect);
	}

	void Application::Tick(float deltaTime)  //Function overriden in GameApplication class.
	{

	}
}
