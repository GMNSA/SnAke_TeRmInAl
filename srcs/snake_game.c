#include "snake_game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "f_log_file.h"
#include "my_sleep.h"
#include "snake_game_menu.h"
#include "snake_game_processing.h"
#include "snake_game_about.h"
#include "work_with_files.h"
#include "snake_game_scores.h"
#include "snake_game_end.h"

unsigned G_SPEED_LOOP = DEFAULT_SPEED;
e_game_state G_GAME_CURRENT_STATE = GAME_STATE_INIT;
e_game_state transfowramtion_from_menu_to_game_state(int menu_);

// -------------------------------------------------------

void update();
void draw();

// -------------------------------------------------------

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
			case GAME_STATE_SCORES:
				game_scores();
				break;
			case GAME_STATE_ABOUT:
				game_about();
				break;
			case GAME_STATE_EXIT:
				game_exit();
				is_run = 0;
				break;
			case GAME_STATE_END_GAME:
				game_end_game();
				break;
			default:
				G_GAME_CURRENT_STATE = GAME_STATE_INIT;
				break;
		}
		sleep_us(G_SPEED_LOOP);
	}
}

// -------------------------------------------------------

void game_init() {
	reset_field_game();
	reset_snake();
}

void game_processing() {
	draw();
	update();
}

void game_menu() {
	snake_menu();
	G_GAME_CURRENT_STATE = 
		transfowramtion_from_menu_to_game_state(menu_selection());
}

void game_about() {
	char *text = read_file(NULL);
	system("clear");
	display_about(text);
	if (text) {
		free(text);
	}
	G_GAME_CURRENT_STATE = GAME_STATE_INIT;
}

void game_scores() {
	system("clear");
	printf("The best scores (*)(*)  <---------   >>>>\n\n");
	display_scores();
	G_GAME_CURRENT_STATE = GAME_STATE_MENU;
}

void game_exit() {
	system("clear");
	printf("EXIT\n");
}

void game_end_game() {
	display_end();
	G_GAME_CURRENT_STATE = GAME_STATE_INIT;
}

// -------------------------------------------------------

e_game_state transfowramtion_from_menu_to_game_state(int menu_) {
	e_game_state result;
	if (menu_  == SNAKE_MENU_START_GAME) {
		result = GAME_STATE_PROCESSING;
	} else if (menu_ ==  SNAKE_MENU_SCORES_GAME) {
		result = GAME_STATE_SCORES;
	} else if (menu_ ==  SNAKE_MENU_ABOUT_GAME) {
		result = GAME_STATE_ABOUT;
	} else if (menu_ == SNAKE_MENU_EXIT_GAME) {
		result = GAME_STATE_EXIT;
	} else {
		result = GAME_STATE_MENU;
	}
	return (result);
}

// -------------------------------------------------------

void update() {
	move_snake();
	input_direction_snake();
	add_random_eat(); 
	if (check_collizion()) {
		G_GAME_CURRENT_STATE = GAME_STATE_END_GAME;  // remove
	}
}

// -------------------------------------------------------

void draw() {
	system("clear");
	draw_information();
	draw_game_field();
}
