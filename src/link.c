#include "lem_in.h"

static void free_old_links(char **arr, size_t size)
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

static void copy_links(char **links, char **new_links, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		new_links[i] = ft_strdup(links[i]);
		i++;
	}
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
	copy_links(links->arr, tmp, links->size - 1);
	free_old_links(links->arr, links->size - 1);
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
	printf("add link %s -> %s\n", room1, room2);
	if (!add_link(&room->links, room2))
		fatal_errors_handler(lem_in, "Malloc error.\n");
}