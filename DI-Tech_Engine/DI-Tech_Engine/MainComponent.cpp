#include "MainComponent.h"


#undef main

using namespace std;

MainComponent::MainComponent()
{
}

MainComponent::~MainComponent()
{
}

int main()
{
	DI_Window di_Window(800, 600, "DI Game Engine");

	Game game(&di_Window);

	CoreEngine engine(60, &di_Window, &game);
	engine.Start();

	cin.get();

	return 0;
}

