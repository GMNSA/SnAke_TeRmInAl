/* my_struct.h */

#ifndef SRC_MY_STRUCT_H_
#define SRC_MY_STRUCT_H_

#define MAX_NAME_GAMER 10

typedef struct s_gamer {
	char name[MAX_NAME_GAMER];
	unsigned score;
} s_gamer;

typedef struct 				s_list_gamer {
	s_gamer 				*gamer;
	struct s_list_gamer 	*next;
} 							s_list_gamer;

s_list_gamer *init_list_gamer(s_gamer *gamer_);
s_list_gamer *add_list_gamer(s_list_gamer **list_,
		const char *name_, unsigned score_);
s_list_gamer *free_list_gamer(s_list_gamer *list_);
s_list_gamer *sort_list_gamer(s_list_gamer **head_);

int is_more_score_list_gamer(s_list_gamer *list_, s_gamer *gamer_);

s_list_gamer *pop_list_gamer(s_list_gamer *lst_);
int size_list_gamer(s_list_gamer *lst_);

void output_list_gamer(s_list_gamer *list_);
void output_gamer(s_gamer *gamer_);

s_list_gamer *split_text_list_gamer(char *text_);

#endif  // SRC_MY_STRUCT_H_
