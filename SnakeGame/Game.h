#pragma once
#include <SFML/Graphics.hpp>
#include "BoardGame.h"
#include "Snake.h"

class Game
{
public:
	Game(const BoardGame* const board);
	Game(int width_, int heigh_, int w);
	void run();

private:
	Snake _snake;
	BoardGame _board;
	sf::RenderWindow _window;

	void update();
	void render();
};

