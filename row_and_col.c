/*
** EPITECH PROJECT, 2025
** Day12
** File description:
** task2
*/

#include "my.h"

int get_lines(char *matrix)
{
    int nb_lines = 0;

    for (int k = 0; matrix[k] != '\0'; k++) {
        if (matrix[k] == '\n')
            nb_lines++;
    }
    return nb_lines;
}

int get_col(char *matrix)
{
    int nb_col = 0;

    if (matrix[0] != '\0') {
        for (int k = 0; matrix[k] != '\n' && matrix[k] != '\0'; k++) {
            nb_col++;
        }
    }
    return nb_col;
}
