/* 2025
** EPITECH PROJECT, 2025
** Day12
** File description:
** task2
*/

#include "my.h"

int get_size(char *matrix)
{
    return my_atoi_c(matrix[0]);
}

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

    /*if (fd == -1) {
        return ERROR_FILE;
    }*/
    nb_bytes = read(fd, buff, SIZEBUFFER);
    buff[nb_bytes] = '\0';
    matrix = my_strdup(erase_first_line(buff));
    return matrix;
}

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

void malloc_twod_array(char **twod_array, int nb_lines, int nb_col)
{
    for (int k = 0; k < nb_lines; k++) {
        twod_array[k] = malloc(nb_col + 1);
    }

}

char **oned_to_twod(char *matrix)
{
    int nb_lines = get_lines(matrix);
    int nb_col = get_col(matrix);
    int m_i = 0;
    int row_i = 0;
    int col_i = 0;
    char **result = malloc(nb_lines * sizeof(char *));

    malloc_twod_array(result, nb_lines, nb_col);
    for (m_i = 0; matrix[m_i] != '\0'; m_i++) {
        if (matrix[m_i] == '\n') {
            result[row_i][col_i] = '\0';
            row_i++;
            col_i = 0;
        } else {
            result[row_i][col_i] = matrix[m_i];
            col_i++;
        }
    }
    if (row_i < nb_lines)
        result[row_i][col_i] = '\0';
    return result;
}

void fill_map_of_number(int i, int j, char **map, int **map_of_number)
{
    
}

int **find_bigest_square(char **map, int row, int col)
{
    int **map_of_number;
    int i = 0;
    int j = 0;
    map_of_number = malloc(row * sizeof(int)); 
    for (int k = 0; k < row; k++) {
        map_of_number[k] = malloc((row) * sizeof(int) + 1);
    }
    for (i; i < row; i++){
        for (j = 0; j < col; j++) {
            if (map[i][j] == 'o') {
                map_of_number[i][j] = 0;
            } else if (i == 0 || j == 0) {
                map_of_number[i][j] = 1;
            }
            else {
                map_of_number[i][j] = 1 + mini_three(map_of_number[i - 1][j], map_of_number[i][j - 1], map_of_number[i - 1][j - 1]);
            }
        }
    }
    for (int k = 0; k < row; k++) {
        for (int f = 0; f < col; f++) {
            my_printf("%d", map_of_number[k][f]);
        }
        my_printf("\n");
    }
    return map_of_number;
}

void print_map_number()
{

}

char *generate_matrix(int size, char *seed)
{
    // execute perl script
    return "";
}

int main(int ac, char **av)
{
    char *matrix = malloc(SIZEBUFFER);
    char **map;
    int i = 0;
    int size;
    int row;
    int col;

    if (ac == 1) {
        my_printf("To few arguments\n");
        return 84;
    }
    if (ac > 3) {
        my_printf("to many arguments\n");
        return 84;
    }
    if (is_apha_char(av[1][0]) == 1) {//part with matrix from the file
        matrix = read_file(av[1]);
        /*if (matrix == ERROR_FILE) {
            my_printf("%s\n", ERROR_FILE);
            return 84;
        }*/

        map = oned_to_twod(matrix);
        row = get_lines(matrix);
        col = get_col(matrix);
        find_bigest_square(map, row, col);

        //print twod_array
        while (map[i] != NULL) {
            my_printf("%s\n",map[i]);
            i++;
        }
    }
    if (is_number(av[1][0]) == 1) {//part with the random generator of matrix
        if (av[2] == NULL) {
            my_printf("To few arguments\n");
            return 84;
        }
    }
    free(matrix);
    free(map);
    return 0;
}
