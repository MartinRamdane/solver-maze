/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** isneg
*/

#include "../includes/my.h"

node **malloc_node_arr(node *first_node, int nb_nodes, char **map)
{
    int y = 0;
    while (map[y])
        y += 1;
    node **node_arr = malloc(sizeof(node *) * (y + 1));
    int i = 0;
    while (i != y) {
        node_arr[i] = malloc(sizeof(node) * (my_strlen(map[i]) + 1));
        i += 1;
    }
    return (node_arr);
}

node **add_el_in_arr(node **arr, pos node_pos, node *my_node)
{
    if (node_pos.x == -1)
        return (arr);
    if (arr[node_pos.y][node_pos.x].x == node_pos.x
        && arr[node_pos.y][node_pos.x].y == node_pos.y)
        return (arr);
    node *new_node = malloc(sizeof(node));
    new_node = get_node(node_pos, my_node -> pos_end, my_node, 0);
    arr[node_pos.y][node_pos.x].close = 0;
    arr[node_pos.y][node_pos.x].x = new_node -> x;
    arr[node_pos.y][node_pos.x].y = new_node -> y;
    arr[node_pos.y][node_pos.x].fcost = new_node -> fcost;
    arr[node_pos.y][node_pos.x].gcost = new_node -> gcost;
    arr[node_pos.y][node_pos.x].hcost = new_node -> hcost;
    arr[node_pos.y][node_pos.x].pos_end = new_node -> pos_end;
    arr[node_pos.y][node_pos.x].parent = new_node -> parent;
    return (arr);
}

nv *remove_el_in_list(nv *list, pos node_pos)
{
    nv *head = malloc(sizeof(nv));
    head = list;
    if (list == NULL)
        return (NULL);
    if (list -> next == NULL)
        return (NULL);
    if (list -> my_node -> x == node_pos.x
        && list -> my_node -> y == node_pos.y)
        return (list -> next);
    while (list -> next != NULL) {
        if (list -> next -> my_node -> x == node_pos.x
            && list -> next -> my_node -> y == node_pos.y) {
            list -> next = list -> next -> next;
            break;
        }
        list = list -> next;
    }
    list = head;
    return (list);
}

nv *copy_from_arr(node **arr, nv **list, pos node_pos)
{
    if (arr[node_pos.y][node_pos.x].close == 0) {
        nv *first = malloc(sizeof(nv));
        first -> my_node = malloc(sizeof(node));
        first -> my_node -> close = arr[node_pos.y][node_pos.x].close;
        first -> my_node -> fcost = arr[node_pos.y][node_pos.x].fcost;
        first -> my_node -> hcost = arr[node_pos.y][node_pos.x].hcost;
        first -> my_node -> gcost = arr[node_pos.y][node_pos.x].gcost;
        first -> my_node -> parent = arr[node_pos.y][node_pos.x].parent;
        first -> my_node -> pos_end = arr[node_pos.y][node_pos.x].pos_end;
        first -> my_node -> x = arr[node_pos.y][node_pos.x].x;
        first -> my_node -> y = arr[node_pos.y][node_pos.x].y;
        first -> next = (*list);
        (*list) = first;
    }
    return (*list);
}
