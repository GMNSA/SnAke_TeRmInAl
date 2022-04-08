/* snake_game_scores.c */

#include "snake_game_scores.h"
#include "f_log_file.h"
#include "work_with_files.h"
#include "my_struct.h"
#include <stdio.h>

void display_scores() {
	char *text = read_file("data/scores.txt");
	
	s_list_gamer *scores = split_text_list_gamer(text);
	output_list_gamer(scores);
	free_list_gamer(scores);

	press_on_key();
}
