/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "../includes/my.h"

pos get_node_top(node *my_node, char **map)
{
    pos pos_node;
    pos_node.y = my_node -> y + 1;
    pos_node.x = my_node -> x;
    if (pos_node.y <= my_node -> pos_end.y
        && map[pos_node.y][pos_node.x] == '*') {
        return pos_node;
    }
    pos_node.y = -1;
    pos_node.x = -1;
    return pos_node;
}

pos get_node_rigth(node *my_node, char **map)
{
    pos pos_node;
    pos_node.y = my_node -> y;
    pos_node.x = my_node -> x + 1;
    if (pos_node.x >= 0 && map[pos_node.y][pos_node.x] == '*') {
        return pos_node;
    }
    pos_node.y = -1;
    pos_node.x = -1;
    return pos_node;
}

pos get_node_bottom(node *my_node, char **map)
{
    pos pos_node;
    pos_node.y = my_node -> y - 1;
    pos_node.x = my_node -> x;
    if (pos_node.y >= 0 && map[pos_node.y][pos_node.x] == '*') {
        return pos_node;
    }
    pos_node.y = -1;
    pos_node.x = -1;
    return pos_node;
}

pos get_node_left(node *my_node, char **map)
{
    pos pos_node;
    pos_node.y = my_node -> y;
    pos_node.x = my_node -> x - 1;
    if (pos_node.x <= my_node -> pos_end.x
        && map[pos_node.y][pos_node.x] == '*') {
        return pos_node;
    }
    pos_node.y = -1;
    pos_node.x = -1;
    return pos_node;
}
