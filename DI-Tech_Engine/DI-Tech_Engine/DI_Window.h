#pragma once
#include "DI_Base.h"
#include "SDL2\SDL.h"
#include "GL\glew.h"

using namespace std;

class DI_Window
{
public:
	DI_Window(int width, int height, const string& title);
	~DI_Window();

	void Update();
	static bool isCloseRequested();
	int getHeight();
	int getWidth();
	string getTitle();

private:
	int iWidth;
	int iHeight;
	string sTitle;
	SDL_Window* window;
	SDL_GLContext glContext;
	//Input input;
	bool bCloseRequested;
};

