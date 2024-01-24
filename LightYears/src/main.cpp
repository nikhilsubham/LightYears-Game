#include<iostream>
#include<SFML/Graphics.hpp>
#include "framwork/Application.h"

using namespace std;

int main()
{
	//Allocation on the heap.
	ly::Application* app = new ly::Application();
	app->Run();

	//return 0;
}