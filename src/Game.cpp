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
	const int startTime = SDL_GetTicks();
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
	const int diff = SDL_GetTicks() - startTime;
	if(diff < _MPF)
	{
		SDL_Delay(_MPF - diff);
	}
}

void Game::updateInput() 
{
	if ((_input->isKeyDown(SDL_SCANCODE_UP) || _input->isKeyDown(SDL_SCANCODE_W)) && _snake.getDir() != Direction::DOWN)
	{
		_snake.setDir(Direction::UP);
		//std::cout << "up" << std::endl;
	}
	if ((_input->isKeyDown(SDL_SCANCODE_DOWN) || _input->isKeyDown(SDL_SCANCODE_S)) && _snake.getDir() != Direction::UP)
	{
		_snake.setDir(Direction::DOWN);
		//std::cout << "down" << std::endl;
	}
	if ((_input->isKeyDown(SDL_SCANCODE_RIGHT) || _input->isKeyDown(SDL_SCANCODE_D)) && _snake.getDir() != Direction::LEFT)
	{
		_snake.setDir(Direction::RIGHT);
		//std::cout << "right" << std::endl;
	}
	if ((_input->isKeyDown(SDL_SCANCODE_LEFT) || _input->isKeyDown(SDL_SCANCODE_A)) && _snake.getDir() != Direction::RIGHT)
	{
		_snake.setDir(Direction::LEFT);
		//std::cout << "left" << std::endl;
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