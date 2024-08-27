#include "lem_in.h"

bool check_if_link(char *line)
{
    if (ft_strchr(line, '-') && line[0] != 'L' && line[0] != '#')
        return (true);
    return (false);
}

bool check_is_valid_link(char **link_rooms)
{
    int i;

    i = 0;
    while (link_rooms && link_rooms[i])
        i++;
    if (i != 2)
        return (false);
    return (true);
}

bool check_if_room_exist(t_lem_in *lem_in, char *room_name)
{
    if (!get_room(lem_in, room_name)) {
        return (false);
    }
    return (true);
}

bool check_error_link(t_lem_in *lem_in, char **link_rooms)
{
    if (!check_is_valid_link(link_rooms))
        return (false);
    if (!check_if_room_exist(lem_in, link_rooms[0]) || !check_if_room_exist(lem_in, link_rooms[1])) {
        return (false);
    }
    return (true);
}

int count_n_links(char **data)
{
    int i;
    int n_links;

    i = 0;
    n_links = 0;
    while (data[i])
    {
        if (check_if_link(data[i]))
            n_links++;
        i++;
    }
    return (n_links);
}
