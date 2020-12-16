#include "Board.h"

Board::Board() : turn(Turn::WHITE), black(0), white(0), end(false)
{
}

void Board::init()
{
	for (int y = 0; y < height; ++y)
		for (int x = 0; x < width; ++x) {
			state[y][x] = State::NONE;
			count[y][x] = 0;
		}

	state[3][3] = State::BLACK;
	state[3][4] = State::WHITE;
	state[4][3] = State::WHITE;
	state[4][4] = State::BLACK;

	turn = Turn::WHITE;
	black = white = 0;
	end = false;

	nextTurn();
}

bool Board::nextTurn()
{
	// toggle turn
	turn = (turn == Turn::BLACK ? Turn::WHITE : Turn::BLACK);

	// update score
	white = 0;
	black = 0;
	for (int y = 0; y < height; ++y)
		for (int x = 0; x < width; ++x)
			if (state[y][x] == State::BLACK) black++;
			else if (state[y][x] == State::WHITE) white++;

	// update possible & count
	bool possible = false;
	for (int y = 0; y < height; ++y)
		for (int x = 0; x < width; ++x) {
			count[y][x] = reverse(x, y, false);
			if (count[y][x] > 0) {
				state[y][x] = State::POSSIBLE;
				possible = true;
			}
		}
	return possible;
}

int Board::reverse(int x, int y, bool execute)
{
	if (state[y][x] == State::BLACK || state[y][x] == State::WHITE) {
		return 0;
	}

	state[y][x] = (execute ? (turn == Turn::BLACK ? State::BLACK : State::WHITE) : State::NONE);

	static const int delta[8][2] = {
		{ 0, 1 },
		{ 1, 1 },
		{ 1, 0 },
		{ 1, -1 },
		{ 0, -1 },
		{ -1, -1 },
		{ -1, 0 },
		{ -1, 1 },
	};

	int count = 0;
	for (auto d : delta) {
		count += reverse(x, y, d[0], d[1], execute);
	}
	return count;
}

int Board::reverse(int x, int y, int dx, int dy, bool execute)
{
	State self = turn == Turn::BLACK ? State::BLACK : State::WHITE;
	State other = turn == Turn::BLACK ? State::WHITE : State::BLACK;

	int count = 0;
	for (x += dx, y += dy; x >= 0 && x < width && y >= 0 && y < height; x += dx, y += dy) {
		if (state[y][x] == other) {
			count++;
		}
		else if (state[y][x] == self) {
			if (execute) {
				for (x -= dx, y -= dy; x >= 0 && x < 8 && y >= 0 && y < 8; x -= dx, y -= dy) {
					if (state[y][x] == other) state[y][x] = self;
					else break;
				}
			}
			return count;
		}
		else {
			return 0;
		}
	}

	return 0;
}

bool Board::putStone(int x, int y)
{
	if (state[y][x] == State::POSSIBLE) {
		reverse(x, y);
		if (nextTurn() == false) {
			if (nextTurn() == false) {
				end = true;
			}
		}

		return true;
	}

	return false;
}

void Board::getScore(int& b, int& w) const
{
	b = black;
	w = white;
}