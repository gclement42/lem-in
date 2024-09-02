#include "lem_in.h"

static void     move_ants(t_lem_in *lem_in);
static bool     next_room_has_links(t_lem_in *lem_in, char *room_name);
static bool     is_next_room_empty(t_lem_in *lem_in, char *room_name);
static bool     check_if_end_is_linked(t_lem_in *lem_in, t_array *links);
static void     write_ant_move(int ant_id, char *room_name);


void    move_ants_manager(t_lem_in *lem_in)
{
    // display_data(lem_in);
    // display_info_rooms_links(lem_in);
    // display_info_rooms_status(lem_in);
    // display_info_ants(lem_in);
    move_ants(lem_in);
    // display_info_rooms_status(lem_in);
}

static void    move_ants(t_lem_in *lem_in)
{
    t_room      *next_room;

    for (int i = 0; i < lem_in->n_ants; i++)
    {
        if (lem_in->ants[i].room->id == lem_in->end)
            continue ;
        for (size_t j = 0; j < lem_in->ants[i].room->links.size; j++)
        {
            if (check_if_end_is_linked(lem_in, &lem_in->ants[i].room->links))
            {
                lem_in->ants[i].room->is_empty = true;
                lem_in->ants[i].room = &lem_in->rooms[lem_in->end];
                write_ant_move(i, lem_in->ants[i].room->name);
                break ;
            }
            if (next_room_has_links(lem_in, lem_in->ants[i].room->links.arr[j]) && is_next_room_empty(lem_in, lem_in->ants[i].room->links.arr[j]))
            {
                if (lem_in->ants[i].room->id != lem_in->start)
                    lem_in->ants[i].room->is_empty = true;
                next_room = get_room(lem_in, lem_in->ants[i].room->links.arr[j]);
                next_room->is_empty = false;
                lem_in->ants[i].room = next_room;
                write_ant_move(i, lem_in->ants[i].room->name);
                break ;
            }
        }
    }
    ft_printf("\n");
}

static bool next_room_has_links(t_lem_in *lem_in, char *room_name)
{
    for (int i = 0; i < lem_in->n_rooms; i++)
    {
        if (ft_strncmp(lem_in->rooms[i].name, room_name, ft_strlen(room_name)) == 0)
        {
            if (lem_in->rooms[i].links.size > 0)
                return (true);
            return (false);
        }
    }
    return (false);
}

static bool is_next_room_empty(t_lem_in *lem_in, char *room_name)
{
    for (int i = 0; i < lem_in->n_rooms; i++)
    {
        if (ft_strncmp(lem_in->rooms[i].name, room_name, ft_strlen(room_name)) == 0)
        {
            if (lem_in->rooms[i].is_empty || lem_in->rooms[i].id == lem_in->end)
                return (true);
            return (false);
        }
    }
    return (false);
}

static bool check_if_end_is_linked(t_lem_in *lem_in, t_array *links)
{
    for (size_t i = 0; i < links->size; i++)
    {
        if (ft_strncmp(links->arr[i], lem_in->rooms[lem_in->end].name, ft_strlen(links->arr[i])) == 0)
            return (true);
    }
    return (false);
}

static void write_ant_move(int ant_id, char *room_name)
{
    ft_printf("L%d-%s ", ant_id, room_name);
}