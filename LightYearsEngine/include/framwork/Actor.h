#pragma once
#include<SFML/Graphics.hpp>

#include "framwork/Core.h"
#include "framwork/Object.h"

namespace ly
{
	class World;
	class Actor : public Object
	{
	public:
		Actor(World* owningWorld, const std::string& texturePath = "");
		virtual ~Actor();
		void BeginPlayInternal();
		void TickInternal(float deltaTime);
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);
		void setTexture(const std::string& texturepath);
		void Render(sf::RenderWindow& window);

	private:
		World* mOwningWorld;
		bool mHasBeganPlay;

		sf::Sprite mSprite;
		sf::Texture mTexture;
	};
}


