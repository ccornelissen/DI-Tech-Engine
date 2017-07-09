#pragma once
#include "DI_Base.h"
#include "SDL2\SDL.h"
#include "GL\glew.h"
#include "DI_Input.h"

using namespace std;


class DI_Window
{
public:
	DI_Window(int width, int height, const string& title);
	~DI_Window();

	void Update();
	bool isCloseRequested();
	void CloseRequested(bool bValue);
	int getHeight();
	int getWidth();
	string getTitle();
	SDL_Window* GetSDL_Window();


private:
	int iWidth;
	int iHeight;
	string sTitle;
	SDL_Window* window;
	SDL_GLContext glContext;
	DI_Input di_Input;
	bool bCloseRequested;
};

