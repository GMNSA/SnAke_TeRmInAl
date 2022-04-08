/* snake_game_about.c */

#include "snake_game_about.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "f_log_file.h"
#include "my_sleep.h"


void display_about(char *text_) {
	unsigned n_text = strlen(text_);
	for (unsigned i = 0; i < n_text; ++i) {
		printf("%c", text_[i]);
		sleep_us(1000);
	}
	press_on_key();
}
