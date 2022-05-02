/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "../includes/my.h"

char *recup_map(char *file)
{
    int fd = open(file, O_RDONLY);
    struct stat s;
    stat(file, &s);
    char *buffer = malloc(sizeof(char) * s.st_size + 1);
    read(fd, buffer, s.st_size);
    close(fd);
    return buffer;
}

pos get_pos_finish(char **map)
{
    int y = 0, x = 0;
    while (map[y]) {
        while (map[y][x]) {
            x += 1;
        }
        x = 0;
        y += 1;
    }
    pos pos_finsih = {y - 1, my_strlen(map[y - 1]) - 1};
    return pos_finsih;
}
