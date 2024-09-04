#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>

typedef struct s_vector2
{
    int         x;
    int         y;
}               t_vector2;

typedef struct s_vector3
{
    float        x;
    float        y;
    float        z;
}               t_vector3;

typedef struct s_array
{
    char        **arr;
    int         index;
    size_t      size;
}               t_array;

typedef struct s_room
{
    int         id;
    char        *name;
    bool        is_empty;
    t_array     links;
    t_vector3    pos;
}               t_room;

typedef struct s_node
{
    t_room              *room;
    struct s_node       *next;
}            t_node;

typedef struct s_ant
{
    int         id;
    t_node      *path;
}               t_ant;


typedef struct s_lem_in
{
    int         n_ants;
    int         start;
    int         end;
    int         n_rooms;
    t_node      *path;


    t_room      *rooms;
    t_ant       *ants;
}               t_lem_in;


void insert_node(t_node **head, t_node *node);
t_node *create_node(t_room *room);
void insert_at_start(t_node **head, t_node *node);
void display_path(t_node *path);


#endif