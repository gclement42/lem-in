#include "lem_in.h"

static void calculate_all_rooms_cost(t_lem_in *lem_in);
// static t_room *choose_next_room(t_lem_in *lem_in, t_room *room);
static void add_neighbor_in_open_lst(t_lem_in *lem_in, t_list **open_lst, t_list **closed_lst);

void    algo_manager(t_lem_in *lem_in)
{
    calculate_all_rooms_cost(lem_in);
}

static void calculate_all_rooms_cost(t_lem_in *lem_in) 
{
    t_list *open_lst;
    t_list *closed_lst;
    t_room *room;
    t_room *next_room;

    open_lst = NULL;
    closed_lst = NULL;
    (void)closed_lst;
    (void)next_room;
    (void)room;
    ft_lstadd_front(&open_lst, ft_lstnew((void *)&lem_in->rooms[lem_in->start]));
    while (open_lst)
    {
        add_neighbor_in_open_lst(lem_in, &open_lst, &closed_lst);
        break;
    }
    while (open_lst)
    {
        printf("open_lst: %s\n", ((t_room *)open_lst->content)->name);
        open_lst = open_lst->next;
    }
}

static void add_neighbor_in_open_lst(t_lem_in *lem_in, t_list **open_lst, t_list **closed_lst)
{
    size_t i;
    t_room *neighbor;
    t_list *node;
    t_room *room;

    i = 0;
    node = ft_pop(open_lst);
    room = (t_room *)node->content;
    ft_lstadd_front(closed_lst, node);
    while (room->links && room->links[i] != -1)
    {
        neighbor = &lem_in->rooms[room->links[i]];
        if (neighbor->cost > -1) {
            t_list *new_node = ft_lstnew((void *)neighbor);
            if (!new_node)
                return ; // TO-DO error
            ft_lstadd_front(open_lst, new_node);
        }
        i++;
    }
}


// static t_room *choose_next_room(t_lem_in *lem_in, t_room *room)
// {
//     t_room *tmp_next_room;
//     t_room *next_room;
//     size_t i;

//     i = 1;
//     if (room->links.size == 0)
//         return room;
//     next_room = get_room(lem_in, room->links.arr[0]);

//     while (i < room->links.size)
//     {
//         tmp_next_room = get_room(lem_in, room->links.arr[i]);
//         if (tmp_next_room->id == lem_in->end)
//             return tmp_next_room;
//         if (tmp_next_room->cost != -1)
//             next_room = tmp_next_room;
//         i++;
//     }
//     return next_room;
// }

