#pragma once

enum class Turn : int {
	BLACK,
	WHITE
};

enum class State : int {
	BLACK,
	WHITE,
	POSSIBLE,
	NONE,
}; 

class Board
{
public:
	static const int width = 8;
	static const int height = 8;

public:
	Board();
	void init();
	bool putStone(int x, int y);

public:
	Turn getTurn() const { return turn; };
	State getState(int x, int y) const { return state[y][x]; };
	int getCount(int x, int y) const { return count[y][x]; };
	void getScore(int& black, int& white) const;
	bool isEnd() const { return end; };

private:
	Turn turn;
	State state[height][width];
	int count[height][width];
	int black, white;
	bool end;

private:
	bool nextTurn();
	int reverse(int x, int y, bool execute = true);
	int reverse(int x, int y, int dx, int dy, bool execute = true);
};

