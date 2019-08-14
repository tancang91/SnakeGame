#include "BoardGame.h"

// TODO
BoardGame::BoardGame(const BoardGame& board)
{
};

BoardGame::BoardGame(): width(0), height(0), cellWidth(0)
{
};

BoardGame::BoardGame(int width_, int height_, int cw_) : width(width_), height(height_), cellWidth(cw_)
{
	int rows = height / cellWidth;
	int cols = width / cellWidth;
	int w = cellWidth;

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			_grid.emplace_back(i, j, w);
		}
	}
}

Cell& BoardGame::getCell(int id)
{
	return _grid[id];
};
