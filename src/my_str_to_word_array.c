/*
** EPITECH PROJECT, 2021
** my_str_to_word_array.c
** File description:
** str to word array
*/

#include "../includes/my.h"

int nb_words_str(char const *str)
{
    int i = 0, cmp = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            cmp = cmp + 1;
        }
        i = i + 1;
    }
    return cmp + 1;
}

int len_word(char const *str)
{
    int i = 0;
    while (str[i] != '\n') {
        i = i + 1;
    }
    return (i);
}

int my_str_n(char const *str, int i)
{
    while (str[i] != '\n' && str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

char **my_str_to_word_array(char const *str)
{
    char **map = malloc(sizeof(char *) * (nb_words_str(str) + 1));
    int i = 0, j = 0, y = 0;
    map[0] = malloc(sizeof(char) * (my_str_n(str, 0) + 1));
    while (str[i]) {
        if (str[i] == '\n') {
            map[y][j] = '\0';
            y++;
            map[y] = malloc(sizeof(char) * (my_str_n(str, i + 1) + 1));
            j = 0; i++;
        }
        map[y][j] = str[i];
        i++; j++;
    }
    map[y + 1] = NULL;
    return map;
}
