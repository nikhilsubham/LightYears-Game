#pragma once
#include <SFML/Graphics.hpp>
#include "framwork/Core.h"

namespace ly
{
	class AssetManager
	{
	protected:
		AssetManager();
	private:
		static unique<AssetManager> assetManager;

	};
}
