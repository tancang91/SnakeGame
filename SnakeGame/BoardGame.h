#pragma once
#include "Cell.h"
#include "vector"

class BoardGame
{
public:
	int width, height, cellWidth;
	
	BoardGame();
	BoardGame(int width_, int height_, int cw_);
	BoardGame(const BoardGame& board);
	void generateFood();
	Cell& getCell(int id);

private:
	std::vector<Cell> _grid;

};

