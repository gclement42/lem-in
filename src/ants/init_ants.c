#include "lem_in.h"

void init_ants(t_lem_in *lem_in)
{
    int i;

    i = 0;
    lem_in->ants = (t_ant *)malloc(sizeof(t_ant) * lem_in->n_ants);
    while (i < lem_in->n_ants)
    {
        lem_in->ants[i].id = i + 1;
        lem_in->ants[i].path = lem_in->path;
        i++;
    }
}