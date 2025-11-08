/*
** EPITECH PROJECT, 2025
** Day03
** File description:
** Alphabet
*/

#ifndef _MY_H_
    #define _MY_H_
    #define SIZEBUFFER 16000
    #include <unistd.h>
    #include <stdarg.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <dirent.h>
    #define NUMBER_OF_SP 16
    #define NUMBER_OF_FLAGS 3

int my_printf(char *format, ...);
int my_atoi(char *str);
char *my_strdup(char *str);

#endif /* _MY_H_ */