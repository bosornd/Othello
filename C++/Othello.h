#pragma once
#include <bangtal>
#include "Board.h"

class Othello;
typedef std::shared_ptr<Othello> OthelloPtr;

class Stone;
typedef std::shared_ptr<Stone> StonePtr;

class Number;
typedef std::shared_ptr<Number> NumberPtr;

class Player;

class Othello : public bangtal::Scene
{
public:
	static OthelloPtr create(const std::string& name = "Othello Game");
	void setPlayer(Turn turn, Player* player);
	void setOnGameEndCallback(std::function<bool(OthelloPtr)> callback);

public:
	bool putStone(int x, int y);
	const Board& getBoard() const { return data; };

protected:
	Othello(const std::string& name);

	virtual bool onEnter();
	virtual bool onLeave();
	virtual bool onGameEnd();

friend Stone;
	bool onClick(int x, int y);
	void update();

private:
	Board data;
	StonePtr board[8][8];
	NumberPtr number[4];

	bangtal::ObjectPtr turn;
	std::function<bool(OthelloPtr)> onGameEndCallback = nullptr;

	bangtal::TimerPtr timer;

	Player* blackPlayer;
	Player* whitePlayer;
};

