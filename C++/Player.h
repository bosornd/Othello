#pragma once

#include "Othello.h"

class Player
{
public:
	Player(OthelloPtr othello);

	virtual bool onTurn();
	virtual bool onClick(int x, int y);

protected:
	OthelloPtr othello;
};

