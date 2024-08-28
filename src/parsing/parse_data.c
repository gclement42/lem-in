#include "lem_in.h"

static bool init_lem_in(t_lem_in *lem_in, char **data)
{
    lem_in->ants = 1;

    lem_in->start = -1;
    lem_in->end = -1;
    lem_in->n_rooms = 0;

    lem_in->rooms = malloc(sizeof(t_room) * (count_n_rooms(data) + 1));
    if (!lem_in->rooms)
        return (false);
    
    return (true);
}

static void parse_links(t_lem_in *lem_in, t_array *data)
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
        if (!check_error_link(lem_in, link_rooms))
        {
            ft_free_array(link_rooms);
            fatal_errors_handler(lem_in, "Invalid link.\n", data);
        }
        set_link_in_rooms(lem_in, link_rooms[0], link_rooms[1], data);
        free(link_rooms[0]);
        free(link_rooms[1]);
        free(link_rooms);
        *i += 1;
    }
}

static void parse_rooms(t_lem_in *lem_in, t_array *data)
{
    int *i;
    int id;

    i = &data->index;
    id = 0;
    while (data->arr[*i] && (check_if_room(data->arr[*i]) || check_if_command(data->arr[*i])))
    {
        if (check_if_command(data->arr[*i]))
        {
            *i += 1;
            continue;
        }
        t_vector room_pos = get_room_pos(data->arr[*i]);
        char *room_name = get_room_name(data->arr[*i]);
        if (check_if_room_already_exist(lem_in, room_name))
            fatal_errors_handler(lem_in, "Room already exist.\n", data);
        set_room(&lem_in->rooms[id], id, room_name, room_pos);
        if (check_if_command(data->arr[*i - 1]))
            set_command(lem_in, data->arr[*i - 1], id);
        id++;
        *i += 1;
        lem_in->n_rooms++;
    }
    if (lem_in->n_rooms == 0)
        fatal_errors_handler(lem_in, "No rooms found.\n", data);
    if (lem_in->start == -1 || lem_in->end == -1)
        fatal_errors_handler(lem_in, "No start or end room found.\n", data);
    lem_in->rooms[id].id = -1;
}

static void parse_nb_ants(t_lem_in *lem_in, t_array *data)
{
    int i;
    int nb_ants;

    i = 0;
    nb_ants = 0;
    while (data->arr[i] && check_if_command(data->arr[i]))
    {
        i++;
    }
    if (!check_if_ants(data->arr[i]))
        fatal_errors_handler(lem_in, "Bad position of ants number.\n", data);
    nb_ants = ft_atoi(data->arr[i]);
    if (nb_ants <= 0)
        fatal_errors_handler(lem_in, "Invalid number of ants.\n", data);
    lem_in->ants = nb_ants;
    data->index = i + 1;
}

t_lem_in parse_data(t_array *data)
{  
    t_lem_in    lem_in;

    init_lem_in(&lem_in, data->arr);
    parse_nb_ants(&lem_in, data);
    parse_rooms(&lem_in, data);
    parse_links(&lem_in, data);
    free_array(data);
    free(data);
    return (lem_in);
}