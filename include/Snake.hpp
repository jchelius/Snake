#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

#include "Graphics.hpp"
#include "Apple.hpp"


enum Direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NONE
};

class Snake
{
private:
	std::vector<std::pair<int, int>> _blocks;
	const int _START_POS_X, _START_POS_Y, _OFFSET;
	Graphics* _graphics;
	int _xDir, _yDir;
	Direction _dir;
public:
	static const int BLOCK_WIDTH, BLOCK_HEIGHT;
public:
	Snake(Graphics* graphics);
	~Snake();
	void grow(const int amount);
	void update();
	void render();
	void move();
	void setDir(const Direction dir);
	const Direction getDir() const { return _dir; }
	const bool collides(const Apple& apple) const;
	const bool collidesWithSelf() const;
	const bool offScreen() const;
	void reset();
};


#endif //SNAKE_H
