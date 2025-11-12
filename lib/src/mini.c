/*
** EPITECH PROJECT, 2025
** minimun
** File description:
** return the minium value of three values
*/

#include "my.h"

int mini_three(int a, int b, int c)
{
    int mini;
    mini = a;
    if (b < a)
        mini = b;
    if (c < b)
        mini = c;
    return mini;
}
