#ifndef ROOM_H
# define ROOM_H

# include "lem_in.h"

void set_link_in_rooms(t_lem_in *lem_in, char *room1, char *room2);
void set_room(t_room *room, int id, char *name, t_vector pos);
t_room  *get_room(t_lem_in *lem_in, char *room_name);


#endif