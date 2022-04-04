#ifndef SRC_F_INPUT_H_
#define SRC_F_INPUT_H_

#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>

typedef enum {
	KEY_UNKNOWN = 0,
	KEY_ENTER,
	KEY_SPACE,
	KEY_UP,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_ESCAPE
} e_key_code;

/**
 * @brief Key input INTERACTIVE. 
 * 			(E_KEY_CODE)
 *
 * @return  -> E_KEY_CODE.
 */
e_key_code key_input();

// -------------------------------------------------------

/**
 * @brief Key input NOT interactive
 *
 * @return (E_KEY_CODE)
 */
e_key_code it_key_input();

int kbhit(void);

#endif // SRC_F_INPUT_H_
