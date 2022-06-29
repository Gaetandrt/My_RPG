##
## EPITECH PROJECT, 2022
## RPG ratio
## File description:
## Makefile
##

CC	=	gcc

CFLAGS	=	-W -Wall -Wextra -I./include/
LDFLAG	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio

SRC	=	$(wildcard src/*.c)

OBJ	=	$(SRC:.c=.o)

BIN	=	my_rpg

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN) $(LDFLAG)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(BIN)

re: fclean all

test:
	make re
	./my_rpg
