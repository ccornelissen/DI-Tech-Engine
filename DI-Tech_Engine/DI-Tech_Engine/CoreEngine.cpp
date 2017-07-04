#include "CoreEngine.h"
#include "SDL2\SDL.h"
#include <stdio.h>
#include <time.h>

using namespace std;

CoreEngine::CoreEngine(double frameRate, DI_Window* window, Game* game)
{
	isRunning = false;
	di_Window = window;
	di_Game = game;

	
}

CoreEngine::~CoreEngine()
{
}

void CoreEngine::Start()
{
	if (isRunning)
	{
		return;
	}

	isRunning = true;

	Run();
}

void CoreEngine::Stop()
{
	if (!isRunning)
		return;

	isRunning = false;
}

void CoreEngine::Run()
{
	double dLastTime = Timing::GetTime(); //Current time at the start of the last frame
	double dFrameCounter = 0; //Total passed time since last frame counter display
	double dUnprocessedTime = 0; //Amount of passed time that the engine hasn't accounted for.
	int iFrames = 0; //Number of frames rendered since last
	double dFrameTime = 1.0 / 60.0;

	while (isRunning)
	{
		bool bRender = false;

		double dStartTime = Timing::GetTime(); //Current time at the start of the frame
		double dPassedTime = dStartTime - dLastTime; //Amount of passed time since the last frame
		dLastTime = dStartTime;

		dUnprocessedTime += dPassedTime;
		dFrameCounter += dPassedTime;

		while (dUnprocessedTime > dFrameTime)
		{
			bRender = true;

			dUnprocessedTime -= dFrameTime;

			if (DI_Window::isCloseRequested()) //If user attempts to close the window stop running the program
			{
				Stop();
			}

			//The engine displays profiling statistics after every second because it needs to display them at some point.
			//The choice of once per second is arbitrary, and can be changed as needed
			if (dFrameCounter > 1.0)
			{
				cout << iFrames << endl;
				iFrames = 0;
				dFrameCounter = 0;
			}

			//Update game
			di_Game->Input();
			di_Game->Update();

		}

		if (bRender)
		{
			Render();
			iFrames++;
		}
		else
		{
			SDL_Delay(1);
		}
	}
}

void CoreEngine::Render()
{
}

void CoreEngine::CleanUp()
{
}
