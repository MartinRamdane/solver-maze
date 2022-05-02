/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "../includes/my.h"

int get_nb_nodes(char **map)
{
    int nb_nodes;
    for (int y = 0; map[y]; y++) {
        for (int x = 0; map[y][x]; x++) {
            if (map[y][x] == '*')
                nb_nodes += 1;
        }
    }
    return nb_nodes;
}

int gestion_error(char **map)
{
    int len_map = my_strlen(map[0]);
    for (int i = 0; map[i]; i++) {
        if (my_strlen(map[i]) != len_map)
            return 84;
        for (int j = 0; map[i][j]; j++) {
            if (map[i][j] != '*' && map[i][j] != 'X')
                return 84;
        }
    }
    return 0;
}

node *get_best_node(nv **visited, node **list_nodes)
{
    nv *tmp = malloc(sizeof(nv));
    tmp = (*visited);
    node *my_node = malloc(sizeof(node));
    my_node -> fcost = 2147483647;
    while ((*visited) != NULL) {
        if ((*visited) -> my_node -> fcost < my_node -> fcost)
            my_node = (*visited) -> my_node;
        (*visited) = (*visited) -> next;
    }
    (*visited) = tmp; pos pos_node;
    pos_node.y = my_node -> y; pos_node.x = my_node -> x;
    (*visited) = remove_el_in_list((*visited), pos_node);
    list_nodes = close_a_node_in_arr(list_nodes, pos_node);
    my_node -> close = 1;
    return my_node;
}

void solver(char **map)
{
    int y = 0, x = 0; pos pos_start = {0, 0};
    pos pos_end = get_pos_finish(map);
    node *my_node = get_node(pos_start, pos_end, NULL, 1); nv *visited = NULL;
    node **nodes_arr = malloc_node_arr(my_node, get_nb_nodes(map), map);
    nodes_arr = add_el_in_arr(nodes_arr, pos_start, NULL);
    while (my_node -> y != pos_end.y || my_node -> x != pos_end.x) {
        nodes_arr = update_liste_nodes(nodes_arr, my_node, map, &visited);
        if (visited == NULL) {
            write(1, "no solution found", 17); return;
        }
        my_node = get_best_node(&visited, nodes_arr);
    }
    while (my_node != NULL) {
        map[my_node -> y][my_node -> x] = 'o'; my_node = my_node -> parent;
    }
    for (int i = 0; map[i]; i++) {
        write(1, map[i], my_strlen(map[i]));
        if (map[i + 1] != NULL)
            write(1, "\n", 1);
    }
}

int main(int ac, char **av)
{
    if (ac == 2) {
        char **map = my_str_to_word_array(recup_map(av[1]));
        if (map[0][0] == 'X') {
            write(1, "no solution found\n", 18);
            return 0;
        }
        int y = 0;
        while (map[y])
            y += 1;
        if (map[y - 1][my_strlen(map[y - 1]) - 1] == 'X') {
            write(1, "no solution found\n", 18);
            return 0;
        }
        if (gestion_error(map) == 84)
            return 84;
        solver(map);
    } else
        return 84;
    return 0;
}
