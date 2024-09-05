#include "lem_in.h"

// static t_node *copy_path(t_list *path);

void init_ants(t_lem_in *lem_in)
{
    int i;

    i = 0;
    lem_in->ants = (t_ant *)malloc(sizeof(t_ant) * lem_in->n_ants);
    while (i < lem_in->n_ants)
    {
        lem_in->ants[i].id = i + 1;
        lem_in->ants[i].path = NULL;//
        i++;
    }
}

// static t_list *copy_path(t_list *path) {
//     if (!path) 
//         return NULL;

//     t_list *new_path = create_node(path->room);
//     t_list *current = new_path;
//     t_list *original_current = path->next;

//     while (original_current) {
//         current->next = create_node(original_current->room);
//         current = current->next;
//         original_current = original_current->next;
//     }

//     return (new_path);
// }