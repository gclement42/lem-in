#include "lem_in.h"

static int count_size(char **links)
{
	int i;

	i = 0;
	if (!links)
		return (0);
	while (links[i])
		i++;
	return (i);
}

static char **add_link(char **links, char *link)
{
	int size;

	size = count_size(links);
	if (size == 0)
	{
		links = (char **)malloc(sizeof(char *) * 2);
		links[0] = link;
		links[1] = NULL;
		return (links);
	}
	links = ft_realloc(links, sizeof(char *) * (size + 1));
	links[size] = link;
	return (links);
}

void set_link_in_rooms(t_lem_in *lem_in, char *room1, char *room2)
{
    t_room *room;

	room = get_room(lem_in, room1);
	if (!room)
		fatal_errors_handler(lem_in, "Room does not exist.\n");
	room->links = add_link(room->links, room2);
}

void set_room(t_room *room, int id, char *name, t_vector pos)
{
    room->id = id;
    room->name = name;
    room->pos = pos;
    room->is_empty = true;
    room->links = NULL;
}


t_room  *get_room(t_lem_in *lem_in, char *room_name)
{
    int i;

    i = 0;
    while (lem_in->rooms[i].name)
    {
        if (ft_strncmp(lem_in->rooms[i].name, room_name, ft_strlen(room_name)) == 0)
            return (&lem_in->rooms[i]);
        i++;
    }
    return (NULL);
}