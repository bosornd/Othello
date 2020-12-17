#include "config.h"

#include "Othello.h"
#include "User.h"
#include "Computer.h"
#include "Computer2.h"

#include <ctime>



using namespace bangtal;

int main() {
	srand(time_t(NULL));

	setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

	auto main = Scene::create("오델로 게임", IMAGE_GAME);
	auto othello = Othello::create();

	User user1(othello), user2(othello);
	Computer computer1(othello);
	Computer2 computer2(othello);

	auto game1 = Object::create(IMAGE_GAME_1, main, 450, 200);
	game1->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
		othello->setPlayer(Turn::BLACK, &user1);
		othello->setPlayer(Turn::WHITE, &user2);
		othello->enter();

		return true;
	});

	auto game2 = Object::create(IMAGE_GAME_2, main, 450, 120);
	game2->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
		othello->setPlayer(Turn::BLACK, &user1);
		othello->setPlayer(Turn::WHITE, &computer1);
		othello->enter();

		return true;
	});

	auto game3 = Object::create(IMAGE_GAME_3, main, 450, 40);
	game3->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
		othello->setPlayer(Turn::BLACK, &computer1);
		othello->setPlayer(Turn::WHITE, &computer2);
		othello->enter();

		return true;
	});

	othello->setOnGameEndCallback([&](auto othello) -> bool {
		showMessage("GAME ENDED!!!");
		return true;
	});

	auto end = Object::create(IMAGE_GAME_END, othello, 1100, 20);
	end->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
		main->enter();

		return true;
	});

	startGame(main);
}