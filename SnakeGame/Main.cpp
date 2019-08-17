//#include <SFML/Graphics.hpp>
#include "Game.h"
#include "BoardGame.h"
#include <iostream>

const int rows = 800;
const int cols = 600;
const int width = 20;

int main()
{

	Game game(rows, cols, width);
	game.run();

	return 0;
}