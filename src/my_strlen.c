/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** len str
*/

#include "../includes/my.h"

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

int my_strlen_pos(char *str, int i)
{
    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

int my_strlen_space(char const *str, int i)
{
    while (str[i] != ' ' && str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
