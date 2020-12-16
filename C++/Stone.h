#pragma once

#include "Othello.h"

class Stone;
typedef std::shared_ptr<Stone> StonePtr;

class Stone : public bangtal::Object
{
public:
	static StonePtr create(OthelloPtr othello, int ix, int iy, bool shown = true);

protected:
	Stone(OthelloPtr othello, int ix, int iy, bool shown);

public:
	void setState(Turn turn, State state);
	bool onMouse(int x, int y, MouseAction action);

private:
	OthelloPtr othello;
	int ix, iy;
	State state;
};

