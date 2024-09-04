#include "lem_in.h"

t_room *choose_next_room(t_lem_in *lem_in, t_room *room)
{
    t_room *tmp_next_room;
    t_room *next_room;
    size_t i;

    i = 1;
    if (room->links.size == 0)
        return room;
    next_room = get_room(lem_in, room->links.arr[0]);
    while (i < room->links.size) {
        tmp_next_room = get_room(lem_in, room->links.arr[i]);
        if (tmp_next_room->id == lem_in->end)
            return tmp_next_room;
        if (tmp_next_room->links.size > next_room->links.size)
            next_room = tmp_next_room;
        i++;
    }
    return next_room;
}

void find_path(t_lem_in *lem_in, t_node **path) 
{
  
    t_room *current_room;
    t_room *next_room;

    current_room = &lem_in->rooms[lem_in->start];
    while (current_room->id != lem_in->end) {
        insert_node(path, create_node(current_room));
        next_room = choose_next_room(lem_in, current_room);
        if (next_room->id == current_room->id) {
            ft_printf("No path found\n");
            return ;
        }
        current_room = next_room;
    }
    insert_node(path, create_node(current_room));
}

t_node    *algo_manager(t_lem_in *lem_in)
{
    t_node *path = NULL;
    find_path(lem_in, &path);
    return path;
}
