#ifndef PARSING_H
# define PARSING_H

# include "lem_in.h"
# include <fcntl.h>

char                **get_data(char *map_path);
int	                open_map(char *map_path);
t_lem_in            parse_data(char **data);

// ----------------------------- Parsing utils -----------------------------

bool                check_if_comment(char *line);
bool                check_if_command(char *line);
bool                check_if_room(char *line);
bool                check_if_link(char *line);
bool                check_is_valid_link(char *line);

int                 count_n_links(char **data);
int                 count_n_rooms(char **data);
char                *get_room_name(char *line);
t_vector            get_room_pos(char *line);

#endif