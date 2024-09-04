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
    printf("tpm->next->room->name: %s\n", tmp->next->room->name);

}

void insert_at_start(t_node **head, t_node *node)
{
    if (!node)
        return ;
    node->next = *head;
    *head = node;
}

void display_path(t_node *path)
{
    t_node *tmp;
    int i = 0;

    tmp = path;
    
    while (tmp)
    {
        ft_printf("%s -> ", tmp->room->name);
        tmp = tmp->next;
        i++;
    }
    ft_printf("NULL\n");
    ft_printf("path length: %d\n", i);
}