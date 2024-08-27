#include "lem_in.h"

static void free_old_array(char **arr, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static void *add_link(t_array *links, char *link)
{
	char *dup_link;

	dup_link = ft_strdup(link);
	if (!dup_link)
		return (NULL);
	links->size += 1;
	char **tmp = (char **)ft_realloc(links->arr, sizeof(char *), links->size + 1);
	if (!tmp)
		return (NULL);
	free_old_array(links->arr, links->size - 1);
	links->arr = tmp;
	links->arr[links->size - 1] = dup_link;
	return (links);
}

void set_link_in_rooms(t_lem_in *lem_in, char *room1, char *room2)
{
    t_room *room;

	room = get_room(lem_in, room1);
	if (!room)
		fatal_errors_handler(lem_in, "Room does not exist.\n");
	if (!add_link(&room->links, room2))
		fatal_errors_handler(lem_in, "Malloc error.\n");
}

void set_room(t_room *room, int id, char *name, t_vector pos)
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