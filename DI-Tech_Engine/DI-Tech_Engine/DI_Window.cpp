#include "DI_Window.h"
#include "DI_Input.h"

DI_Window::DI_Window(int width, int height, const string& title) :
	iWidth(width),
	iHeight(height),
	sTitle(title),
	di_Input(this),
	bCloseRequested(false)
{
	//Initialize SDL sub systems
	SDL_Init(SDL_INIT_EVERYTHING);

	//Set the SDL attributes (8 for default)
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	glContext = SDL_GL_CreateContext(window);

	SDL_GL_SetSwapInterval(1);

	glewExperimental = GL_TRUE;

	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
	}
}

DI_Window::~DI_Window()
{
}

void DI_Window::Update()
{

}

bool DI_Window::isCloseRequested()
{
	return bCloseRequested;
}

void DI_Window::CloseRequested(bool bValue)
{
	bCloseRequested = bValue;
}

int DI_Window::getHeight()
{
	return 0;
}

int DI_Window::getWidth()
{
	return 0;
}

string DI_Window::getTitle()
{
	return string();
}

SDL_Window * DI_Window::GetSDL_Window()
{
	return window;
}

