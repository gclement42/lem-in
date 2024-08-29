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
	if (fd < 0) 
    {
		print_error("Could not open file.\n");
        return (-1);
    }
	return (fd);
}

void full_gnl_loop(int fd)
{
    char *line;

    line = get_next_line(fd);
    while (line)
    {
        free(line);
        line = get_next_line(fd);
    }
}

bool is_num(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (false);
        i++;
    }
    return (true);
}