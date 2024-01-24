#include<iostream>
#include<SFML/Graphics.hpp>

using namespace std;

int main()
{
	sf::RenderWindow renderWindow{ sf::VideoMode(100,100), "MyWindow"};

	while (renderWindow.isOpen())
	{
		sf::Event windowEvent;
		while (renderWindow.pollEvent(windowEvent))
		{
			if (windowEvent.type == sf::Event::EventType::Closed)
			{
				renderWindow.close();
			}
		}
	}
	cout << "Hello world" << endl;
	return 0;
}