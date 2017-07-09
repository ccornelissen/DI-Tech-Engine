#pragma once
#include "SDL2\SDL.h"

class DI_Window;

class Game
{
public:
	Game(DI_Window* window);
	~Game();

	void Input();
	void MouseButtonInput(SDL_MouseButtonEvent &sdl_Event);
	void KeyboardInput(const SDL_Keycode &curKey);
	void Update();

private:
	bool bShowCursor;
	DI_Window* di_Window;
};

