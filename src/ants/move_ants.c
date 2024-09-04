#include "lem_in.h"

static void     move_ants(t_lem_in *lem_in);
static void     write_ant_move(int ant_id, char *room_name);


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
        if (ants[i].path->room->id == lem_in->end)
            continue;
        next_room = ants[i].path->next->room;
        if (next_room->id != lem_in->end && next_room->is_empty == false) {
            continue;
        }
        ants[i].path->room->is_empty = true;
        ants[i].path->room = next_room;
        next_room->is_empty = false;
        write_ant_move(ants[i].id, next_room->name);
        ants[i].path = ants[i].path->next;
    }
    ft_printf("\n");
}

static void write_ant_move(int ant_id, char *room_name)
{
    ft_printf("L%d-%s ", ant_id, room_name);
}