#include "lem_in.h"

void *ft_realloc(void *ptr, size_t size, size_t len)
{
    void *new_ptr;

    size = size * len;
    if (!ptr)
        return (malloc(size));
    if (size == 0)
        return (NULL);
    new_ptr = malloc(size);
    if (!new_ptr)
        return (NULL);
    ft_bzero(new_ptr, size);
    return (new_ptr);
}

bool next_room_is_end(t_lem_in *lem_in, t_ant *ant)
{
    if (ant->path->room->id == lem_in->end)
        return (true);
    return (false);
}

t_node *create_node(t_room *room)
{
    t_node *node;

    node = malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->room = room;
    node->next = NULL;
    return (node);
}

void insert_node(t_node **head, t_node *node)
{
    t_node *tmp;

    if (!node)
        return ;
    if (!*head)
    {
        printf("head is null\n");
        *head = node;
        return ;
    }
    tmp = *head;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = node;
}

void insert_at_start(t_node **head, t_node *node)
{
    if (!node)
        return ;
    node->next = *head;
    *head = node;
}

t_node *get_last_node(t_node *lst)
{
    t_node *tmp;

    tmp = lst;
    while (tmp->next)
        tmp = tmp->next;
    return (tmp);
}

void remove_last_node(t_node **lst)
{
    t_node *tmp;
    t_node *prev;

    tmp = *lst;
    prev = NULL;
    while (tmp->next)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    if (prev)
        prev->next = NULL;
    free(tmp);
}

size_t get_size_lst(t_node *lst)
{
    t_node *tmp;
    size_t i = 0;

    tmp = lst;
    while (tmp)
    {
        tmp = tmp->next;
        i++;
    }
    return (i);
}



void display_lst(t_node *lst)
{
    t_node *tmp;
    int i = 0;

    tmp = lst;
    
    while (tmp)
    {
        ft_printf("%s -> ", tmp->room->name);
        tmp = tmp->next;
        i++;
    }
    ft_printf("NULL\n");
    ft_printf("lst length: %d\n", i);
}