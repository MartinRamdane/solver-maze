/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>

#ifndef MY_H
    #define MY_H

typedef struct pos {
    int y;
    int x;
} pos;

typedef struct node {
    int y;
    int x;
    pos pos_end;
    int gcost;
    int hcost;
    int fcost;
    int close;
    struct node *parent;
} node;

typedef struct nodes_visited {
    node *my_node;
    struct nodes_visited *next;
} nv;

int my_putstr(char const *str);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_strlen(char const *str);
int my_strlen_space(char const *str, int i);
char *my_strcpy(char *dest, char const *src);
char *my_strcpy_pos(char *dest, char const *src, int i);
char *my_strcat(char *dest, char const *src);
int my_printf(const char *format, ...);
int my_getnbr(char *str);
char *my_revstr(char *str);
int my_strstr(char *str, char *to_find);
char **my_str_to_word_array(char const *str);
char *recup_map(char *file);
pos get_pos_finish(char **map);
node *get_node(pos pos_node, pos pos_end, node *parent, int close);
pos get_node_top(node *my_node, char **map);
pos get_node_rigth(node *my_node, char **map);
pos get_node_bottom(node *my_node, char **map);
pos get_node_left(node *my_node, char **map);
int get_nb_nodes(char **map);
node **update_liste_nodes(node **arr, node *my_node, char **map, nv **visited);
node **malloc_node_arr(node *first_node, int nb_nodes, char **map);
int is_exist_in_arr(node **arr, pos node_pos);
node **add_el_in_arr(node **arr, pos node_pos, node *my_node);
nv *remove_el_in_list(nv *list, pos node_pos);
nv *copy_from_arr(node **arr, nv **list, pos node_pos);
node **close_a_node_in_arr(node **arr, pos node_pos);
#endif
