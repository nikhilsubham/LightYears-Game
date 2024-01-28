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

		void SetActorLocation(const sf::Vector2f& newLoc);
		void SetActorRotation(float newRot);
		void AddActorLocationOffset(const sf::Vector2f& offsetAmt);
		void AddActorRotationOffset(float offsetAmt);

		sf::Vector2f GetActorLocation() const;
		float GetActorRotation() const;
		sf::Vector2f GetActorForwardDirection() const;
		sf::Vector2f GetActorRightDirection() const;

		sf::Vector2u GetWindowSize() const;

	private:
		void CenterPivot();
		World* mOwningWorld;
		bool mHasBeganPlay;

		sf::Sprite mSprite;
		//sf::Texture mTexture;
		shared<sf::Texture> mTexture;
	};
}


