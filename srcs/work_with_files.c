/* work_with_files.c */

#include "work_with_files.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "f_log_file.h"

const char *G_FILENAME_ABOUT = "about.txt";
const char *G_FILENAME_SCORES = "data/scores.txt";

char *read_file(char const *filename_) {
	FILE *fio = NULL;
	char *text = NULL;
	long size = 0;
	if (filename_ == NULL) {
		filename_ = G_FILENAME_ABOUT;
	}

	fio = fopen(filename_, "r");

	if (fio == NULL) {
		G_ERROR_LOG = ERROR_LOG_READ_FILE;
		create_log("Did't read from file about.txt [!!!ERROR!!!]", NULL);
	} else {
		fseek(fio, 0L, SEEK_END);
		size = ftell(fio);
		fseek(fio, 0L, SEEK_SET);

		if (!(text = (char *)calloc(size + 1, sizeof(char)))) {
			G_ERROR_LOG = ERROR_LOG_CREATE_DYNAMIC_ARRAY;
			create_log(NULL, NULL);
		} else {
			fread(text, sizeof(char), size, fio);
		}
		fclose(fio);
	}
	return (text);
}

// -------------------------------------------------------

char *input_text() {
	char c;
	int end = -1;
	char *text = (char *)calloc(MAX_SIZE_NAME + 1, sizeof(char));
	int limit = MAX_SIZE_NAME / 2;

	while ((c = getchar()) != '\n') {
		if (c == EOF) {
			G_ERROR_LOG = ERROR_LOG_CTRL_D;
			create_log(NULL, NULL);
		}
		if (++end >= limit) {
			break;
		} else {
			text[end] = c;
		}
	}

	if (strlen(text) == 0) {
		strncpy(text, "unknown", MAX_SIZE_NAME);
	}
	return (text);
}

// -------------------------------------------------------

void write_to_file_list_gamer(s_list_gamer *lst_, char const *filename_) {
	FILE *fin = NULL;

	if (lst_ == NULL) {
		G_ERROR_LOG = ERROR_LOG_WRITE_FILE;
		create_log("Error write to file (s_list_gamer) <--> NULL ", NULL);
	}

	if (filename_ == NULL) {
		filename_ = G_FILENAME_SCORES;
	}

	fin = fopen(filename_, "w");

	if (fin) {
		while (lst_) {
			fprintf(fin, "%s %d\n", lst_->gamer->name, lst_->gamer->score);
			lst_ = lst_->next;
		}
		fclose(fin);
	} else {
		G_ERROR_LOG = ERROR_LOG_WRITE_FILE;
		create_log(NULL, NULL);
	}
}
