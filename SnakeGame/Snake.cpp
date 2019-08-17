#include "Snake.h"

Snake::Snake(const Cell& positionStart) : _head(positionStart)
{
	_head.setType(CellType::CellHead);
}

const Cell& Snake::getHead() const
{
	return _head;
}

void Snake::setHead(Cell& h)
{
	//_head.setType(CellType::CellEmpty);
	_head = h;
	_head.setType(CellType::CellHead);
}

const std::list<Cell>& Snake::getBody() const
{
	return _snakePartList;
}

void Snake::clearBody()
{
	while (!_snakePartList.empty())
	{
		_snakePartList.pop_back();
	}
};

void Snake::move(Cell& nextCell)
{
	auto tail = _snakePartList.back();
	tail.setType(CellType::CellEmpty);
	_snakePartList.pop_back();

	grow();
	setHead(nextCell);
};

void Snake::grow()
{
	_head.setType(CellType::CellSnakePart);
	_snakePartList.push_front(_head);
};

void Snake::grow(Cell& b)
{
	b.setType(CellType::CellSnakePart);
	_snakePartList.push_front(b);
};
