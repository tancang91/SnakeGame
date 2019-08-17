#pragma once
#include "Snake.h"
#include "BoardGame.h"

namespace SnakeGame {
	inline size_t index(const size_t& i, const size_t& j, const size_t& columns) { return i * columns + j; }

	bool checkCrash(const size_t& i, const size_t& j, const size_t& columns, const size_t& rows);
	bool checkWallCollision(const BoardGame& board, const size_t& i, const size_t& j);
	bool checkBodyCollision(const Snake& snake, const BoardGame& board);

	void reset(BoardGame& board, Snake& snake);
}