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
        printf("%d: %s, [%f, %f]\n", lem_in->rooms[i].id, lem_in->rooms[i].name, lem_in->rooms[i].pos.x, lem_in->rooms[i].pos.y);
        size_t j = 0;
        printf("links:\n");
        while (lem_in->rooms[i].links && lem_in->rooms[i].links[j] != -1)
        {
            printf("-> %s\n", lem_in->rooms[lem_in->rooms[i].links[j]].name);
            j++;
        }
        printf("------------------------\n");
        i++;
    }
    i = 0;
}

void    display_info_rooms_links(t_lem_in *lem_in)
{
    int i;

    i = 0;
    printf("----------------------------------\n");

    i = 0;
    while (i < lem_in->n_rooms)
    {
        printf("\033[1;35mRoom %s\033[0m is linked to :\n", lem_in->rooms[i].name);
        for (size_t j = 0; lem_in->rooms[i].links[j] != -1; j++)
        {
            printf("    \033[1;35mRoom %s\033[0m\n", lem_in->rooms[lem_in->rooms[i].links[j]].name);
        }
        i++;
    }
    printf("----------------------------------\n");
}

void    display_info_rooms_status(t_lem_in *lem_in)
{
    int i;

    i = 0;
    printf("----------------------------------\n");

    i = 0;
    while (i < lem_in->n_rooms)
    {
        printf("\033[1;35mRoom #%d %s\033[0m is empty = %s\n", lem_in->rooms[i].id, lem_in->rooms[i].name, lem_in->rooms[i].is_empty ? "true" : "false");
        i++;
    }
    printf("----------------------------------\n");
}

void display_info_ants(t_lem_in *lem_in)
{
    int i;

    i = 0;
    printf("----------------------------------\n");

    i = 0;
    while (i < lem_in->n_ants)
    {
        // printf("\033[1;32mAnt %d\033[0m is in \033[1;35mroom  %s\033[0m\n", lem_in->ants[i].id, lem_in->ants[i].room->name);
        i++;
    }
    printf("----------------------------------\n");
}