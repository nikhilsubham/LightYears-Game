#pragma once
#include <SFML/Graphics.hpp>
#include "framwork/Core.h"

namespace ly
{
	class AssetManager
	{
	public:
		static AssetManager& get();
		shared<sf::Texture> LoadTexture(const std::string& path);
		void CleanCycle();
	protected:
		AssetManager();
	private:
		static unique<AssetManager> assetManager;
		Dictionary<std::string, shared<sf::Texture>> mLoadedTextureMap;
	};
}
