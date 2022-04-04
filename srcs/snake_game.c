#include "snake_game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "snake_game_menu.h"
#include "my_sleep.h"

int G_FIELD_WIDTH = 80;
int G_FIELD_HEIGHT = 25;

e_game_state G_GAME_CURRENT_STATE = GAME_STATE_INIT;
e_game_state transfowramtion_from_menu_to_game_state(int menu_);

void game() {
	int is_run = 1;

	while (is_run) {
		switch (G_GAME_CURRENT_STATE) {
			case GAME_STATE_INIT:
				game_init();
				G_GAME_CURRENT_STATE = GAME_STATE_MENU;
				break;
			case GAME_STATE_PROCESSING:
				game_processing();
				break;
			case GAME_STATE_MENU:
				game_menu();
				break;
			case GAME_STATE_ABOUT:
				game_about();
				break;
			case GAME_STATE_EXIT:
				game_exit();
				is_run = 0;
				break;
		}
		sleep_us(100000);
	}
}

// -------------------------------------------------------

void game_init() {
	printf("INIT\n");
}

void game_processing() {
	printf("START\n");
}

void game_menu() {
	snake_menu();
	G_GAME_CURRENT_STATE = transfowramtion_from_menu_to_game_state(menu_selection());
}

void game_about() {
	printf("about\n");
}

void game_exit() {
	printf("EXIT\n");
}

// -------------------------------------------------------

e_game_state transfowramtion_from_menu_to_game_state(int menu_) {
	e_game_state result;
	if (menu_  == SNAKE_MENU_START_GAME) {
		result = GAME_STATE_PROCESSING;
	} else if (menu_ ==  SNAKE_MENU_ABOUT_GAME) {
		result = GAME_STATE_ABOUT;
	} else if (menu_ == SNAKE_MENU_EXIT_GAME) {
		result = GAME_STATE_EXIT;
	} else {
		result = GAME_STATE_MENU;
	}
	return (result);
}
