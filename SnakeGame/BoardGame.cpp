#include "BoardGame.h"
#include <stdlib.h>

// TODO
BoardGame::BoardGame() : width(0), height(0), cellWidth(0), _food(nullptr)
{
};

BoardGame::BoardGame(int width_, int height_, int cw_) : width(width_), height(height_), cellWidth(cw_), _food(nullptr)
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

BoardGame::~BoardGame()
{
	delete _food;
	_food = nullptr;
}

Cell* BoardGame::food() const
{
	return _food;
}

Cell* BoardGame::food(const bool& newfood=false)
{
	if (newfood)
	{
		_generateFood();
	}
	return _food;
}

void BoardGame::_generateFood()
{
	if (_food)
	{
		_food->setType(CellType::CellEmpty);
		_food = nullptr;
	}
	
	while (1)
	{
		srand(time(0));

		Cell& newCell = _grid[rand() % _grid.size()];
		if (newCell.getType() != CellType::CellHead && newCell.getType() != CellType::CellSnakePart)
		{
			newCell.setType(CellType::CellFood);
			_food = &newCell;
			return;
		}
	}

};

Cell* BoardGame::getCell(int i, int j)
{
	int idx = _index(i, j);
	if (_index(i, j) == -1)
	{
		return nullptr;
	}
	return &_grid[idx];
}

Cell& BoardGame::getCell(int id)
{
	return _grid[id];
}
int BoardGame::_index(int i, int j) const
{
	int rows = height / cellWidth;
	int cols = width / cellWidth;

	if (i < 0 || j < 0 || i >= rows || j >= cols) { return -1; }
	return i * cols + j;
};
