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
		void SetAssetRootDirectory(const std::string& directory);

	protected:
		AssetManager();

	private:
		static std::unique_ptr<AssetManager> assetManager;
		Dictionary<std::string, shared<sf::Texture>> mLoadedTextureMap;
		std::string mRootDirectory;
	};
}
