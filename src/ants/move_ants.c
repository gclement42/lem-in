#include "lem_in.h"

static bool     is_next_room_empty(t_lem_in *lem_in, char *room_name);
static void     move_ants(t_lem_in *lem_in);

void    move_ants_manager(t_lem_in *lem_in)
{
    display_data(lem_in);
    display_info_rooms_links(lem_in);
    display_info_rooms_status(lem_in);
    display_info_ants(lem_in);
    move_ants(lem_in);
}

static bool is_next_room_empty(t_lem_in *lem_in, char *room_name)
{
    for (int i = 0; i < lem_in->n_rooms; i++)
    {
        if (ft_strncmp(lem_in->rooms[i].name, room_name, ft_strlen(room_name)) == 0)
        {
            if (lem_in->rooms[i].is_empty)
                return (true);
            else
                return (false);
        }
    }
    return (false);
}


static void    move_ants(t_lem_in *lem_in)
{
    for (int i = 0; i < lem_in->n_ants; i++)
    {
        for (size_t j = 0; j < lem_in->ants[i].room->links.size; j++)
        {
            printf("ant %d\n", i);
            if (is_next_room_empty(lem_in, lem_in->ants[i].room->links.arr[j]))
            {
                printf("next empty room name = %s\n", lem_in->ants[i].room->links.arr[j]);
            }
        }
    }
}