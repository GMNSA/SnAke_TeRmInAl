/* snake_game_about.c */

#include "snake_game_about.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "f_log_file.h"
#include "my_sleep.h"

const char *G_FILENAME_ABOUT = "about.txt";

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
		printf("read ok\n");
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

void display_about(char *text_) {
	unsigned n_text = strlen(text_);
	char c = '\n';
	for (unsigned i = 0; i < n_text; ++i) {
		printf("%c", text_[i]);
		sleep_us(1000);
	}
	printf("\nPRESS ON KEY");
	while ((c = getchar() != '\n')) {
	}
}
