#include "config.h"

#include <iostream>

#include "Othello.h"
#include "Stone.h"
#include "Number.h"
#include "Player.h"

using namespace bangtal;
using namespace std;

OthelloPtr Othello::create(const std::string& name)
{
	auto othello = OthelloPtr(new Othello(name));
	Scene::add(name, othello);

	for (int y = 0; y < othello->data.height; y++) {
		for (int x = 0; x < othello->data.width; x++) {
			othello->board[y][x] = Stone::create(othello, x, y);
		}
	}

	othello->number[0] = Number::create(othello, NUMBER11_X, NUMBER_Y, false);
	othello->number[1] = Number::create(othello, NUMBER12_X, NUMBER_Y, false);
	othello->number[2] = Number::create(othello, NUMBER21_X, NUMBER_Y, false);
	othello->number[3] = Number::create(othello, NUMBER22_X, NUMBER_Y, false);

	othello->turn = Object::create(IMAGE_TURN_BLACK, othello, TURN_X, TURN_Y);

	return othello;
}

Othello::Othello(const std::string& name) : Scene(name, IMAGE_BACKGROUND)
{
	timer = Timer::create(TIMER_TURN);
	timer->setOnTimerCallback([&](auto timer)->bool {
		if (data.getTurn() == Turn::BLACK) blackPlayer->onTurn();
		else whitePlayer->onTurn();

		return true;
	});
}

bool Othello::onEnter()
{
	if (Scene::onEnter()) return true;

	data.init();		// initialize board data
	update();

	return true;
}

bool Othello::onLeave()
{
	if (Scene::onLeave()) return true;

	timer->stop();

	return true;
}

bool Othello::putStone(int x, int y)
{
	if (data.putStone(x, y)) {
		update();

		return true;
	}
	return false;
}

void Othello::update()
{
	// update board
	for (int y = 0; y < data.height; y++) {
		for (int x = 0; x < data.width; x++) {
			board[y][x]->setState(data.getTurn(), data.getState(x, y));
		}
	}

	// update score
	int black, white;
	data.getScore(black, white);

	number[0]->setNumber(black / 10 > 0 ? black / 10 : -1);
	number[1]->setNumber(black % 10);
	number[2]->setNumber(white / 10 > 0 ? white / 10 : white);
	number[3]->setNumber(white / 10 > 0 ? white % 10 : -1);

	// update turn
	if (data.isEnd()) {
		turn->hide();
		onGameEnd();
	}
	else {
		turn->setImage(data.getTurn() == Turn::BLACK ? IMAGE_TURN_BLACK : IMAGE_TURN_WHITE);
	}

	timer->set(TIMER_TURN);
	timer->start();
}

void Othello::setPlayer(Turn turn, Player* player)
{
	if (turn == Turn::BLACK) blackPlayer = player;
	else whitePlayer = player;
}


bool Othello::onClick(int x, int y)
{
	if (data.getTurn() == Turn::BLACK) blackPlayer->onClick(x, y);
	else whitePlayer->onClick(x, y);

	return true;
}

bool Othello::onGameEnd()
{
	if (onGameEndCallback) {
		return onGameEndCallback(std::dynamic_pointer_cast<Othello>(getScene(ID())));
	}
	return false;
}

void Othello::setOnGameEndCallback(std::function<bool(OthelloPtr)> callback)
{
	onGameEndCallback = callback;
}