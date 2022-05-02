/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** isnegro
*/

#include "../includes/my.h"

node **close_a_node_in_arr(node **arr, pos node_pos)
{
    arr[node_pos.y][node_pos.x].close = 1;
    return (arr);
}
