#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_vector
{
    int         x;
    int         y;
}               t_vector;

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
    t_vector    pos;
}               t_room;

typedef struct s_ant
{
    int         id;
    t_room      *room;
}               t_ant;

typedef struct s_lem_in
{
    int         n_ants;
    int         start;
    int         end;
    int         n_rooms;

    t_room      *rooms;
    t_ant       *ants;
}               t_lem_in;


#endif