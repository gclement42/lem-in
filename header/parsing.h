#ifndef PARSING_H
# define PARSING_H

# include "lem_in.h"
# include <fcntl.h>
# include <limits.h>

t_array             *get_data(char *filename);
int	                open_map(char *map_path);

t_lem_in            parse_data(t_array *data);
void                parse_nb_ants(t_lem_in *lem_in, t_array *data);
void                parse_rooms(t_lem_in *lem_in, t_array *data);
void                parse_links(t_lem_in *lem_in, t_array *data);

// ----------------------------- Parsing utils -----------------------------

bool                check_if_comment(char *line);
bool                check_if_command(char *line);
bool                check_if_room(char *line);
bool                check_if_link(char *line);
bool 				check_if_room_exist(t_lem_in *lem_in, char *room_name);
bool                is_num(char *str);

int                 count_n_rooms(char **data);
void                set_room(t_room *room, int id, char *name, t_vector3 pos);
void 				set_command(t_lem_in *lem_in, char *line, int room_id);
void                set_room(t_room *room, int id, char *name, t_vector3 pos);
void                full_gnl_loop(int fd);
int	                ft_atoi_lem_in(const char *str);


#endif