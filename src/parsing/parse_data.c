#include "lem_in.h"

static bool init_lem_in(t_lem_in *lem_in, char **data)
{
    lem_in->ants = ft_atoi(data[0]);
    if (lem_in->ants <= 0)
        return (false);

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
    int j;

    i = 1;
    j = 0;
    while (data[i])
    {
        if (check_if_room(data[i]))
        {
            t_vector room_pos = get_room_pos(data[i]);
            lem_in->rooms[j].id = j;
            lem_in->rooms[j].is_empty = true;
            lem_in->rooms[j].pos.x = room_pos.x;
            lem_in->rooms[j].pos.y = room_pos.y;
            j++;
        }
        i++;
    }
    lem_in->rooms[j].id = -1;
}

t_lem_in parse_data(char **data)
{  
    t_lem_in    lem_in;

    init_lem_in(&lem_in, data);
    if (!get_links(&lem_in, data))
        ft_print_error("There is an invalid link.\n");
        // put a return here
        
    get_rooms(&lem_in, data);

    return (lem_in);
}