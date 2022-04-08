/* my_struct.c */

#include "my_struct.h"
#include <stdio.h>
#include <stdlib.h>
#include "f_log_file.h"
#include <string.h>

#define ft_unuased(num) (void)(num)
void add_to_list(s_list_gamer **lst_,
		char *text_,
		unsigned begin_,
		unsigned end_);

s_list_gamer *init_list_gamer(s_gamer *gamer_) {
	s_list_gamer *lst = NULL;
	if (!(lst = (s_list_gamer*)calloc(1, sizeof(s_list_gamer)))) {
		G_ERROR_LOG = ERROR_LOG_STACK_LIST_GAMER_DYNAMIC_ARRAY;
		create_log(NULL, NULL);
		exit(-1);
	}

	lst->gamer = (s_gamer *)calloc(1, sizeof(s_list_gamer));

	if (gamer_) {
		strncpy(lst->gamer->name, gamer_->name, MAX_NAME_GAMER);
		lst->gamer->score = gamer_->score;
		lst->next = NULL;
	} else {
		// TODO: ERROR
	}
	return (lst);
}


s_list_gamer *add_list_gamer(s_list_gamer **list_,
	const char *name_, unsigned score_) {
	s_list_gamer *lst = NULL;
	s_list_gamer *tmp = NULL;

	ft_unuased(tmp);
	ft_unuased(list_);

	s_gamer s;
	strncpy(s.name, name_, MAX_NAME_GAMER - 1);
	s.score = score_;
	
	if (*(list_) == NULL) {
		(*list_) = init_list_gamer(&s);
	} else {
		if (!(lst = (s_list_gamer*)calloc(1, sizeof(s_list_gamer)))) {
			G_ERROR_LOG = ERROR_LOG_STACK_LIST_GAMER_DYNAMIC_ARRAY;
			create_log(NULL, NULL);
			exit(-1);
		}

		lst->gamer = (s_gamer *)calloc(1, sizeof(s_list_gamer));

		tmp = *list_;
		strncpy(lst->gamer->name, s.name, MAX_NAME_GAMER);
		lst->gamer->score = s.score;
		lst->next = NULL;

		while (tmp->next) {
			tmp = tmp->next;
		}

		tmp->next = lst;
	} 

	return (lst);
}


s_list_gamer *sort_list_gamer(s_list_gamer **head_) {
	s_gamer *tmp = NULL;
	int end = 1;
	while (end) {
		end = 0;
		for (s_list_gamer *node = *head_; node->next; node = node->next) {
			if (node->gamer->score < node->next->gamer->score) {
				tmp = node->gamer;
				node->gamer = node->next->gamer;
				node->next->gamer = tmp;
				end = 1;
			}
		}
	}
	return (*head_);
}

int is_more_score_list_gamer(s_list_gamer *list_, s_gamer *gamer_) {
	int is_more = 0;
	while (list_) {
		if (gamer_->score > list_->gamer->score) {
			is_more = 1;
		}
		list_ = list_->next;
	}
	return (is_more);
}

s_list_gamer *pop_list_gamer(s_list_gamer *lst_) {
	s_list_gamer *data = lst_;
	s_list_gamer *tmp = lst_;
	int i = 0;

	if (lst_) {
		if (lst_->next == NULL) {
			free(lst_->gamer);
			lst_->gamer = NULL;
			free(lst_);
			lst_ = NULL;
		} else {
			while (tmp->next) {
				++i;
				tmp = tmp->next;
			}
			if (tmp) {
				free(tmp->gamer);
				tmp->gamer = NULL;
				free(tmp);
				tmp = NULL;

				while (data->next && --i > 0) {
					data = data->next;
				}
				data->next = NULL;
			}
		}
	}

	return (lst_);
}

int size_list_gamer(s_list_gamer *lst_) {
	int i = 0;
	for (; lst_; lst_ = lst_->next, ++i) {
	}
	return (i);
}

// -------------------------------------------------------

void output_list_gamer(s_list_gamer *list_) {
	while (list_) {
		printf("%s\t%d\n", list_->gamer->name, list_->gamer->score);
		list_ = list_->next;
	}
}

void output_gamer(s_gamer *gamer_) {
	if (gamer_) {
		printf("name: %s\n", gamer_->name);
		printf("score: %d\n", gamer_->score);
	}
}

// -------------------------------------------------------

s_list_gamer *free_list_gamer(s_list_gamer *list_) {
	s_list_gamer *tmp = NULL;

	while (list_) {
		if (list_->gamer) {
			free (list_->gamer);
			list_->gamer = NULL;
		}
		tmp = list_;
		list_ = list_->next;
		free (tmp);
		tmp = NULL;
	}
	return (list_);
}

// -------------------------------------------------------

s_list_gamer *split_text_list_gamer(char *text_) {
	s_list_gamer *lst = NULL;
	char *p = text_;
	int n_n = 0;;
	int begin = 0;
	int end = 0;;

	while (*p != '\0') {
		++end;
		if (*p == '\n') {
			add_to_list(&lst, text_, begin, end);
			++n_n;
			begin = end;
		}
		++p;
	}
	return (lst);
}

void add_to_list(s_list_gamer **lst_,
		char *text_,
		unsigned begin_,
		unsigned end_) {
	char name[30] = {"\0"};
	char score[30] = {"\0"};;
	int is_score = 0;
	int begin_name = -1;
	int begin_score = -1;

	for (; begin_ < end_; ++begin_) {
		if (!is_score ) {
			if (text_[begin_] != ' ') {
				name[++begin_name] = text_[begin_];
			} else {
				is_score = 1;
			}
		} else {
			score[++begin_score] = text_[begin_];
		}
	}
	add_list_gamer(lst_, name, atoi(score));
}
