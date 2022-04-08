#ifndef SRC_F_LOG_FILE_H_
#define SRC_F_LOG_FILE_H_

typedef enum {
	ERROR_LOG_OK = 0,
	ERROR_LOG_CREATE_DYNAMIC_ARRAY ,
	ERROR_LOG_READ_FILE,
	ERROR_LOG_STACK_LIST_GAMER_DYNAMIC_ARRAY,
	ERROR_LOG_CTRL_D
} e_log_error;

void create_log(char const *text_, char const *filename_);

extern e_log_error G_ERROR_LOG;

void press_on_key();

#endif // SRC_F_LOG_FILE_H_
