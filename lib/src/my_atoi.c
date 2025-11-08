/*
** EPITECH PROJECT, 2025
** Atoi
** File description:
** transform a string of number into an int
*/
#include "my.h"

int my_atoi(char *str)
{
    int nb = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        nb = (nb * 10) + (str[i] - '0');
    }
    return nb;
}
