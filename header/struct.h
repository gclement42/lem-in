#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>

typedef struct s_vector
{
    int         x;
    int         y;
}               t_vector;

typedef struct s_room
{
    int         id;
    char        *name;
    bool        is_empty;
    char        **links;
    t_vector    pos;
}               t_room;

typedef struct s_array
{
    char        **arr;
    int         index;
}               t_array;

typedef struct s_ant
{
    int         id;
    t_room      *room;
}               t_ant;

typedef struct s_lem_in
{
    int         ants;
    int         start;
    int         end;
    int         n_rooms;

    char        **links;
    t_room      *rooms;
}               t_lem_in;

t_room  *get_room(t_lem_in *lem_in, char *room_name);

#endif