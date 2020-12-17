#pragma once
#include "Player.h"

class Computer2 : public Player
{
public:
	Computer2(OthelloPtr othello);

	bool onTurn();
};

