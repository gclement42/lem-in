#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/include/libft.h"

typedef struct s_vector
{
    int         x;
    int         y;
} t_vector;

typedef struct s_room
{
    int         id;
    char        **links;
    bool        is_empty;
    t_vector    pos;
} t_room;

typedef struct s_ant
{
    int         id;
    t_room      *room;
} t_ant;

typedef struct s_lem_in
{
    int         ants;
    int         start;
    int         end;
    int         n_rooms;
    
    t_room      *rooms;
} t_lem_in;

#endif