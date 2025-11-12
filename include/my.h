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
    #define ERROR_FILE "no such file or directory"

int my_printf(char *format, ...);
int my_atoi(char *str);
char *my_strdup(char *str);
int is_apha_char(char c);
int is_number(char c);
int mini_three(int a, int b, int c);
int my_atoi_c(char c);

#endif /* _MY_H_ */