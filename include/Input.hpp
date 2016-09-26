#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>


class Input
{
private:
	SDL_Keycode _keyReleased, _keyPressed;
	bool _shouldQuit;
public:
	Input();
	~Input(){ }
	void update();
	const bool shouldQuit() const { return _shouldQuit; }
	const SDL_Keycode getKeyDown() const { return _keyPressed; }
	const SDL_Keycode getKeyUp() const { return _keyReleased; }
	const int getMousePosX();
	const int getMousePosY();
};


#endif //INPUT_H