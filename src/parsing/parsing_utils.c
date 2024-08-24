#include "lem_in.h"

int	open_map(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		ft_printf("Error: Could not open file %s\n", map_path);
	return (fd);
}