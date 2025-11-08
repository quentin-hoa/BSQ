/* 2025
** EPITECH PROJECT, 2025
** Day12
** File description:
** task2
*/

#include "my.h"

/*int cat(int ac, char **av)
{
    int fd = 0;
    int nb_bytes = 1;
    char buff[SIZEBUFFER];

    if (ac == 1) {
        while (nb_bytes > 0) {
            nb_bytes = read(0, buff, SIZEBUFFER);
            write(1, buff, nb_bytes);
        }
    }
    for (int i = 1; i < ac; i++) {
        fd = open(av[i], O_RDONLY);
        if (fd == -1) {
            write(2, "No such file or directory", 25);
            return 84;
        }
        nb_bytes = read(fd, buff, SIZEBUFFER);
        write(1, buff, nb_bytes);
    }
    return 0;
}*/

int fs_open_file(char const *filepath)
{
    int file_descriptor = 0;

    file_descriptor = open(filepath, O_RDONLY);
    if (file_descriptor == -1)
        my_printf("FAILURE\n");
    else
        my_printf("SUCCES\n");
    close(file_descriptor);
    return file_descriptor;
}

void fs_understand_retunr_of_read(int fd, char *buffer, int size)
{
    if (fd  == -1)
        my_printf("read failed\n");
    if (fd == 0)
        my_printf("read has nothing more to read\n");
    if (fd < size)
        my_printf("read didn't complete the entire buffer\n");
    if (fd == size)
        my_printf("read completed the entire buffer\n");
}

void fs_cat_500_bytes(char const *filepath)
{
    int fd;
    int nb_bytes = 1;
    char buff[500];

    fd = open(filepath, O_RDONLY);
    nb_bytes = read(fd, buff, 500);
    write(1, buff, nb_bytes);
    close(fd);
}

void fs_cat_x_bytes(char const *filepath, int x)
{
    int fd;
    int nb_bytes = 1;
    char buff[x];

    fd = open(filepath, O_RDONLY);
    nb_bytes = read(fd, buff, x);
    write(1, buff, nb_bytes);
    close(fd);
}

char *fs_print_first_line(char const *filepath)
{
    int fd;
    int nb_bytes = 1;
    char buff[SIZEBUFFER];
    char result[SIZEBUFFER];
    int i;

    fd = open(filepath, O_RDONLY);
    nb_bytes = read(fd, buff, SIZEBUFFER);
    for (i = 0; buff[i] != '\n'; i++) {
        result[i] = buff[i];
    }
    result[i] = '\0';
    //my_printf("%s", result);
    close(fd);
    return my_strdup(result);
}

int fs_get_number_from_first_line(char const* filepath)
{
    char *first_line = fs_print_first_line(filepath);
    char number[9];
    int i = 0;

    for (int j = 0; first_line[j] != '\0'; j++) {
        if (first_line[j] >= 48 && first_line[j] <= 57) {
            number[i] = first_line[j];
            i++;
        }
    }
    return my_atoi(number); 
}

void array_1_d_print_chars(char const *arr)
{
    my_printf("%s", arr);
}

void array_1d_print_ints(int const *arr, int size)
{
    for (int i = 0; i < size; i++) {
        my_d(arr[i]);
        my_s("\n");
    }
}

int array_1d_sum(int const *arr, int size)
{
    int result = 0;

    for (int i = 0; i < size; i++) {
        result += arr[i];
    }
    return result;
}

int array_2d_sum(int arr[2][3], int nb_rows, int nb_cols)
{
    int result = 0;

    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j < nb_cols; j++) {
            result += arr[i][j];
        }
    }
    return result;
}

int array_2d_how_many(int arr[2][3], int nb_rows, int nb_cols,  int number)
{
    int result = 0;

    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j < nb_cols; j++) {
            if (arr[i][j] == number)
                result++;
        }
    }
    return result;
}

char *mem_alloc(char const *a, char const *b)
{
    char *result = malloc(my_strlen(a) + my_strlen(b) + 2);

    return result;
}

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **reslut = malloc(sizeof(char) * nb_cols * nb_cols);

    return reslut;
}

char *load_file_in_mem(char const *filepath)
{
    int fd;
    char buff[SIZEBUFFER];

    fd = open(filepath, O_RDONLY);
    read(fd, buff, SIZEBUFFER);
    return buff;

}

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols)
{
    int fd;
    char buff[SIZEBUFFER];
    int nb_bytes;
    char result[nb_rows][nb_cols];

    fd = open(filepath, O_RDONLY);
    nb_bytes = read(fd, buff, SIZEBUFFER);
    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j < nb_cols; j++) {
            result[i][j] = buff[i];
        }
    }
    return *result;
}
