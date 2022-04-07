CC=gcc
LDFLAGS=-c -std=gnu11 -g -Wall -Werror -Wextra
EXECUTABLE=a.out
SOURCES=srcs/main.c srcs/f_log_file.c srcs/snake_game.c srcs/snake_game_menu.c srcs/my_sleep.c srcs/snake_game_processing.c srcs/snake_game_about.c srcs/snake_game_end.c srcs/work_with_files.c srcs/my_struct.c
OBJECTS=$(SOURCES:.c=.o)
LIBC=libs/libinput.a

EXECUTABLE_TEST=test.out
SOURCES_TEST=tests/main.c srcs/f_log_file.c srcs/snake_game.c srcs/snake_game_menu.c srcs/my_sleep.c srcs/snake_game_processing.c srcs/snake_game_about.c srcs/snake_game_end.c srcs/work_with_files.c srcs/my_struct.c

OBJECTS_TEST=$(SOURCES_TEST:.c=.o)

HEADERS=-I ./includes

BAR?=_TEST_
TEST?=


.PHONY: all test rebuild


all: build

build: $(EXECUTABLE) $(OBJECTS)

rebuild: clean build test

clean:
	rm -f $(EXECUTABLE) $(EXECUTABLE_TEST) $(OBJECTS) $(OBJECTS_TEST)

.c.o:
	@echo "Compiling"
	$(CC) $(LDFLAGS) -D MY_USLEEP_ -D $(BAR)$(TEST) $(HEADERS)  $< -o $@


$(EXECUTABLE) : $(OBJECTS)
	@echo "Linking"
	$(CC) $(OBJECTS) $(LIBC) -o $(EXECUTABLE)

test: $(EXECUTABLE_TEST)

$(EXECUTABLE_TEST) : $(OBJECTS_TEST)
	@echo "Linking"
	$(CC) $(OBJECTS_TEST) $(LIBC)  -o $(EXECUTABLE_TEST)
