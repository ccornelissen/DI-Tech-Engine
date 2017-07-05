#include "Game.h"
#include "DI_Base.h"
#include "DI_Input.h"
#include "SDL2\SDL.h"

using namespace std;

Game::Game()
{
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
		}
	}
}

void Game::Update()
{
}
