/* snake_game_processing.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "f_input.h"
#include "snake_game_processing.h"

s_field_game G_FIELD_GAME[D_GAME_WIDTH][D_GAME_HEIGHT] = {0};
s_snake G_SNAKE;
unsigned G_SCOPE = 0;

void output_game_field();
void check_field_boards();
void default_speed();
void decrement_speed();

void draw_game_field(){
	output_game_field();
}

void draw_information() {
	printf("score: %d\n", G_SCOPE);
}

// -------------------------------------------------------

void output_game_field() {
	for (int j = 0; j < D_GAME_HEIGHT; j++) {
		for (int i = 0; i < D_GAME_WIDTH; i++) {
			if (G_FIELD_GAME[i][j].lifecell == G_SNAKE.length) {
				printf("0");
			} else if (G_FIELD_GAME[i][j].lifecell > 0) {
				printf("o");
				// printf("%d", G_FIELD_GAME[i][j].lifecell);
			} else if (G_FIELD_GAME[i][j].eat > 0) {
				printf("#");
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
			G_FIELD_GAME[x][y].eat = 0;
		}
	}
}

void reset_snake() {
	G_SNAKE.length = 9;
	G_SNAKE.dir_x = 1;
	G_SNAKE.dir_y = 0;
	G_SNAKE.pos_x = D_GAME_WIDTH / 2;
	G_SNAKE.pos_y = D_GAME_HEIGHT / 2;

	// unsigned n_size_snake = G_SNAKE.length;

	// for (unsigned i = 1; i <= n_size_snake; ++i) {
	// 	G_FIELD_GAME[G_SNAKE.pos_x + i][G_SNAKE.pos_y].lifecell = i;
	// }
	// for (unsigned i = n_size_snake; i > 0; --i) {
	// 	G_FIELD_GAME[G_SNAKE.pos_x + i][G_SNAKE.pos_y].lifecell = i;
	// }
}

// -------------------------------------------------------

void move_snake() {
	for (int y = 0; y < D_GAME_HEIGHT; y++) {
		for (int x = 0; x < D_GAME_WIDTH; x++) {
			if (G_FIELD_GAME[x][y].lifecell > 0) {
				--G_FIELD_GAME[x][y].lifecell;
			}
			if (G_FIELD_GAME[x][y].eat == 1 
					&& G_FIELD_GAME[x][y].lifecell > 1) {
				G_FIELD_GAME[x][y].eat = 0;
				++G_SNAKE.length;
				G_SCOPE += 10;
			}

		}
	}

	check_collizion();

	G_SNAKE.pos_x += G_SNAKE.dir_x;
	G_SNAKE.pos_y += G_SNAKE.dir_y;

	check_field_boards();

	G_FIELD_GAME[G_SNAKE.pos_x][G_SNAKE.pos_y].lifecell = G_SNAKE.length;
}

// -------------------------------------------------------

void check_field_boards() {
	if (G_SNAKE.pos_x >= D_GAME_WIDTH) {
		G_SNAKE.pos_x = 0;
	} else if (G_SNAKE.pos_x < 0) {
		G_SNAKE.pos_x = D_GAME_WIDTH - 1;
	} else if (G_SNAKE.pos_y >= D_GAME_HEIGHT) {
		G_SNAKE.pos_y = 0;
	} else if (G_SNAKE.pos_y < 0) {
		G_SNAKE.pos_y = D_GAME_HEIGHT - 1;
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
		default_speed();
	}
}

// -------------------------------------------------------

void add_random_eat() {
	time_t t;
	unsigned x;
	unsigned y;
	int check_eat = 0;

	for (int y = 0; y < D_GAME_HEIGHT && check_eat != 1; ++y) {
		for (int x = 0; x < D_GAME_WIDTH && check_eat != 1; x++) {
			if (G_FIELD_GAME[x][y].eat == 1) {
				check_eat = 1;
			}
		}
	}

	if (!check_eat) {
		srand((unsigned)time(&t));

		x = rand() % D_GAME_WIDTH;
		y = rand() % D_GAME_HEIGHT;
		while (G_FIELD_GAME[x][y].lifecell != 0) {
			x = rand() % D_GAME_WIDTH;
			y = rand() % D_GAME_HEIGHT;
		}

		G_FIELD_GAME[x][y].eat = 1;
		decrement_speed();
	}
}

void default_speed() {
	G_SPEED_LOOP = 100000;
}

int check_collizion() {
	unsigned lifecell = 0;
	int result = 0;
	if ((G_SNAKE.pos_x + G_SNAKE.dir_x < D_GAME_WIDTH 
				&& G_SNAKE.pos_y + G_SNAKE.dir_y < D_GAME_HEIGHT) 
			&& (G_SNAKE.pos_x + G_SNAKE.dir_x >= 0  
				&& G_SNAKE.pos_y + G_SNAKE.dir_y >= 0)
	   ) {
		lifecell = G_FIELD_GAME[G_SNAKE.pos_x
			+ G_SNAKE.dir_x][G_SNAKE.pos_y 
			+ G_SNAKE.dir_y].lifecell;
		if ((lifecell > 0)) {
			printf("COLLIZION");
			result = 1;
		}
	}
	return (result);
}

void decrement_speed() {
	if (G_SPEED_LOOP > 20000) {
		G_SPEED_LOOP -= 10000;
	} if (G_SPEED_LOOP > 15000) {
		G_SPEED_LOOP -= 2500;
	}
}
