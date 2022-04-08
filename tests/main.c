#include <stdio.h>
#include <stdlib.h>
#include "snake_game.h"
#include "snake_game_about.h"
#include "snake_game_processing.h"
#include "snake_game_end.h"
#include "snake_game_end.h"
#include "work_with_files.h"
#include "my_struct.h"
#include <assert.h>

void output_array(int **arr_, int row_, int col_);
int **create_array(int row_, int col_);

void test_snake_about();
void test_random_eat();
void test_display_end();
void test_my_struct();
void test_is_more_score_list_gamer();
void test_pop_less_score_list_gamer();
void test_size_list_gamer();
void test_sort_list_gamer();
void test_split_text_list_gamer();

int main(void) {
#ifdef 	_TEST_1
	 test_snake_about();
#endif	// _SNAKE_ABOUT_
		
#ifdef 	_TEST_2
	 test_random_eat();
#endif	// _RANDOM_EAT_

#ifdef 	_TEST_3
	test_display_end();
#endif 	// _DISPLAY_END_
	
#ifdef 	_TEST_4
	test_my_struct();
#endif  // _MY_STRUCT_
	
#ifdef 	_TEST_5
	test_is_more_score_list_gamer();
#endif  // _IS_MORE_SCORE_

#ifdef 	_TEST_6
	test_size_list_gamer();
#endif	// _IS_SIZE_LIST_

#ifdef 	_TEST_7
	test_pop_less_score_list_gamer();
#endif 	// _POP_LESS_SCORE_

#ifdef 	_TEST_8
	test_sort_list_gamer();
#endif 	// _POP_LESS_SCORE_

#ifdef 	_TEST_9
	test_split_text_list_gamer();
#endif 	// _POP_LESS_SCORE_

#ifdef _TEST_
	printf("Enter TEST=(1-7)\n");
#endif 	// _TEST
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
	printf("TEST snake_about OK\n");
}

// -------------------------------------------------------

void test_random_eat() {
	add_random_eat();
	printf("TEST random_eat OK\n");
}

// -------------------------------------------------------

void test_display_end() {
	display_end();
	printf("TEST display end OK\n");
}

// -------------------------------------------------------

void test_pop_less_score_list_gamer() {
	s_list_gamer *lst = NULL;

	add_list_gamer(&lst, "Polina", 32);
	add_list_gamer(&lst, "Gagarin", 80);
	add_list_gamer(&lst, "PomElO", 13);
	output_list_gamer(lst);
	printf("\n");
	lst = pop_list_gamer(lst);
	lst = pop_list_gamer(lst);
	lst = pop_list_gamer(lst);
	printf("\n");
	output_list_gamer(lst);
	free_list_gamer(lst);

	if (size_list_gamer(lst) == 0) {
		printf("OK\n");
	} else {
		printf("FAIL\n");
	}
	printf("TEST pop_less_score_list_gamer OK\n");
}

// -------------------------------------------------------

void test_my_struct() {
	s_list_gamer *lst = NULL;

	add_list_gamer(&lst, "Polina", 32);
	// add_list_gamer(&lst, "Gagarin", 80);
	// add_list_gamer(&lst, "PomElO", 13);

	if (lst == NULL) 
		printf("!!!NULL\n");
	output_list_gamer(lst);
	free_list_gamer(lst);
	printf("TEST my_struct OK\n");
}

// -------------------------------------------------------

void test_is_more_score_list_gamer() {

	s_list_gamer *lst = NULL;
	s_gamer gamer = {"Piter", 14};

	add_list_gamer(&lst, "Polina", 32);
	add_list_gamer(&lst, "Gagarin", 80);
	add_list_gamer(&lst, "PomElO", 13);

	int res = is_more_score_list_gamer(lst, &gamer);
	assert(res == 1);
	if (res == 1) {
		printf("OK\n");
	} else {
		printf("Fail\n");
	}

	printf("test_is_more_score_list_gamer OK\n");
}

// -------------------------------------------------------

void test_size_list_gamer() {
	s_list_gamer *lst = NULL;
	int n_lst = 0;

	n_lst = size_list_gamer(lst);

	if (n_lst == 0) {
		printf("OK\n");
	} else {
		printf("FAIL\n");
	}

	add_list_gamer(&lst, "Polina", 32);
	add_list_gamer(&lst, "Gagarin", 80);
	add_list_gamer(&lst, "PomElO", 13);

	n_lst = size_list_gamer(lst);

	if (n_lst == 3) {
		printf("OK\n");
	} else {
		printf("FAIL\n");
	}

	printf("test size list_gamer OK\n");
}

// -------------------------------------------------------

void test_sort_list_gamer() {
	s_list_gamer *lst = NULL;
	add_list_gamer(&lst, "Polina", 32);
	add_list_gamer(&lst, "Gagarin", 80);
	add_list_gamer(&lst, "PomElO", 13);
	add_list_gamer(&lst, "Garik", 52);
	add_list_gamer(&lst, "Salo", 77);
	add_list_gamer(&lst, "Minka", 17);
	add_list_gamer(&lst, "Villa", 197);

	output_list_gamer(lst);
	printf("\nSorted \n");
	sort_list_gamer(&lst);
	output_list_gamer(lst);
	free_list_gamer(lst);
}

// -------------------------------------------------------

void test_split_text_list_gamer() {
	char *text = read_file("data/scores.txt");
	s_list_gamer *scores = split_text_list_gamer(text);
	output_list_gamer(scores);
	printf("split test_list_gamer OK\n");
	free_list_gamer(scores);
	if (text) {
		free(text);
	}
}
