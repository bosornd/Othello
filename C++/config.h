#pragma once

#ifdef WIN32
#define IMAGE_PATH					"../Images/"
#else
#define IMAGE_PATH
#endif

#define IMAGE_GAME					IMAGE_PATH "othello.png"
#define IMAGE_GAME_1				IMAGE_PATH "game1.png"
#define IMAGE_GAME_2				IMAGE_PATH "game2.png"
#define IMAGE_GAME_3				IMAGE_PATH "game3.png"
#define IMAGE_GAME_END				IMAGE_PATH "game end.png"

#define IMAGE_BACKGROUND			IMAGE_PATH "background.png"
#define IMAGE_STONE_BLANK			IMAGE_PATH "blank.png"
#define IMAGE_STONE_BLACK			IMAGE_PATH "black.png"
#define IMAGE_STONE_WHITE			IMAGE_PATH "white.png"
#define IMAGE_STONE_BLACK_POSSIBLE	IMAGE_PATH "black possible.png"
#define IMAGE_STONE_WHITE_POSSIBLE	IMAGE_PATH "white possible.png"
#define IMAGE_TURN_BLACK			IMAGE_PATH "black turn.png"
#define IMAGE_TURN_WHITE			IMAGE_PATH "white turn.png"

#define BOARD_INIT_X				40
#define BOARD_INIT_Y				40
#define STONE_SIZE_X				80
#define STONE_SIZE_Y				80

#define NUMBER11_X					750
#define NUMBER12_X					820
#define NUMBER21_X					1080
#define NUMBER22_X					1150
#define NUMBER_Y					220

#define TURN_X						920
#define TURN_Y						100

#define TIMER_TURN					1.f