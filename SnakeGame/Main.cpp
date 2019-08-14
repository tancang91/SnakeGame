//#include <SFML/Graphics.hpp>
#include "Game.h"
#include "BoardGame.h"


const int rows = 800;
const int cols = 600;
const int width = 20;

int main()
{
	//BoardGame board(rows, cols, width);
	Game* g = new Game(rows, cols, width);
	g->run();
	delete g;

	return 0;
}