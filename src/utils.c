#include "lem_in.h"

void display_data(t_lem_in *lem_in)
{
    int i;

    i = 0;
    printf("Ants: %d\n", lem_in->ants);
    printf("Rooms:\n\n");
    printf("Start: %s\n", lem_in->rooms[lem_in->start].name);
    printf("End: %s\n", lem_in->rooms[lem_in->end].name);
    while (lem_in->rooms[i].id != -1)
    {
        printf("%d: %s, [%d, %d]\n", lem_in->rooms[i].id, lem_in->rooms[i].name, lem_in->rooms[i].pos.x, lem_in->rooms[i].pos.y);
        int j = 0;
        while (lem_in->rooms[i].links && lem_in->rooms[i].links[j])
        {
            printf("Link: %s\n", lem_in->rooms[i].links[j]);
            j++;
        }
        i++;
    }
    i = 0;
}

void *ft_realloc(void *ptr, size_t size)
{
    void *new_ptr;

    if (!ptr)
        return (malloc(size));
    if (size == 0)
    {
        free(ptr);
        return (NULL);
    }
    new_ptr = malloc(size);
    if (!new_ptr)
        return (NULL);
    ft_bzero(new_ptr, size);
    ft_memcpy(new_ptr, ptr, size);
    free(ptr);
    return (new_ptr);
}