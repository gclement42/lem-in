#include "lem_in.h"

static int count_line(char *filename) 
{
    int count;
    int fd;
    char *line;

    count = 0;
    fd = open_map(filename);
    line = get_next_line(fd);
    while (line) {
        if (!check_if_comment(line))
            count++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (count);
}

static char **malloc_arr(char *filename)
{
    char **data;
    int count;

    count = count_line(filename);
    data = (char **)malloc(sizeof(char *) * (count + 1));
    if (!data)
        return (NULL);
    ft_bzero(data, sizeof(char *) * (count + 1));
    return (data);
}

t_array *get_data(char *filename)
{
    int fd;
    int i;
    t_array *data;
    char *line;

    i = 0;
    data = malloc(sizeof(t_array));
    data->arr = malloc_arr(filename);
    if (!data->arr)
        return (NULL);
    fd = open_map(filename);
    line = get_next_line(fd);
    data->arr[0] = ft_strdup(line);
    if (!data->arr[0])
        return (NULL);
    
    while (line)
    {
        free(line);
        line = get_next_line(fd);
        if (!line)
            break;
        if (check_if_comment(line))
            continue;
        i++;
        line = ft_strtrim(line, " \n");
        data->arr[i] = ft_strdup(line);
        if (!data->arr[i])
            break;
    }
    close(fd);
    return (data);
}