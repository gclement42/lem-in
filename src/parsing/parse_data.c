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

static bool get_links(t_lem_in *lem_in, t_array *data)
{
    int *i;
    int j;

    i = &data->index;
    j = 0;
    while (data->arr[*i])
    {
        if (check_if_link(data->arr[*i]))
        {
            if (!check_is_valid_link(data->arr[*i])) 
                return (false);
            lem_in->links[j] = ft_strdup(data->arr[*i]);
            j++;
        }
        *i += 1;
    }
    lem_in->links[j] = NULL;
    return (true);
}

static void get_rooms(t_lem_in *lem_in, t_array *data)
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
        set_room(&lem_in->rooms[id], id, room_name, room_pos);
        id++;
        *i += 1;
    }
    lem_in->rooms[id].id = -1;
}

static void get_nb_ants(t_lem_in *lem_in, t_array *data)
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
        fatal_errors_handler(lem_in, "Bad position of ants number.\n");
    nb_ants = ft_atoi(data->arr[i]);
    if (nb_ants <= 0)
        fatal_errors_handler(lem_in, "Invalid number of ants.\n");
    lem_in->ants = nb_ants;
    data->index = i + 1;
}

t_lem_in parse_data(t_array *data)
{  
    t_lem_in    lem_in;

    init_lem_in(&lem_in, data->arr);
    get_nb_ants(&lem_in, data);
    get_rooms(&lem_in, data);
    if (!get_links(&lem_in, data))
        print_error("There is an invalid link.\n");
    return (lem_in);
}