#include "Computer2.h"

Computer2::Computer2(OthelloPtr othello) : Player(othello)
{
}

// simple greedy player
bool Computer2::onTurn()
{
	static const int WEIGHT = 5;

	const Board& board = othello->getBoard();

	int max = 0, tx, ty;
	for (int y = 0; y < board.height; ++y)
		for (int x = 0; x < board.width; ++x) {
			int c = board.getCount(x, y);
			// 가장 자리에 놓는 경우에 가중치를 둔다.
			if (c > 0) {
				if (x == 0 || x == board.width - 1) c += WEIGHT;
				if (y == 0 || y == board.height - 1) c += WEIGHT;
			}

			if (c > max || ((c == max) && rand() % 2)) {
				max = c;
				tx = x; ty = y;
			}
		}

	othello->putStone(tx, ty);

	return Player::onTurn();
}
