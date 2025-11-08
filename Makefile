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
COMMIT ?= 

SRC	= main.c
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib
	clang *.o -L./lib -o $(EXE) -lmy

push: fclean
	git add .
	git commit -m "$(COMMIT)"
	git push

clean:
	rm -f $(OBJ)
	make clean -C ./lib
fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib


re: fclean all
