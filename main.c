/*
** EPITECH PROJECT, 2025
** Day12
** File description:
** task2
*/

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


int main()
{
    my_printf("hello world");
}