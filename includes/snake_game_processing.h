/* snake_game_processing.h */

#ifndef SRC_SNAKE_GAME_PROCESSING_H_
#define SRC_SNAKE_GAME_PROCESSING_H_

#include "f_input.h"
#include "snake_game.h"
#include "snake_options_game.h"

typedef struct {
	unsigned lifecell;
	unsigned eat;
} s_field_game;

typedef struct {
	int dir_x;
	int dir_y;
	int pos_x;
	int pos_y;
	unsigned length;
} s_snake;

extern s_field_game G_FIELD_GAME[D_GAME_WIDTH][D_GAME_HEIGHT];
extern s_snake G_SNAKE;

void reset_field_game();
void reset_snake();

void draw_game_field();
void draw_information();

void move_snake();
void input_direction_snake();
void add_random_eat();
int check_collizion();

#endif  // SRC_SNAKE_GAME_PROCESSING_H_
