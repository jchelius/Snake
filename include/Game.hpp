#ifndef GAME_H
#define GAME_H

#include "Graphics.hpp"
#include "Input.hpp"
#include "Snake.hpp"


class Game
{
private:
	Graphics* _graphics;
	Input* _input;
	Snake _snake;
	Apple _apple;
	const int _FPS;
	const int _MPF;
	int _startTime;
	bool _paused;
private:
	void reset();
	void pause();
	void resume();
public:
	Game(Graphics* graphics, Input* input);
	~Game(){ }
	void update();
	void render();
};


#endif //GAME_H
