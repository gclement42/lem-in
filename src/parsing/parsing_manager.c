#include "lem_in.h"

bool parse_file(char *map_path)
{
    int fd;

    fd = open_map(map_path);
    if (fd < 0)
    {
        ft_printf("Error: Could not open file %s\n", map_path);
        return (false);
    }
    char *line = get_next_line(fd);
    
    while (line)
    {
        ft_printf("%s\n", line);
        free(line);
        line = get_next_line(fd);
    }
    return (true);
}