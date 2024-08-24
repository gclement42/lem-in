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

char *get_room_name(char *line)
{
    char *name;
    int i;

    i = 0;
    while (line[i] != ' ')
        i++;
    name = ft_substr(line, 0, i);
    return (name);
}

int	open_map(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0) {
		ft_printf("Error: Could not open file %s\n", map_path);
        exit(EXIT_FAILURE);
    }
	return (fd);
}