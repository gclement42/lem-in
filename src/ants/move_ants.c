#include "lem_in.h"

void    print_info_ants(t_lem_in *lem_in)
{
    int i;

    i = 0;
    while (i < lem_in->n_ants)
    {
        printf("Ants # %d is in room %s\n", lem_in->ants[i].id, lem_in->ants[i].room->name);
        i++;
    }

    i = 0;
    while (i < lem_in->n_rooms)
    {
        printf("Room %s is empty : %s\n", lem_in->rooms[i].name, lem_in->rooms[i].is_empty ? "true" : "false");
        i++;
    }
}