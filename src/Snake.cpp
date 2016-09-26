#include "../include/Snake.hpp"
#include <iostream>


const int Snake::BLOCK_WIDTH = 25;
const int Snake::BLOCK_HEIGHT = 25;

Snake::Snake(Graphics* graphics):
	_START_POS_X(graphics->getWidth() / (2 * BLOCK_WIDTH) * BLOCK_WIDTH),
	_START_POS_Y(graphics->getHeight() / (2 * BLOCK_HEIGHT) * BLOCK_HEIGHT),
	_OFFSET(0),
	_graphics(graphics)
{
	reset();
}

Snake::~Snake()
{
	_blocks.clear();
}

void Snake::grow(const int amount)
{
	for(int i = 0; i < amount; i++)
	{
		std::pair<int, int> pos;
		if(_blocks.size() > 0)
		{
			pos.first = _blocks.back().first - _xDir * BLOCK_WIDTH + _OFFSET * _xDir * i;
			pos.second = _blocks.back().second - _yDir * BLOCK_HEIGHT + _OFFSET * _yDir * i;
		}
		else
		{
			pos.first = _START_POS_X;
			pos.second = _START_POS_Y;
		}
		_blocks.push_back(pos);
	}
}

void Snake::move()
{
	std::pair<int, int> pos;
	pos.first = _blocks[0].first + _xDir * (BLOCK_WIDTH + _OFFSET);
	pos.second = _blocks[0].second + _yDir * (BLOCK_HEIGHT + _OFFSET);
	_blocks.pop_back();
	_blocks.insert(_blocks.begin(), pos);
}

void Snake::setDir(const Direction dir)
{
	_dir = dir;
	switch(dir)
	{
		case UP:
			_xDir = 0;
			_yDir = -1;
			break;
		case DOWN:
			_xDir = 0;
			_yDir = 1;
			break;
		case LEFT:
			_xDir = -1;
			_yDir = 0;
			break;
		case RIGHT:
			_xDir = 1;
			_yDir = 0;
			break;
		case NONE:
			_xDir = 0;
			_yDir = 0;
			break;
	}
}

void Snake::update()
{
	move();
}

void Snake::render()
{
	_graphics->setDrawColor(0, 255, 0);
	for(size_t i = 0; i < _blocks.size(); i++)
	{
		SDL_Rect rect = {_blocks[i].first, _blocks[i].second, BLOCK_WIDTH, BLOCK_HEIGHT};
		_graphics->drawFilledRect(rect);
	}
}

const bool Snake::collides(const Apple& apple) const
{
	if (_blocks[0].first == apple.getPosX() && _blocks[0].second == apple.getPosY())
	{
		return true;
	}
	return false;
}

const bool Snake::collidesWithSelf() const
{
	for(auto itr = _blocks.begin() + 1; itr != _blocks.end(); itr++)
	{
		if(itr->first == _blocks[0].first && itr->second == _blocks[0].second)
		{
			return true;
		}
	}
	return false;
}

const bool Snake::offScreen() const
{
	const int x = _blocks[0].first;
	const int y = _blocks[0].second;
	if(x >= _graphics->getWidth() || x < 0 || y < 0 || y >= _graphics->getHeight())
	{
		return true;
	}
	return false;
}

void Snake::reset()
{
	_blocks.clear();
	setDir(NONE);
	grow(5);
}