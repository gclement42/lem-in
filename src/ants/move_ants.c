#include "lem_in.h"

void    move_ants_manager(t_lem_in *lem_in)
{
    display_data(lem_in);
    display_info_rooms_links(lem_in);
    display_info_rooms_status(lem_in);
    display_info_ants(lem_in);
    move_ants(lem_in);
}

static bool is_next_room_empty(t_lem_in *lem_in, int room_id)
{
    if (lem_in->rooms[room_id].is_empty)
        return (true);
    return (false);
}

static int get_room_id(t_lem_in *lem_in, char *room_name)
{
    int i;

    i = 0;
    while (i < lem_in->n_rooms)
    {
        if (ft_strncmp(lem_in->rooms[i].name, room_name, ft_strlen(room_name)) == 0)
            return (lem_in->rooms[i].id);
        i++;
    }
    return (-1);
}

void    move_ants(t_lem_in *lem_in)
{
    int         i;
    size_t      j;
    int         room_id;

    for (int c = 0; c < 1; c++)
    {
        i = 0;
        while (i < lem_in->n_ants)
        {
            j = 0;
            while(j < lem_in->ants[i].room->links.size)
            {
                room_id = get_room_id(lem_in, lem_in->ants[i].room->links.arr[j]);
                if (room_id == -1)
                    return ;
                if (is_next_room_empty(lem_in, room_id))
                {
                    printf("ROOM_ID = %d\n", room_id);
                    lem_in->ants[i].room = &lem_in->rooms[room_id];
                    lem_in->rooms[room_id].is_empty = false;
                    lem_in->rooms[lem_in->ants[i].room->id].is_empty = true;
                    display_info_rooms_status(lem_in);
                }
                j++;
            }
            i++;
        }
    }

    printf("After move\n");
    display_info_rooms_status(lem_in);
    display_info_ants(lem_in);
}