#ifndef PARSING_H
# define PARSING_H

# include "lem_in.h"
# include <fcntl.h>

t_array             *get_data(char *filename);
int	                open_map(char *map_path);
t_lem_in            parse_data(t_array *data);

// ----------------------------- Parsing utils -----------------------------

bool                check_if_comment(char *line);
bool                check_if_command(char *line);
bool                check_if_room(char *line);
bool                check_if_link(char *line);
bool                check_is_valid_link(char *line);
bool                check_if_ants(char *line);

int                 count_n_links(char **data);
int                 count_n_rooms(char **data);
char                *get_room_name(char *line);
t_vector            get_room_pos(char *line);



#endif