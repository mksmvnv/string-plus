CC = gcc
CFLAGS = -Wall -Werror -Wextra

OBJ = ./fake_string.o ./tests/unit_tests.o

TARGET = fake_string

all: ./fake_string.c ./fake_string.h ./tests/unit_tests.c ./tests/unit_tests.h
	$(CC) $(CFLAGS) ./fake_string.c ./tests/unit_tests.c -pthread -lcheck_pic -pthread -lrt -lm -lsubunit

clean:
	rm -f $(OBJ) $(TARGET)
