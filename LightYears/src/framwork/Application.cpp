#include "framwork/Application.h"
#include <iostream>


namespace ly
{
	Application::Application()
		: mWindow{ sf::VideoMode(800,900), "Light Years" },
		mTargetFrameRate{60.f},
		mTickClock{}
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
			//std::cout << accumulatedTime << std::endl;
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
		std::cout<< "Ticking at frmaerate:  "<<1.f/deltaTime << std::endl;
		Tick(deltaTime);
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
	void Application::Tick(float deltaTime)
	{

	}
}
