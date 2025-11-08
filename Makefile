##
## EPITECH PROJECT, 2025
## Day10
## File description:
## task01 Makefile
##

INCLUDE_PATH = ./include/
CFLAGS = -I$(INCLUDE_PATH)
NAME = libmy.a
EXE = setting_up

SRC	= main.c
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib
	clang *.o -L./lib -o $(EXE) -lmy

compilation:
	gcc -c *.c -g -I$(INCLUDE_PATH)
	gcc *.o -L./ -o $(EXE) -lmy

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib


re: fclean all
