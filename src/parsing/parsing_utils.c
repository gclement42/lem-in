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

int	ft_atoi_lem_in(const char *str)
{
	int			i;
	long long	x;
	int			sign;

	i = 0;
	x = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (x != (((x * 10) + (str[i] - 48)) / 10))
			return (((sign + 1) / -2));
		x = (str[i] - 48) + (x * 10);
		i++;
	}
	x = x * sign;
	if (x > INT_MAX || x < INT_MIN)
        return (((sign + 1) / -2));
	return ((int)x);
}