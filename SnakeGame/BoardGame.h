#pragma once
#include "Cell.h"
#include "vector"

class BoardGame
{
public:
	int width, height, cellWidth;
	
	BoardGame();
	BoardGame(int width_, int height_, int cw_);
	~BoardGame();


	size_t rows();
	size_t columns();

	Cell* food() const;
	Cell* food(const bool& newfood);

	Cell* getCell(int i, int j);
	Cell& getCell(int id);

private:
	std::vector<Cell> _grid;
	Cell* _food;

	void _generateFood();
};

