#ifndef PARSING_H
# define PARSING_H

# include "lem_in.h"
# include <fcntl.h>

char                **get_data(char *map_path);
int	                open_map(char *map_path);
t_lem_in            parse_data(char **data);
char                *get_room_name(char *line);

bool                check_if_comment(char *line);
bool                check_if_command(char *line);
bool                check_if_room(char *line);
bool                check_if_link(char *line);

#endif