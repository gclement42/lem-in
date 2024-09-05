#include "lem_in.h"

static void     move_ants(t_lem_in *lem_in);
static void     write_ant_move(int ant_id, char *room_name);
static t_room   *get_next_room(t_lem_in *lem_in, t_room *room);


void    move_ants_manager(t_lem_in *lem_in)
{
    move_ants(lem_in);
}

static void    move_ants(t_lem_in *lem_in)
{
    t_room      *next_room;
    t_ant       *ants;

    ants = lem_in->ants;
    for (int i = 0; i < lem_in->n_ants; i++)
    {
        if (ants[i].room->id == lem_in->end)
            continue;
        next_room = get_next_room(lem_in, ants[i].room);
        if (next_room->is_empty == false && next_room->id != lem_in->end)
            continue;
        ants[i].room->is_empty = true;
        next_room->is_empty = false;
        ants[i].room = next_room;
        write_ant_move(ants[i].id, next_room->name);
    }
    ft_printf("\n");
}

static t_room   *get_next_room(t_lem_in *lem_in, t_room *room)
{
    t_room      *next_room;
    t_room      *tmp;
    size_t      i;

    i = 1;
    if (!room->links)
        return (room);
    next_room = &lem_in->rooms[room->links[0]];
    while (room->links[i] != -1)
    {
        tmp = &lem_in->rooms[room->links[i]];
        if (tmp->cost > next_room->cost && tmp->is_empty)
            next_room = tmp;
        i++;
    }
    return (next_room);
}

static void write_ant_move(int ant_id, char *room_name)
{
    ft_printf("L%d-%s ", ant_id, room_name);
}