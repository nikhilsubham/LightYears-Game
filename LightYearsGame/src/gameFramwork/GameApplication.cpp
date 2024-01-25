#include <iostream>
#include <gameFramwork/GameApplication.h>


ly::Application* GetApplication()
{
	return new ly::GameApplication{};
}

namespace ly
{

}