#ifndef PARSING_H
# define PARSING_H

# include "lem_in.h"
# include <fcntl.h>

char                **get_data(char *map_path);
int	                open_map(char *map_path);
t_lem_in            parse_data(char **data);

#endif