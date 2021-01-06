#include "../include/Game.hpp"
#include "../include/Random.hpp"


const int WIDTH = 1000;
const int HEIGHT = 800;
const std::string TITLE = "Snake";


int main(int, char**)
{
	Graphics* graphics = new Graphics(WIDTH, HEIGHT, TITLE);
	Input* input = new Input;
	Game game(graphics, input);
	while(!input->shouldQuit())
	{
		graphics->clear();
		game.updateInput();
		game.update();
		game.render();
		graphics->update();
		input->update();
	}
	delete graphics;
	return 0;
}