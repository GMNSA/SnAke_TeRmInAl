/* work_with_files.h */

#ifndef SRC_WORK_WITH_FILES_H_
#define SRC_WORK_WITH_FILES_H_

#define MAX_SIZE_NAME 10

#include "snake_options_game.h"
#include "my_struct.h"

char *read_file(char const *filename_);
void write_to_file_list_gamer(s_list_gamer *lst_, char const *filename_);
char *input_text();

#endif  // SRC_WORK_WITH_FILES_H_
