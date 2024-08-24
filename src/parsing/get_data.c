#include "lem_in.h"

static int count_line(char *filename) 
{
    int count;
    int fd;

    count = 0;
    fd = open_map(filename);
    while (get_next_line(fd))
        count++;
    close(fd);
    return (count);
}

static char **malloc_data(char *filename)
{
    char **data;
    int count;

    count = count_line(filename);
    data = (char **)malloc(sizeof(char *) * (count + 1));
    if (!data)
        return (NULL);
    return (data);
}

char **get_data(char *filename)
{
    int fd;
    int count;
    int i;
    char **data;
    char *line;

    i = 0;
    data = malloc_data(filename);
    if (!data)
        return (NULL);
    fd = open_map(filename);
    line = get_next_line(fd);
    data[0] = ft_strdup(line);
    if (!data[0])
        return (NULL);
    
    while (line)
    {
        i++;
        free(line);
        line = get_next_line(fd);
        data[i] = ft_strdup(line);
        if (!data[i])
            return (NULL);
    }
    return (data);
}