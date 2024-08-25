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