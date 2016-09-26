#include "../include/Input.hpp"


Input::Input():
	_keyReleased(-1),
	_keyPressed(-1),
	_shouldQuit(false)
{

}

void Input::update()
{
	SDL_Event e;
	_keyReleased = -1;
	while (SDL_PollEvent(&e) != 0)
	{
		switch(e.type)
		{
			case SDL_KEYDOWN:
				_keyPressed = e.key.keysym.sym;
				break;
			case SDL_KEYUP:
				_keyReleased = e.key.keysym.sym;
				_keyPressed = -1;
				break;
			case SDL_QUIT:
				_shouldQuit = true;
				break;
		}
	}
}

const int Input::getMousePosX()
{
	int x;
	SDL_GetMouseState(&x, NULL);
	return x;
}

const int Input::getMousePosY()
{
	int y;
	SDL_GetMouseState(NULL, &y);
	return y;
}