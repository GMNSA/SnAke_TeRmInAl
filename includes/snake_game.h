#ifndef SRC_SNAKE_GAME_H_
#define SRC_SNAKE_GAME_H_

#include "snake_options_game.h"

extern unsigned G_SPEED_LOOP;

typedef enum {
	GAME_STATE_INIT = 0,
	GAME_STATE_PROCESSING,
	GAME_STATE_MENU,
	GAME_STATE_SCORES,
	GAME_STATE_ABOUT,
	GAME_STATE_EXIT,
	GAME_STATE_END_GAME
} e_game_state;

extern e_game_state G_GAME_CURRENT_STATE;

void game();
void game_init();
void game_processing();
void game_menu();
void game_scores();
void game_about();
void game_exit();
void game_end_game();

#endif // SRC_SNAKE_GAME_H_
