#include <stdio.h>
#include <stdlib.h>
#include "snake_game.h"
#include "snake_game_about.h"

void output_array(int **arr_, int row_, int col_);
int **create_array(int row_, int col_);

void test_snake_about();

int main(void) {
	test_snake_about();
	return 0;
}

void output_array(int **arr_, int row_, int col_) {
	for (int i = 0; i < row_; i++) {
		for (int j = 0; j < col_; j++) {
			printf("%d ", *(*(arr_ + j) + i));
		}
		printf("\n");
	}
}

int **create_array(int row_, int col_) {
	int **arr = (int **)malloc(row_ * col_ * sizeof(int) + row_ * sizeof(int *));
	int *p = (int *)(arr + row_);

	for (int i = 0; i < row_; i++) {
		arr[i] = (p + col_ * i);
	}
	return (arr);
}

// -------------------------------------------------------

void test_snake_about() {
	char *text = read_file(NULL);
	display_about(text);

	free(text);
}

// -------------------------------------------------------

