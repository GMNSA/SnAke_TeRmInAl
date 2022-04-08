/* snake_game_end.c */

#include "snake_game_end.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_struct.h"
#include "work_with_files.h"
#include "f_log_file.h"

void display_end() {
	printf("GAME OVER\n");
	char *text = read_file("data/scores.txt");

	s_list_gamer *lst = NULL;

	// G_SCOPE = 30;
	lst = split_text_list_gamer(text);
	printf("Youre score %d\n", G_SCOPE);
	s_gamer gamer = {"", G_SCOPE};

	char *name = NULL;
	if (is_more_score_list_gamer(lst, &gamer)) {
		printf("Enter the name: ");
		name = input_text();
		strncpy(gamer.name, name, 2);
		gamer.score = G_SCOPE;
		printf("name: %s\n", gamer.name);
		printf("score: %d\n", gamer.score);
		add_list_gamer(&lst, name, G_SCOPE);
		printf("\n");
		output_list_gamer(lst);
		free_list_gamer(lst);
		free(text);
	}
	press_on_key();
}

