/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** getnbr
*/

#include "../includes/my.h"

nv *add_or_update_visited(pos pos_n, nv **visited, node **arr, node *my_n)
{
    int in_visited = 0;
    nv *tmp = malloc(sizeof(nv));
    tmp = (*visited);
    while ((*visited) != NULL) {
        if ((*visited) -> my_node -> x == pos_n.x &&
            (*visited) -> my_node -> y == pos_n.y) {
            in_visited = 1; break;
        }
        (*visited) = (*visited) -> next;
    }
    if (in_visited == 1 &&
        (*visited) -> my_node -> gcost < my_n -> gcost + 10) {
        (*visited) -> my_node = get_node(pos_n, my_n -> pos_end, my_n, 0);
    }
    (*visited) = tmp;
    if (in_visited == 0)
        (*visited) = copy_from_arr(arr, visited, pos_n);
    return (*visited);
}

node **update_liste_nodes(node **arr, node *my_node, char **map, nv **visited)
{
    pos pos_node = get_node_top(my_node, map);
    arr = add_el_in_arr(arr, pos_node, my_node);
    if (pos_node.x != -1)
        (*visited) = add_or_update_visited(pos_node, visited, arr, my_node);
    pos_node = get_node_rigth(my_node, map);
    arr = add_el_in_arr(arr, pos_node, my_node);
    if (pos_node.x != -1)
        (*visited) = add_or_update_visited(pos_node, visited, arr, my_node);
    pos_node = get_node_bottom(my_node, map);
    arr = add_el_in_arr(arr, pos_node, my_node);
    if (pos_node.x != -1)
        (*visited) = add_or_update_visited(pos_node, visited, arr, my_node);
    pos_node = get_node_left(my_node, map);
    arr = add_el_in_arr(arr, pos_node, my_node);
    if (pos_node.x != -1)
        (*visited) = add_or_update_visited(pos_node, visited, arr, my_node);
    return arr;
}

int get_gcost(node *parent)
{
    if (parent != NULL)
        return (parent -> gcost + 10);
    else
        return 0;
}

int get_hcost(pos pos_node, pos pos_end)
{
    int hcost = ((pos_end.y - pos_node.y) + (pos_end.x - pos_node.x)) * 10;
    return hcost;
}

node *get_node(pos pos_node, pos pos_end, node *parent, int close)
{
    node *my_node = malloc(sizeof(node));
    my_node -> y = pos_node.y;
    my_node -> x = pos_node.x;
    my_node -> pos_end.y = pos_end.y;
    my_node -> pos_end.x = pos_end.x;
    my_node -> gcost = get_gcost(parent);
    my_node -> hcost = get_hcost(pos_node, pos_end);
    my_node -> fcost = my_node -> gcost + my_node -> hcost;
    my_node -> parent = parent;
    my_node -> close = close;
    return my_node;
}
