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
    lem_in->rooms = NULL;
    return (true);
}

static void get_links(t_lem_in *lem_in, char **data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (data[i])
    {
        if (check_if_link(data[i]) && check_is_valid_link(data[i]))
        {
            lem_in->links[j] = ft_strdup(data[i]);
            j++;
        }
        i++;
    }
    lem_in->links[j] = NULL;
    ft_print_array(lem_in->links);
}

t_lem_in parse_data(char **data)
{  
    t_lem_in    lem_in;

    init_lem_in(&lem_in, data);
    get_links(&lem_in, data);

    
    return (lem_in);
}