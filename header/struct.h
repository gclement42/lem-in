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
    bool        is_empty;
    t_vector    pos;
}               t_room;

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

#endif