#pragma once
#include "DI_Base.h"
#include "DI_Window.h"
#include "Timing.h"
#include "Game.h"

class CoreEngine
{
public:
	CoreEngine(double frameRate, DI_Window* window, Game* game);
	~CoreEngine();

	void Start();
	void Stop();
	void Run();
	void Render();
	void CleanUp();

private:
	bool isRunning;
	double dFrameRate;
	DI_Window* di_Window;
	Game* di_Game;
};

