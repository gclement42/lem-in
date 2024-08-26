#include "lem_in.h"

void display_data(t_lem_in *lem_in)
{
    int i;

    i = 0;
    printf("Ants: %d\n", lem_in->ants);
    printf("Rooms:\n\n");
    while (lem_in->rooms[i].id != -1)
    {
        printf("%d: %d %d\n", lem_in->rooms[i].id, lem_in->rooms[i].pos.x, lem_in->rooms[i].pos.y);
        i++;
    }
    i = 0;
    printf("\nLinks:\n\n");
    while (lem_in->links[i])
    {
        printf("%s", lem_in->links[i]);
        i++;
    }
}