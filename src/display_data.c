//TODO: remove this file

#include "lem_in.h"

void display_data(t_lem_in *lem_in)
{
    int i;

    i = 0;
    printf("Ants: %d\n", lem_in->n_ants);
    printf("Rooms:\n\n");
    printf("Start: %s\n", lem_in->rooms[lem_in->start].name);
    printf("End: %s\n", lem_in->rooms[lem_in->end].name);
    while (lem_in->rooms[i].id != -1)
    {
        printf("%d: %s, [%d, %d]\n", lem_in->rooms[i].id, lem_in->rooms[i].name, lem_in->rooms[i].pos.x, lem_in->rooms[i].pos.y);
        size_t j = 0;
        while (j < lem_in->rooms[i].links.size)
        {
            printf("Link: %s\n", lem_in->rooms[i].links.arr[j]);
            j++;
        }
        i++;
    }
    i = 0;
}

void    display_info_rooms(t_lem_in *lem_in)
{
    int i;

    i = 0;
    printf("----------------------------------\n");

    i = 0;
    printf("\n");
    while (i < lem_in->n_rooms)
    {
        printf("\033[1;35mRoom %s\033[0m is linked to :\n", lem_in->rooms[i].name);
        ft_print_array(lem_in->rooms[i].links.arr);
        i++;
    }
    printf("\n----------------------------------\n");
}

void display_info_ants(t_lem_in *lem_in)
{
    int i;

    i = 0;
    printf("----------------------------------\n");

    i = 0;
    printf("\n");
    while (i < lem_in->n_ants)
    {
        printf("\033[1;35mAnt %d\033[0m is in room %s\n", lem_in->ants[i].id, lem_in->ants[i].room->name);
        i++;
    }
    printf("\n----------------------------------\n");
}