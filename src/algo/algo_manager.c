#include "lem_in.h"

static void find_path(t_lem_in *lem_in, t_node **path);
static t_room *choose_next_room(t_lem_in *lem_in, t_room *room);
static void remove_bad_path(t_node **path, t_node *cross_road);
static void set_cost_bad_path(t_node *path);

t_node    *algo_manager(t_lem_in *lem_in)
{
    t_node *path = NULL;

    find_path(lem_in, &path);
    return (path);
}

static void find_path(t_lem_in *lem_in, t_node **path) 
{
    t_room *current_room;
    t_room *next_room;
    t_node *cross_road;


    current_room = &lem_in->rooms[lem_in->start];
    cross_road = NULL;
    while (current_room->id != lem_in->end)
    {
        insert_node(path, create_node(current_room));
        if (current_room->links.size >= 2)
            cross_road = get_last_node(*path);
        next_room = choose_next_room(lem_in, current_room);
        if (next_room->id == current_room->id) {
            current_room = cross_road->room;
            printf("cross_road->room->name: %s\n", cross_road->room->name);
            remove_bad_path(path, cross_road);
            continue; 
        }
        current_room = next_room;
    }
    insert_node(path, create_node(current_room));
}

static void remove_bad_path(t_node **path, t_node *cross_road)
{
    t_node *tmp;
    t_node *last;

    tmp = *path;
    while (tmp && tmp->next != cross_road)
    {
        tmp = tmp->next;
    }
    if (!tmp)
        return;
    last = tmp;
    last->next = NULL;
    set_cost_bad_path(cross_road);
}

static void set_cost_bad_path(t_node *path)
{
    t_node *prev;

    while (path)
    {
        path->room->cost = -1;
        prev = path;
        path = path->next;
        free(prev);
    }
}

static t_room *choose_next_room(t_lem_in *lem_in, t_room *room)
{
    t_room *tmp_next_room;
    t_room *next_room;
    size_t i;

    i = 1;
    if (room->links.size == 0)
        return room;
    next_room = get_room(lem_in, room->links.arr[0]);

    while (i < room->links.size)
    {
        tmp_next_room = get_room(lem_in, room->links.arr[i]);
        if (tmp_next_room->id == lem_in->end)
            return tmp_next_room;
        if (tmp_next_room->cost != -1)
            next_room = tmp_next_room;
        i++;
    }
    return next_room;
}