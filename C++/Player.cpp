#include "Player.h"

Player::Player(OthelloPtr o) : othello(o)
{

}

bool Player::onTurn()
{
	return false;
}

bool Player::onClick(int x, int y)
{
	return true;
}