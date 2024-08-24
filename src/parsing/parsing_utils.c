#include "lem_in.h"

bool check_if_comment(char *line)
{
    if (line[0] == '#' && line[1] != '#')
        return (true);
    return (false);
}

bool check_if_command(char *line)
{
    if (line[0] == '#' && line[1] == '#')
        return (true);
    return (false);
}

bool check_if_room(char *line)
{
    if (ft_strchr(line, ' ') && line[0] != 'L' && line[0] != '#')
        return (true);
    return (false);
}

bool check_if_link(char *line)
{
    if (ft_strchr(line, '-') && line[0] != 'L' && line[0] != '#')
        return (true);
    return (false);
}

bool check_is_valid_link(char *line)
{
    int i;

    i = 0;
    while (line[i] != '-')
        i++;
    if (line[i + 1] == '\0' || line[i + 1] == '\n')
        return (false);
    return (true);
}

char *get_room_name(char *line)
{
    char *name;
    int i;

    i = 0;
    while (line[i] != ' ')
        i++;
    name = ft_substr(line, 0, i);

    ft_printf("Room name: %s\n", name);
    return (name);
}

int count_n_links(char **data)
{
    int i;
    int n_links;

    i = 0;
    n_links = 0;
    while (data[i])
    {
        if (check_if_link(data[i]))
            n_links++;
        i++;
    }
    return (n_links);
}

int count_n_rooms(char **data)
{
    int i;
    int n_rooms;

    i = 0;
    n_rooms = 0;
    while (data[i])
    {
        if (check_if_room(data[i]))
            n_rooms++;
        i++;
    }
    return (n_rooms);
}

t_vector get_room_pos(char *line)
{
    t_vector pos;
    int i;

    i = 0;
    while (line[i] != ' ')
        i++;
    pos.x = ft_atoi(&line[i + 1]);
    while (line[i] != ' ')
        i++;
    pos.y = ft_atoi(&line[i + 1]);
    return (pos);
}

int	open_map(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0) {
		ft_print_error("Error: Could not open file.\n");
        exit(EXIT_FAILURE);
    }
	return (fd);
}