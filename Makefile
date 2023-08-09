CC = gcc
CFLAGS = -Wall -Wextra -g

EXEC = tp2
SRC = main.c estrategia1.c estrategia2.c matriz.c arquivos.c
OBJ = $(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -rf $(OBJ) $(EXEC)
