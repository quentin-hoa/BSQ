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

SRC	= lib/src/my_0.c \
	lib/src/my_c.c \
	lib/src/my_d.c \
	lib/src/my_e.c \
	lib/src/my_ee.c \
	lib/src/my_f.c \
	lib/src/my_g.c \
	lib/src/my_o.c \
	lib/src/my_printf.c \
	lib/src/my_put_decimal.c \
	lib/src/my_revstr.c \
	lib/src/my_s.c \
	lib/src/my_space.c \
	lib/src/my_strcat.c \
	lib/src/my_strlen.c \
	lib/src/my_u.c \
	lib/src/my_x.c \
	lib/src/my_xx.c \
	lib/src/my_plus.c \
	lib/src/my_p.c \
	lib/src/my_b.c
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

compilation:
	gcc -c *.c -I$(INCLUDE_PATH)
	gcc *.o -L./ -o $(EXE) -lmy

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)


re: fclean all
