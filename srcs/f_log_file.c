#include "f_log_file.h"
#include <stdio.h>
#include <time.h>

e_log_error G_ERROR_LOG = ERROR_LOG_OK;

const char *G_FILENAME = "log_file.txt";

void create_log(char const *text_, char const *filename_) {
	long ttime = time(0);
	char const *current_time = ctime(&ttime);
	FILE *fin = NULL;

	if (text_ == NULL) {
		if (G_ERROR_LOG == ERROR_LOG_CREATE_DYNAMIC_ARRAY) {
			text_= "Create Dynamic Array ERROR ";
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
}
