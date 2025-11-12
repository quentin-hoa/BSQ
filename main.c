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
    nb_lines++;
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

int error_handling(int ac)
{
    if (ac == 1)
        return 84;
    if (ac > 3)
        return 84;
    return 0;
}

int main(int ac, char **av)
{
    char *matrix = malloc(SIZEBUFFER);
    char **map;
    int i = 0;
    int row;
    int col;
    int **map_of_number = malloc(row * sizeof(int));

    if (error_handling(ac) != 0)
        return error_handling(ac);
    if (is_apha_char(av[1][0]) == 1) {
        matrix = read_file(av[1]);
        if (my_strcmp(matrix, ERROR_FILE) == 0)
            return 84;
        map = oned_to_twod(matrix);
        row = get_lines(matrix);
        col = get_col(matrix);
        for (int k = 0; k < row; k++) {
            map_of_number[k] = malloc((row) * sizeof(int) + 1);
        }
        find_bigest_square(map, map_of_number, row, col);
        mark_biggest_square(map, map_of_number, row, col);
        print_map_number(map, row, col);
    }
    if (is_number(av[1][0]) == 1) {
        if (av[2] == NULL) {
            my_printf("To few arguments\n");
            return 84;
        }
    }
    return 0;
}
