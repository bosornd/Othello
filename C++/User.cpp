#include "User.h"

User::User(OthelloPtr othello) : Player(othello), turn(false)
{

}

bool User::onTurn()
{
	turn = true;
	return Player::onTurn();
}

bool User::onClick(int x, int y)
{
	if (turn) {
		if (othello->putStone(x, y))
			turn = false;

		return true;
	}

	return Player::onClick(x, y);
}