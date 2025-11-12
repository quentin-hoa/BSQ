/*
** EPITECH PROJECT, 2025
** setting up
** File description:
** setting up
*/

#include "my.h"

void mark_biggest_square(char **map, int **num_map, int rows, int cols)
{
    int max_size = 0;
    int max_i = 0;
    int max_j = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (num_map[i][j] > max_size) {
                max_size = num_map[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }
    if (max_size == 0)
        return;
    for (int i = 0; i < max_size; i++) {
        for (int j = 0; j < max_size; j++) {
            if (map[max_i - i][max_j - j] == '.')
                map[max_i - i][max_j - j] = 'x';
        }
    }
}

void fill_map_of_number(int i, int j, char **map, int **map_of_number)
{
    if (map[i][j] == 'o') {
        map_of_number[i][j] = 0;
    } else if (i == 0 || j == 0) {
        map_of_number[i][j] = 1;
    } else {
        map_of_number[i][j] = 1 + mini_three(map_of_number[i - 1][j],
            map_of_number[i][j - 1], map_of_number[i - 1][j - 1]);
    }
}

int **find_bigest_square(char **map, int **map_of_number, int row, int col)
{
    int i = 0;
    int j = 0;

    for (i; i < row; i++){
        for (j = 0; j < col; j++) {
            fill_map_of_number(i, j, map, map_of_number);
        }
    }
    return map_of_number;
}

void print_map_number(char **map, int row, int col)
{
    for (int i = 0; i < row; i++) {
        my_printf("%s\n", map[i]);
    }
}
