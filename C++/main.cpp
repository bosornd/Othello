#include "config.h"

#include "Othello.h"
#include "User.h"
#include "Computer.h"
#include "Computer2.h"

#include <ctime>

using namespace bangtal;

ScenePtr scene;
OthelloPtr othello = Othello::create();

/*
* Android에서는 main() 함수가 종료된 다음에 게임이 동작하므로
* main() 함수의 로컬 변수는 메모리에서 제거된다.
* ==> 글로벌 변수로 선언되어야 한다.
*/
User user1(othello), user2(othello);
Computer computer1(othello);
Computer2 computer2(othello);

ObjectPtr game1, game2, game3, end;

int main() {
	srand(time_t(NULL));

	setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

    scene = Scene::create("오델로 게임", IMAGE_GAME);

	game1 = Object::create(IMAGE_GAME_1, scene, 450, 200);
	game1->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
		othello->setPlayer(Turn::BLACK, &user1);
		othello->setPlayer(Turn::WHITE, &user2);
		othello->enter();

		return true;
	});

	game2 = Object::create(IMAGE_GAME_2, scene, 450, 120);
	game2->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
		othello->setPlayer(Turn::BLACK, &user1);
		othello->setPlayer(Turn::WHITE, &computer1);
		othello->enter();

		return true;
	});

	game3 = Object::create(IMAGE_GAME_3, scene, 450, 40);
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

	end = Object::create(IMAGE_GAME_END, othello, 1100, 20);
	end->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
		scene->enter();

		return true;
	});

	startGame(scene);
}