#include "DI_Input.h"
#include "DI_Window.h"

DI_Input::DI_Input(DI_Window* window)
{
	inp_Window = window;

	int inp_MouseX = 0;
	int inp_MouseY = 0;
}

DI_Input::~DI_Input()
{
}

SDL_Keycode DI_Input::GetKey(SDL_Event* event)
{
	if (event->type == SDL_KEYDOWN)
	{
		return event->key.keysym.sym;
	}
	else
	{
		return event->key.keysym.unused;
	}
}

void DI_Input::SetCursor(bool value)
{
	if (value)
	{
		SDL_ShowCursor(1);
	}
	else
	{
		SDL_ShowCursor(0);
	}
}

void DI_Input::SetMousePosition(float x, float y)
{
	SDL_WarpMouseInWindow(inp_Window->GetSDL_Window(), (int)x, (int)y);
}


