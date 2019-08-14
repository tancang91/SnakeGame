#include "Game.h"
#include <iostream>

int index(int i, int j, int cols, int rows) {
	if (i < 0 || j < 0 || i >= rows || j >= cols) { return -1; }
	return i * cols + j;
}

// TODO
Game::Game(const BoardGame* const board)
{
};

Game::Game(int width_, int heigh_, int w)
	: _board(width_, heigh_, w)
	, _snake({ 0,0,0 })
	, _window(sf::VideoMode(width_, heigh_), "Snake game")
{
	_snake.setHead(_board.getCell(1));
	_snake.grow(_board.getCell(0));
};

void Game::run()
{
	_window.setFramerateLimit(5);
	while (_window.isOpen())
	{
		sf::Event event;
		while (_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_window.close();
		}
		render();
		update();
	}
}

void Game::update()
{
	int i = _snake.getHead().row();
	int j = _snake.getHead().col();
	int cols = _board.width / _board.cellWidth;
	int rows = _board.height / _board.cellWidth;

	int idx = index(i, j+1, cols, rows);
	if (idx != -1)
	{
		auto next = _board.getCell(idx);
		_snake.move(next);
	}
};

void Game::render()
{
	_window.clear();

	auto body = _snake.getBody();
	for (auto& b : body)
	{
		_window.draw(b);
	};
	_window.draw(_snake.getHead());
	_window.display();
};

