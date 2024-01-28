#pragma once
#include<string>

std::string GetResourceDir()
{
#ifdef NDEBUG //release build
	return "assets/";
#else
	return "D:/Game_Development/LightYears/LightYearsGame/assets/";
#endif
}
