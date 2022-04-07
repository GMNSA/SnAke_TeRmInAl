/* snake_game_end.c */

#include "snake_game_end.h"
#include <stdio.h>
#include <stdlib.h>
#include "my_struct.h"
#include "work_with_files.h"
#include <string.h>

void display_end() {
	char c;
	printf("GAME OVER\n");
	char *text = read_file("data/scores.txt");

	char *p = text;
	int n_n = 0;;
	int begin = 0;
	int end = 0;;
	s_list_gamer *lst = NULL;

	while (*p != '\0') {
		++end;
		if (*p == '\n') {
			add_to_list(&lst, text, begin, end);
			++n_n;
			begin = end;
		}
		++p;
	}

	G_SCOPE = 30;
	printf("Youre score %d\n", G_SCOPE);
	s_gamer gamer = {"", G_SCOPE};

	char *name = NULL;
	if (is_more_score_list_gamer(lst, &gamer)) {
		printf("Enter the name: ");
		 name = input_text();
		strncpy(gamer.name, name, MAX_SIZE_NAME);
		gamer.score = G_SCOPE;
		printf("name: %s\n", gamer.name);
		printf("score: %d\n", gamer.score);
		add_list_gamer(&lst, name, G_SCOPE);
		printf("\n");
		output_list_gamer(lst);
		free_list_gamer(lst);
		free(text);
	}

	printf("\nPRESS ON KEY");
	while ((c = getchar() != '\n') ) {
	}
}

void add_to_list(s_list_gamer **lst_,
		char *text_,
		unsigned begin_,
		unsigned end_) {
	char name[30] = {"\0"};
	char score[30] = {"\0"};;
	int is_score = 0;
	int begin_name = -1;
	int begin_score = -1;

	for (; begin_ < end_; ++begin_) {
		if (!is_score ) {
			if (text_[begin_] != ' ') {
				name[++begin_name] = text_[begin_];
			} else {
				is_score = 1;
			}
		} else {
			score[++begin_score] = text_[begin_];
		}
	}
	add_list_gamer(lst_, name, atoi(score));
}
