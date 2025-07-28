EXEC = main

SRC = main.c imagens_ppm.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

%.o: %.c imagens_ppm.h
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(EXEC) *.o

clean-all: clean
	rm -f *.ppm
