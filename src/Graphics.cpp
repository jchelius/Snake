#include "../include/Graphics.hpp"


Graphics::Graphics(const int width, const int height, const std::string& title):
	_width(width),
	_height(height)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	setDrawColor(0, 0, 0, 0);
}

Graphics::~Graphics()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

void Graphics::setDrawColor(const int r, const int g, const int b, const int a)
{
	SDL_SetRenderDrawColor(_renderer, r, g, b, a);
}

void Graphics::clear()
{
	SDL_RenderClear(_renderer);
}

void Graphics::drawPoint(const int x, const int y)
{
	SDL_RenderDrawPoint(_renderer, x, y);
}

void Graphics::drawLine(const int x1, const int y1, const int x2, const int y2)
{
	SDL_RenderDrawLine(_renderer, x1, y1, x2, y2);
}

void Graphics::drawFilledRect(const SDL_Rect& rect)
{
	SDL_RenderFillRect(_renderer, &rect);
}

void Graphics::update()
{
	SDL_RenderPresent(_renderer);
}
