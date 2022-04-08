#include "f_log_file.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

e_log_error G_ERROR_LOG = ERROR_LOG_OK;

const char *G_FILENAME = "log_file.txt";

void create_log(char const *text_, char const *filename_) {
	long ttime = time(0);
	char const *current_time = ctime(&ttime);
	FILE *fin = NULL;

	if (text_ == NULL) {
		if (G_ERROR_LOG == ERROR_LOG_CREATE_DYNAMIC_ARRAY) {
			text_= "Create Dynamic Array ERROR ";
		} else if (G_ERROR_LOG == ERROR_LOG_READ_FILE) {
			text_= "Error Read file ERROR ";
		} else if (G_ERROR_LOG == ERROR_LOG_STACK_LIST_GAMER_DYNAMIC_ARRAY) {
			text_ = "Error craete dynamic memory [list gamer] ";
		} else if (G_ERROR_LOG == ERROR_LOG_CTRL_D) {
			text_ = "Error ctrl + d ";
		} else {
			text_ = "Ok <----> ";
		}
	}

	if (filename_ == NULL) {
		filename_ = G_FILENAME;
	}

	fin = fopen(filename_, "a");

	if (fin) {
		fprintf(fin, "%s %s", text_, current_time);
		fclose(fin);
	}
	if (G_ERROR_LOG != ERROR_LOG_OK) {
		exit(-1);
	}
}

// -------------------------------------------------------

void press_on_key() {
	char c;

	printf("\nPRESS ON KEY");
	while ((c = getchar() != '\n') ) {
		if (c != EOF) {
			G_ERROR_LOG = ERROR_LOG_CTRL_D;
			create_log(NULL, NULL);
		}
	}
}
