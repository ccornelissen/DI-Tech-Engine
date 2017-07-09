#include "Game.h"
#include "DI_Base.h"
#include "DI_Input.h"
#include "CoreEngine.h"

using namespace std;

Game::Game(DI_Window* window)
{
	di_Window = window;
	bShowCursor = false;
}

Game::~Game()
{
}

void Game::Input()
{
	SDL_Event sdl_Event;

	if (SDL_PollEvent(&sdl_Event))
	{
		SDL_Keycode curKey;

		curKey = DI_Input::GetKey(&sdl_Event);

		if (curKey)
		{
			KeyboardInput(curKey);
		}
	}

	if (SDL_PollEvent(&sdl_Event))
	{
		if (sdl_Event.type == SDL_MOUSEBUTTONDOWN)
		{
			MouseButtonInput(sdl_Event.button);
		}
	}

	int x, y; 

	SDL_GetMouseState(&x, &y);

	DI_Input::SetMousePosition(di_Window, x, y);
	
}

void Game::MouseButtonInput(SDL_MouseButtonEvent &sdl_MEvent)
{
	if (sdl_MEvent.button == SDL_BUTTON_LEFT)
	{
		cout << "Pressing left click" << endl;
	}
	else if (sdl_MEvent.button == SDL_BUTTON_RIGHT)
	{
		cout << "Pressing right click" << endl;
	}
	else if (sdl_MEvent.button == SDL_BUTTON_MIDDLE)
	{
		if (bShowCursor == false)
		{
			bShowCursor = true;
			DI_Input::SetCursor(bShowCursor);
		}
		else
		{
			bShowCursor = false;
			DI_Input::SetCursor(bShowCursor);
		}
	}
	else
	{
		return;
	}
}

void Game::KeyboardInput(const SDL_Keycode &curKey)
{
	switch (curKey)
	{
	case SDLK_w:
		cout << "Pressing W" << endl;
		break;
	case SDLK_s:
		cout << "Pressing S" << endl;
		break;
	case SDLK_d:
		cout << "Pressing D" << endl;
		break;
	case SDLK_a:
		cout << "Pressing A" << endl;
		break;
	case SDLK_ESCAPE:
		di_Window->CloseRequested(true);
		break;
	}
}

void Game::Update()
{
}
