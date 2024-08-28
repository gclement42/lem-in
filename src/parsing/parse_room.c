#include "lem_in.h"

bool check_if_room(char *line)
{
    if (check_if_link(line) || check_if_command(line))
        return (false);
    if (line[0] == 'L')
        return (false);
    if (strchr(line, ' ') == NULL)
        return (false);
    return (true);
}

bool check_if_room_already_exist(t_lem_in *lem_in, char *room_name)
{
    if (get_room(lem_in, room_name))
        return (true);
    return (false);
}

int count_n_rooms(char **data)
{
    int i;
    int n_rooms;

    i = 0;
    n_rooms = 0;
    while (data && data[i])
    {
        if (check_if_room(data[i]))
            n_rooms++;
        i++;
    }
    return (n_rooms);
}

t_vector2 get_room_pos(char *line)
{
    t_vector2 pos;
    int i;

    i = 0;
    while (line[i] != ' ')
        i++;
    pos.x = ft_atoi(&line[i + 1]);
    while (line[i] != ' ')
        i++;
    pos.y = ft_atoi(&line[i + 1]);
    return (pos);
}

char *get_room_name(char *line)
{
    char *name;
    int i;

    i = 0;
    while (line[i] != ' ')
        i++;
    name = ft_substr(line, 0, i);

    return (name);
}
