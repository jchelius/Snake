#include "../include/Game.hpp"
#include <iostream>


Game::Game(Graphics* graphics, Input* input):
	_graphics(graphics),
	_input(input),
	_snake(graphics),
	_apple(graphics),
	_FPS(17),
	_MPF(1000 / _FPS)
{
	
}

void Game::update()
{
	const int startTime = SDL_GetTicks() - _startTime;
	_snake.update();
	if (_snake.collides(_apple))
	{
		_snake.grow(5);
		_apple.respawn();
	}
	if(_snake.collidesWithSelf() || _snake.offScreen())
	{
		reset();
	}
	if ((_input->isKeyDown(SDL_SCANCODE_UP) || _input->isKeyDown(SDL_SCANCODE_W)) && _snake.getDir() != DOWN)
	{
		_snake.setDir(UP);
	}
	if ((_input->isKeyDown(SDL_SCANCODE_DOWN) || _input->isKeyDown(SDL_SCANCODE_S)) && _snake.getDir() != UP)
	{
		_snake.setDir(DOWN);
	}
	if ((_input->isKeyDown(SDL_SCANCODE_RIGHT) || _input->isKeyDown(SDL_SCANCODE_D)) && _snake.getDir() != LEFT)
	{
		_snake.setDir(RIGHT);
	}
	if ((_input->isKeyDown(SDL_SCANCODE_LEFT) || _input->isKeyDown(SDL_SCANCODE_A)) && _snake.getDir() != RIGHT)
	{
		_snake.setDir(LEFT);
	}
	const int diff = (SDL_GetTicks() - _startTime) - startTime;
	if(diff < _MPF)
	{
		SDL_Delay(_MPF - diff);
	}
}

void Game::render()
{
	_snake.render();
	_apple.render();
	_graphics->setDrawColor(0, 0, 0);
}

void Game::reset()
{
	_snake.reset();
}