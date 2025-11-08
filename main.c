/* 2025
** EPITECH PROJECT, 2025
** Day12
** File description:
** task2
*/

#include "my.h"

char *erase_first_line(char *matrix)
{
    int count = 0;

    for (int i = 0; matrix[i] != '\n'; i++) {
        count++;
    }
    return (matrix + count + 1);
}

char *read_file(char *path)
{
    int count = 0;
    char buff[SIZEBUFFER];
    int nb_bytes = 0;
    int fd = open(path, O_RDONLY);
    char *matrix;

    if (fd == -1) {
        return FILE_ERROR;
    }
    nb_bytes = read(fd, buff, SIZEBUFFER);
    buff[nb_bytes + 1] = '\0';
    matrix = my_strdup(erase_first_line(buff));
    return matrix;
}

char *generate_matrix(int size, char *seed)
{
    char *matrix = malloc((size * size) + (size - 1) + 1);
    int k = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[k] = '.';
            k++;
        }
        if (i < size -1) {
            matrix[k] = '\n';
            k++;
        }
    }
    matrix[k] = '\0';
    return matrix;
}

int main(int ac, char **av)
{
    char *matrix = malloc(SIZEBUFFER);

    if (ac == 1) {
        my_printf("To few arguments\n");
        return 84;
    }
    if (is_apha_char(av[1][0]) == 1) {
        //part with matrix from the file
        matrix = read_file(av[1]);
        if (matrix == FILE_ERROR) {
            my_printf("%s\n", FILE_ERROR);
            return 84;
        }
        my_printf("%s", matrix);

    }
    if (is_number(av[1][0]) == 1) {
        //part with the random generator of matrix
        if (av[2] == NULL) {
            my_printf("To few arguments\n");
            return 84;
        }
        matrix = generate_matrix(my_atoi(av[1]),av[2]);
        printf("%s", matrix);
    }
    free(matrix);
    return 0;
}
