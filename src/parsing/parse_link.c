#include "lem_in.h"

static bool check_is_valid_link(char **link_rooms)
{
    int i;

    i = 0;
    while (link_rooms && link_rooms[i])
        i++;
    if (i != 2)
        return (false);
    return (true);
}

static bool check_error_link(t_lem_in *lem_in, char **link_rooms)
{
    if (!link_rooms)
    {
        print_error("Split failed.\n");
        return (false);
    }
    if (!check_is_valid_link(link_rooms))
    {
        print_error("Wrong link format.\n");
        return (false);
    }
    if (!check_if_room_exist(lem_in, link_rooms[0]) || !check_if_room_exist(lem_in, link_rooms[1]))
    {
        print_error("One of the rooms in a link does not exist.\n");
        return (false);
    }
    return (true);
}

bool check_if_link(char *line)
{
    if (ft_strchr(line, '-') && line[0] != 'L' && line[0] != '#')
        return (true);
    return (false);
}

void parse_links(t_lem_in *lem_in, t_array *data)
{
    int *i;
    char **link_rooms;

    i = &data->index;
    while (data->arr[*i])
    {
        if (check_if_command(data->arr[*i]))
        {
            *i += 1;
            continue;
        }
        link_rooms = ft_split(data->arr[*i], '-');
        if (!check_error_link(lem_in, link_rooms) || !set_link_in_rooms(lem_in, link_rooms[0], link_rooms[1], data))
        {
            ft_free_array(link_rooms);
            fatal_errors_handler(lem_in, NULL, data);
        }
        free(link_rooms[0]);
        free(link_rooms[1]);
        free(link_rooms);
        *i += 1;
    }
}