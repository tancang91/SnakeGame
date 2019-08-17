#include "Game.h"
#include <iostream>


Game::Game(int width_, int heigh_, int w)
	: _board(width_, heigh_, w)
	, _snake({ 0,0,0 })
	, _window(sf::VideoMode(width_, heigh_), "Snake game")
	, _eDirection()
	, _isGameOver()
{
	setup();
}

Game::~Game()
{
}

void Game::setup()
{
	_eDirection = EDirection::RIGHT;
	_isGameOver = false;
	_board.food(true);
	_snake.setHead(*_board.getCell(0, 1));
	_snake.grow(*_board.getCell(0, 0));
}

void Game::run()
{
	_window.setFramerateLimit(15);
	while (_window.isOpen())
	{
		sf::Event event;
		while (_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_window.close();
		}
		// Game logic
		if (_isGameOver)
		{
			std::cout << "Game over: Y for conntinue" << std::endl;
			while (true)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
				{
					SnakeGame::reset(_board, _snake);
					setup();
					break;
				}
			}
		}
		render();
		update();
	}
}

void Game::update()
{
	updateDirection();

	int i = _snake.getHead().row();
	int j = _snake.getHead().col();

	int i_food = _board.food()->row();
	int j_food = _board.food()->col();

	if (i == i_food && j == j_food)
	{
		_snake.grow();
		_board.food(true);
	}

	switch (_eDirection)
	{
	case EDirection::UP:
		i--;
		break;
	case EDirection::DOWN:
		i++;
		break;
	case EDirection::RIGHT:
		j++;
		break;
	case EDirection::LEFT:
		j--;
		break;
	default:
		break;
	}

	Cell* next = _board.getCell(i, j);
	if (next)
	{
		_snake.move(*next);
	}

	if (SnakeGame::checkBodyCollision(_snake, _board) || SnakeGame::checkWallCollision(_board, i, j))
	{
		//std::cout << "Food " << i_food << ", " << j_food << std::endl;
		_isGameOver = true;
	}
};

void Game::render()
{
	_window.clear();
	_window.draw(_snake.getHead()); // draw head
	_window.draw(*_board.food());	// draw food

	const std::list<Cell>& body = _snake.getBody();
	for (auto& b : body)
	{
		_window.draw(b);
	};
	_window.display();
}

void Game::updateDirection()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && _eDirection != EDirection::RIGHT)
	{
		_eDirection = EDirection::LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && _eDirection != EDirection::LEFT)
	{
		_eDirection = EDirection::RIGHT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && _eDirection != EDirection::DOWN)
	{
		_eDirection = EDirection::UP;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && _eDirection != EDirection::UP)
	{
		_eDirection = EDirection::DOWN;
	}
}
