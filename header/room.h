#ifndef ROOM_H
# define ROOM_H

# include "lem_in.h"

void        set_room(t_room *room, int id, char *name, t_vector3 pos);
t_room      *get_room(t_lem_in *lem_in, char *room_name);

#endif