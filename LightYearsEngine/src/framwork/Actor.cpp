#include "framwork/Actor.h"
#include "framwork/Core.h"
#include "framwork/AssetManager.h"

namespace ly
{
	Actor::Actor(World* owningWorld, const std::string& texturePath)
		: mOwningWorld(owningWorld),
		mHasBeganPlay(false),
		mSprite(),
		mTexture()
	{
		setTexture(texturePath);
	}

	Actor::~Actor()
	{
		LOG("Actor Destroyed");
	}

	void Actor::BeginPlayInternal()
	{
		if (!mHasBeganPlay)
		{
			mHasBeganPlay = true;
			BeginPlay();
		}
	}

	void Actor::TickInternal(float deltaTime)
	{
		if (!isPendigDestroy())
			Tick(deltaTime);
	}

	void Actor::BeginPlay()
	{
		//LOG("Actor begin play");
	}

	void Actor::Tick(float deltaTime)
	{
		//LOG("Actor Ticking");
	}

	void Actor::setTexture(const std::string& texturepath)
	{
		AssetManager& assetManager = AssetManager::get();
		mTexture = assetManager.LoadTexture(texturepath);   //loadFromFile(texturepath);

		if (!mTexture) return;
		mSprite.setTexture(*mTexture);

		int textureWidth = mTexture->getSize().x;
		int textureHeight = mTexture->getSize().y;
		mSprite.setTextureRect(sf::IntRect(sf::Vector2i{}, sf::Vector2i{textureWidth,textureHeight}));
	}

	void Actor::Render(sf::RenderWindow& window)
	{
		if (isPendigDestroy())
			return;

		window.draw(mSprite);
	}
}

