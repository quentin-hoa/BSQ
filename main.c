/* 2025
** EPITECH PROJECT, 2025
** Day12
** File description:
** task2
*/

#include "my.h"

char *read_file(char *path)
{
    char *matrix;
    char buff[SIZEBUFFER];
    int nb_bytes = 0;
    int fd = open(path, O_RDONLY);

    if (fd == -1) {
        return FILE_ERROR;
    }
    nb_bytes = read(fd, buff, SIZEBUFFER);
    buff[nb_bytes + 1] = '\0';
    matrix = my_strdup(buff);
    return matrix;
}

int main(int ac, char **av)
{
    char *matrix = malloc(SIZEBUFFER);

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
    }
    return 0;
}
