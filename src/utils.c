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

int generate_random_number(int min, int max) 
{
    return (rand() % (max - min + 1)) + min;
}