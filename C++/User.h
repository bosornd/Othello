#pragma once

#include "Player.h"

class User : public Player
{
public:
	User(OthelloPtr othello);

	bool onTurn();
	bool onClick(int x, int y);

private:
	bool turn;
};

