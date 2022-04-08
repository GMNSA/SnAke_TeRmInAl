#ifndef SRC_SNAKE_GAME_MENU_
#define SRC_SNAKE_GAME_MENU_

typedef enum {
	SNAKE_MENU_START_GAME = 0,
	SNAKE_MENU_SCORES_GAME,
	SNAKE_MENU_ABOUT_GAME,
	SNAKE_MENU_EXIT_GAME,
	SNAKE_MENU_END
} e_snake_menu;

extern int G_SNAKE_MENU_CURRENT_STATE;

void snake_menu();
int menu_selection();

#endif // SRC_SNAKE_GAME_MENU_
