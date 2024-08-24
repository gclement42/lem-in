#include "lem_in.h"

static void init_lem_in(t_lem_in *lem_in, char *first_line)
{
    lem_in->ants = ft_atoi(first_line);
    lem_in->start = 0;
    lem_in->end = 0;
    lem_in->n_rooms = 0;
    lem_in->rooms = NULL;
}

t_lem_in parse_data(char **data)
{
    t_lem_in    lem_in;

    init_lem_in(&lem_in, data[0]);
    

    return (lem_in);
}