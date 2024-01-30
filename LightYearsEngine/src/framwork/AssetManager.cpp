#include "framwork/AssetManager.h"

namespace ly
{
	std::unique_ptr<AssetManager> AssetManager::assetManager{ nullptr };

	AssetManager& AssetManager::get()
	{
		if (!assetManager)
		{
			assetManager = std::move(std::unique_ptr<AssetManager>(new AssetManager));
		}
		return *assetManager;
	}

	std::shared_ptr<sf::Texture> AssetManager::LoadTexture(const std::string& path)
	{
		auto found = mLoadedTextureMap.find(path);
		if (found != mLoadedTextureMap.end())
		{
			return found->second;
		}

		std::shared_ptr<sf::Texture> newTexture = std::make_shared<sf::Texture>();
		if (newTexture->loadFromFile(mRootDirectory+path))
		{
			mLoadedTextureMap.insert({path, newTexture});
			return newTexture;
		}
		return nullptr;
	}

	void AssetManager::CleanCycle()
	{
		for (auto iter = mLoadedTextureMap.begin(); iter != mLoadedTextureMap.end();)
		{
			if (iter->second.unique())
			{
				LOG("Cleaning texture: %s", iter->first.c_str());
				iter = mLoadedTextureMap.erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}

	void AssetManager::SetAssetRootDirectory(const std::string& directory)
	{
		mRootDirectory = directory;
	}

	AssetManager::AssetManager() :mRootDirectory{}
	{

	}
}