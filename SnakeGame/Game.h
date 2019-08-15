#pragma once
#include <SFML/Graphics.hpp>
#include "BoardGame.h"
#include "Snake.h"

class Game
{
public:
	enum EDirection { UP = 0, RIGHT, DOWN, LEFT };

	Game(int width_, int heigh_, int w);
	~Game();

	void run();

private:
	Snake _snake;
	BoardGame _board;
	sf::RenderWindow _window; 
	EDirection _eDirection;

	void updateDirection();
	void update();
	void render();
	

};

