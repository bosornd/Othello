#include "Stone.h"
using namespace bangtal;

#include "config.h"
#include "Othello.h"

StonePtr Stone::create(OthelloPtr othello, int ix, int iy, bool shown)
{
	auto stone = StonePtr(new Stone(othello, ix, iy, shown));
	Object::add(stone);

	return stone;
}

Stone::Stone(OthelloPtr scene, int x, int y, bool shown)
	: Object(IMAGE_STONE_BLANK, scene, BOARD_INIT_X + STONE_SIZE_X * x, BOARD_INIT_Y + STONE_SIZE_Y * y, shown),
	  othello(scene), ix(x), iy(y), state(State::NONE)
{
}

void Stone::setState(Turn turn, State s)
{
	state = s;
	switch (state) {
		case State::BLACK: setImage(IMAGE_STONE_BLACK); break;
		case State::WHITE: setImage(IMAGE_STONE_WHITE); break;
		case State::POSSIBLE: turn == Turn::BLACK ? setImage(IMAGE_STONE_BLACK_POSSIBLE) : setImage(IMAGE_STONE_WHITE_POSSIBLE); break;
		default: setImage(IMAGE_STONE_BLANK); break;
	}
}

bool Stone::onMouse(int x, int y, MouseAction action)
{
	if (state == State::POSSIBLE) {
		return othello->onClick(ix, iy);
	}
	return false;
}