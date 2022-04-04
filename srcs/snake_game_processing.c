/* snake_game_processing.c */

#include <stdio.h>
#include <stdlib.h>
#include "f_input.h"
#include "snake_game_processing.h"

s_field_game G_FIELD_GAME[D_GAME_WIDTH][D_GAME_HEIGHT] = {0};
s_snake G_SNAKE;

void output_game_field();
void check_field_boards();

void draw_game_field(){
	output_game_field();
}

void output_game_field() {
	system("clear");
	for (int j = 0; j < D_GAME_HEIGHT; j++) {
		for (int i = 0; i < D_GAME_WIDTH; i++) {
			if (G_FIELD_GAME[i][j].lifecell == G_SNAKE.length) {
				printf("0");
			} else if (G_FIELD_GAME[i][j].lifecell > 0) {
				printf("o");
				// printf("%d", G_FIELD_GAME[i][j].lifecell);
			} else {
				printf(".");
			}
		}
		printf("\n");
	}
}

void reset_field_game() {
	for (int y = 0; y < D_GAME_HEIGHT; y++) {
		for (int x = 0; x < D_GAME_WIDTH; x++) {
			G_FIELD_GAME[x][y].lifecell = 0;
		}
	}
}

void reset_snake() {
	G_SNAKE.length = 3;
	G_SNAKE.dir_x = 1;
	G_SNAKE.dir_y = 0;
	G_SNAKE.pos_x = D_GAME_WIDTH / 2;
	G_SNAKE.pos_y = D_GAME_HEIGHT / 2;

	for (unsigned i = 1; i <= G_SNAKE.length; ++i) {
		G_FIELD_GAME[G_SNAKE.pos_x + i][G_SNAKE.pos_y].lifecell = i;
	}
}

// -------------------------------------------------------

void move_snake() {
	for (int y = 0; y < D_GAME_HEIGHT; y++) {
		for (int x = 0; x < D_GAME_WIDTH; x++) {
			if (G_FIELD_GAME[x][y].lifecell > 0) {
				--G_FIELD_GAME[x][y].lifecell;
			}
		}
	}

	G_SNAKE.pos_x += G_SNAKE.dir_x;
	G_SNAKE.pos_y += G_SNAKE.dir_y;

	check_field_boards();

	G_FIELD_GAME[G_SNAKE.pos_x][G_SNAKE.pos_y].lifecell = G_SNAKE.length;
}

// -------------------------------------------------------

void check_field_boards() {
	if (G_SNAKE.pos_x >= D_GAME_WIDTH) {
		G_SNAKE.pos_x = 0;
	} else if (G_SNAKE.pos_x < 1) {
		G_SNAKE.pos_x = D_GAME_WIDTH;
	} else if (G_SNAKE.pos_y >= D_GAME_HEIGHT) {
		G_SNAKE.pos_y = 0;
	} else if (G_SNAKE.pos_y < 1) {
		G_SNAKE.pos_y = D_GAME_HEIGHT;
	}
}

// -------------------------------------------------------

void input_direction_snake() {
	e_key_code key = key_input();
	if (key == KEY_UP) {
		if (G_SNAKE.dir_y != 1) {
			G_SNAKE.dir_x = 0;
			G_SNAKE.dir_y = -1;
		}
	} else if (key == KEY_DOWN) {
		if (G_SNAKE.dir_y != -1) {
			G_SNAKE.dir_x = 0;
			G_SNAKE.dir_y = 1;
		}
	} else if (key == KEY_RIGHT) {
		if (G_SNAKE.dir_x != -1) {
			G_SNAKE.dir_x = 1;
			G_SNAKE.dir_y = 0;
		}
	} else if (key == KEY_LEFT) {
		if (G_SNAKE.dir_x != 1) {
			G_SNAKE.dir_x = -1;
			G_SNAKE.dir_y = 0;
		}
		/* Escape from game to menU */
	} else if (key == KEY_ESCAPE) {  
		G_GAME_CURRENT_STATE = GAME_STATE_INIT;
	}
}
