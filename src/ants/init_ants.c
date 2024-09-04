#include "lem_in.h"

static t_node *copy_path(t_node *path);

void init_ants(t_lem_in *lem_in)
{
    int i;

    i = 0;
    lem_in->ants = (t_ant *)malloc(sizeof(t_ant) * lem_in->n_ants);
    while (i < lem_in->n_ants)
    {
        lem_in->ants[i].id = i + 1;
        lem_in->ants[i].path = copy_path(lem_in->path);
        i++;
    }
}

static t_node *copy_path(t_node *path) {
    if (!path) 
        return NULL;

    t_node *new_path = create_node(path->room);
    t_node *current = new_path;
    t_node *original_current = path->next;

    while (original_current) {
        current->next = create_node(original_current->room);
        current = current->next;
        original_current = original_current->next;
    }

    return (new_path);
}