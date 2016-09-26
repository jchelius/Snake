#ifndef APPLE_H
#define APPLE_H

#include "../include/Graphics.hpp"


class Apple
{
private:
	Graphics* _graphics;
	int _x, _y;
public:
	static const int WIDTH, HEIGHT;
public:
	Apple(Graphics* graphics);
	~Apple(){ }
	const int getPosX() const { return _x; }
	const int getPosY() const { return _y; }
	void respawn();
	void render();
};


#endif //APPLE_H