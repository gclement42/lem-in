#include "lem_in.h"

void set_room(t_room *room, int id, char *name, t_vector2 pos)
{
    room->id = id;
    room->name = name;
    room->pos = pos;
    room->is_empty = true;
    room->links.arr = NULL;
	room->links.size = 0;
}


t_room  *get_room(t_lem_in *lem_in, char *room_name)
{
    int i;

    i = 0;
    while (i < lem_in->n_rooms)
    {
		if (!lem_in->rooms[i].name)
			return (NULL);
        if (ft_strncmp(lem_in->rooms[i].name, room_name, ft_strlen(room_name)) == 0)
            return (&lem_in->rooms[i]);
        i++;
    }
    return (NULL);
}