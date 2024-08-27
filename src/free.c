#include "lem_in.h"

void free_room(t_room *room)
{
	int i;

	i = 0;
	while (room->links && room->links[i])
	{
		free(room->links[i]);
		i++;
	}
	free(room->name);
	free(room);
}

void free_lem_in(t_lem_in *lem_in)
{
	int i;

	i = 0;
	while (i < lem_in->n_rooms)
	{
		free_room(&lem_in->rooms[i]);
		i++;
	}
	free(lem_in->rooms);
	free(lem_in);
}

void free_array(t_array *data)
{
	int i;

	i = 0;
	while (data->arr[i])
	{
		free(data->arr[i]);
		i++;
	}
	free(data->arr);
	free(data);
}
