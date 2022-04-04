#ifndef SRC_SNAKE_GAME_H_
#define SRC_SNAKE_GAME_H_

#include "snake_options_game.h"

typedef enum {
	GAME_STATE_INIT = 0,
	GAME_STATE_PROCESSING,
	GAME_STATE_MENU,
	GAME_STATE_ABOUT,
	GAME_STATE_EXIT
} e_game_state;

extern e_game_state G_GAME_CURRENT_STATE;

void game();
void game_init();
void game_processing();
void game_menu();
void game_about();
void game_exit();

#endif // SRC_SNAKE_GAME_H_
