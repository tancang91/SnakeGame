#include "Helper.h"
#include <iostream>

bool SnakeGame::checkCrash(const size_t& i, const size_t& j, const size_t& columns, const size_t& rows)
{
	return i < 0 || j < 0 || i > rows || j > columns ? true : false;
}

bool SnakeGame::checkWallCollision(const BoardGame& board, const size_t& i, const size_t& j)
{
	size_t rows = board.height / board.cellWidth;
	size_t cols = board.width / board.cellWidth;
	
	if (i < 0 || j < 0)
	{
		return true;
	}
	if (i >= rows || j >= cols)
	{
		return true;
	}
	return false;
}

bool SnakeGame::checkBodyCollision(const Snake& snake, const BoardGame& board)
{
	const std::list<Cell>& body = snake.getBody();
	const Cell& head = snake.getHead();
	for (auto& b : body)
	{
		if (head.row() == b.row() && head.col() == b.col())
		{
			std::cout << "(" << head.row() << ", " << head.col() << ") ";
			std::cout << "[" << b.row() << ", " << b.col() << "]\n";
			return true;
		}
	}
	return false;
}

void SnakeGame::reset(BoardGame& board, Snake& snake)
{
	size_t rows = board.rows();
	size_t cols = board.columns();
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			board.getCell(i, j)->setType(CellType::CellEmpty);
		}
	}
	snake.clearBody();
}
