#include "MainComponent.h"
#include "DI_Window.h"

#undef main

using namespace std;

int main()
{
	DI_Window di_Window(800, 600, "DI Game Engine");

	MainComponent::Start();
}

void MainComponent::Start()
{
	Run();
}

void MainComponent::Stop()
{
}

void MainComponent::Run()
{
	while (!DI_Window::isCloseRequested())
	{
		Render();
	}
}

void MainComponent::Render()
{
}

void MainComponent::CleanUp()
{
}
