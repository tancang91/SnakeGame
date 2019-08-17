#pragma once
#include <list>
#include "Cell.h"

class Snake
{
public:
	Snake();
	Snake(const Cell& positionStart);

	const Cell& getHead() const;
	void setHead(Cell& h);

	const std::list<Cell>& getBody() const;

	void clearBody();
	void move(Cell& nextCell);
	void grow();
	void grow(Cell& b);

private:
	Cell _head;
	std::list<Cell> _snakePartList;
};


