CC=gcc
LDFLAGS=-c -g -Wall -Werror -Wextra
EXECUTABLE=a.out
SOURCES=srcs/main.c srcs/f_log_file.c srcs/snake_game.c srcs/snake_game_menu.c srcs/my_sleep.c srcs/snake_game_processing.c
OBJECTS=$(SOURCES:.c=.o)
LIBC=libs/libinput.a

EXECUTABLE_TEST=test.out
SOURCES_TEST=
OBJECTS_TEST=$(SOURCES_TEST:.c=.o)

HEADERS=-I ./includes

all: build

build: $(EXECUTABLE) $(OBJECTS)

rebuild: clean build 

clean:
	rm -f $(EXECUTABLE) $(EXECUTABLE_TEST) $(OBJECTS) $(OBJECTS_TEST)

.c.o:
	@echo "Compiling"
	$(CC) $(LDFLAGS) -D MY_USLEEP_ $(HEADERS)  $< -o $@


$(EXECUTABLE) : $(OBJECTS)
	@echo "Linking"
	$(CC) $(OBJECTS) $(LIBC) -o $(EXECUTABLE)


test: $(EXECUTABLE_TEST) $(OBJECTS_TEST)


$(EXECUTABLE_TEST) : $(OBJECTS_TEST)
	@echo "Linking"
	$(CC) $(OBJECTS_TEST) $(HEADERS) -o $(EXECUTABLE_TEST)
