#ifndef SRC_F_LOG_FILE_H_
#define SRC_F_LOG_FILE_H_

typedef enum {
	ERROR_LOG_OK = 0,
	ERROR_LOG_CREATE_DYNAMIC_ARRAY 
} e_log_error;

void create_log(char const *text_, char const *filename_);

extern e_log_error G_ERROR_LOG;

#endif // SRC_F_LOG_FILE_H_
