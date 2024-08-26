#include "lem_in.h"

static bool init_lem_in(t_lem_in *lem_in, char **data)
{
    lem_in->ants = 1;

    lem_in->start = 0;
    lem_in->end = 0;
    lem_in->n_rooms = 0;

    lem_in->links = malloc(sizeof(char *) * (count_n_links(data) + 1));
    if (!lem_in->links)
        return (false);
    lem_in->rooms = malloc(sizeof(t_room) * (count_n_rooms(data) + 1));
    if (!lem_in->rooms)
        return (false);

    return (true);
}

static bool get_links(t_lem_in *lem_in, char **data)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (data[i])
    {
        if (check_if_link(data[i]))
        {
            if (!check_is_valid_link(data[i]))
                return (false);
            lem_in->links[j] = ft_strdup(data[i]);
            j++;
        }
        i++;
    }
    lem_in->links[j] = NULL;
    return (true);
}

static void get_rooms(t_lem_in *lem_in, char **data)
{
    int i;
    int id;

    i = 1;
    id = 0;
    while (data[i])
    {
        if (check_if_room(data[i]))
        {
            t_vector room_pos = get_room_pos(data[i]);
            lem_in->rooms[id].id = id;
            lem_in->rooms[id].name = get_room_name(data[i]);
            lem_in->rooms[id].is_empty = true;
            lem_in->rooms[id].pos.x = room_pos.x;
            lem_in->rooms[id].pos.y = room_pos.y;
            id++;
        }
        i++;
    }
    lem_in->rooms[id].id = -1;
}

static void get_nb_ants(t_lem_in *lem_in, char **data)
{
    int i;
    int nb_ants;

    i = 0;
    nb_ants = 0;
    while (data[i])
    {
        if (check_if_ants(data[i])) 
        {
            nb_ants = ft_atoi(data[i]);
            break;
        }
        i++;
    }
    if (nb_ants <= 0)
        fatal_errors_handler(lem_in, "Invalid number of ants.\n");
    lem_in->ants = nb_ants;
}

t_lem_in parse_data(char **data)
{  
    t_lem_in    lem_in;
    int         data_index;

    init_lem_in(&lem_in, data);
    get_nb_ants(&lem_in, data);
    get_rooms(&lem_in, data);
    if (!get_links(&lem_in, data))
        print_error("There is an invalid link.\n");
    return (lem_in);
}