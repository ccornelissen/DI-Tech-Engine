#pragma once
#include "DI_Base.h"
#include <SDL2/SDL.h>

class DI_Window;

class DI_Input
{
public:
	DI_Input(DI_Window* in_Window);
	~DI_Input();

	static SDL_Keycode GetKey(SDL_Event* event);
	static void SetCursor(bool value);
	static void SetMousePosition(DI_Window* window, int x, int y);
	

private:
	DI_Window* inp_Window;
	int inp_MouseX;
	int inp_MouseY;
};

