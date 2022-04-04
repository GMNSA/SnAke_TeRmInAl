#include "snake_game_menu.h"
#include <stdio.h>
#include <stdlib.h>
#include "my_sleep.h"
#include "f_input.h"

int G_SNAKE_MENU_CURRENT_STATE = SNAKE_MENU_START_GAME;

char const *G_SNAKE_MENU[SNAKE_MENU_END] = {
	"Start Menu",
	"About",
	"Exit"
};

void snake_menu_to_upper_snake(char *text_);
void snake_menu_move(int *run_);

void snake_menu() {
	int is_run = 1;

	while (is_run) {
		system("clear");
		for (int i = 0; i < SNAKE_MENU_END; ++i) {
			if ((int)G_SNAKE_MENU_CURRENT_STATE == i) {
				snake_menu_to_upper_snake((char *)G_SNAKE_MENU[i]);
			} else {
				printf("%s\n", G_SNAKE_MENU[i]);
			}
		}
		snake_menu_move(&is_run);
		sleep_us(50000);
	}
}

void snake_menu_to_upper_snake(char *text_) {
	char *p = text_;
	char c;

	for (; *p != '\0'; ++p) {
		c = *p;
		if (*p >= 'a' && *p <= 'z') {
			c -= 32;
		}
		printf("%c", c);
	}
	printf("\n");
}

void snake_menu_move(int *run_) {
	e_key_code key = key_input();

	if (key == KEY_UP) {
		if (G_SNAKE_MENU_CURRENT_STATE > 0) {
			--G_SNAKE_MENU_CURRENT_STATE;
		} else {
			G_SNAKE_MENU_CURRENT_STATE = SNAKE_MENU_EXIT_GAME;
		}
	}

	if (key == KEY_DOWN) {
		if (G_SNAKE_MENU_CURRENT_STATE < SNAKE_MENU_EXIT_GAME) {
			++G_SNAKE_MENU_CURRENT_STATE;
		} else {
			G_SNAKE_MENU_CURRENT_STATE = SNAKE_MENU_START_GAME;
		}
	}

	if (key == KEY_ENTER){
		*run_ = 0;
	}
}

int menu_selection() {
	return (G_SNAKE_MENU_CURRENT_STATE);
}
