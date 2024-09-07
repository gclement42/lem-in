#include "lem_in.h"

static void calculate_all_rooms_cost(t_lem_in *lem_in);
static int reach_path(t_lem_in lem_in, t_room *room);

void algo_manager(t_lem_in *lem_in)
{
    calculate_all_rooms_cost(lem_in);
}

static void calculate_all_rooms_cost(t_lem_in *lem_in) 
{
    t_room *room;

    room = &lem_in->rooms[lem_in->start];
    reach_path(*lem_in, room);
    room->cost = -1;
}

static int reach_path(t_lem_in lem_in, t_room *room)
{
    t_room *next_room;
    int cost;
    size_t i;

    i = 0;
    cost = 0;

    if (lem_in.end == room->id)
        return lem_in.n_rooms;

    room->visited = true;
    while (room->links[i] != -1)
    {
        next_room = &lem_in.rooms[room->links[i]];

        if (!next_room->visited || room->id == lem_in.start) {
            cost = reach_path(lem_in, next_room);
            if (cost >= next_room->cost || (next_room->cost == 0 && cost <= -1)) {
                next_room->cost = cost;
            }
            if (room->links[i + 1] == -1) {
                room->visited = false;
                return next_room->cost - 1;
            }
            else {
                if (cost >= next_room->cost || (next_room->cost == 0 && cost <= -1))
                    room->cost = next_room->cost - 1;
            }
        }
        i++;
    }
    room->visited = false;
    return room->cost;
}