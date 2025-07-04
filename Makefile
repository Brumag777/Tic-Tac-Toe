CC = gcc
BASE_FLAGS = -Wall -Wextra -pedantic -O1 -g
SANITIZE_FLAGS = -fsanitize=address -fno-omit-frame-pointer
COVERAGE_FLAGS = --coverage
CFLAGS = $(BASE_FLAGS) $(SANITIZE_FLAGS) $(COVERAGE_FLAGS)
LDFLAGS = -lcunit

SRC = Menus.c Print.c
OBJ = $(SRC:.c=.o)
MAIN_OBJ = Main.o $(OBJ)

all: TicTacToe

TicTacToe: $(MAIN_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f Jogo Testes *.o *.gcov *.gcda *.gcno \
					  AI/*.o AI/*.gcov AI/*.gcda AI/*.gcno