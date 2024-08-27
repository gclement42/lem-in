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

static t_array *init_data(char *filename)
{
    t_array *data;

    data = malloc(sizeof(t_array));
    data->size = 0;
    data->arr = malloc_arr(filename);
    if (!data->arr)
        return (NULL);
    return (data);
}

static void read_data(t_array *data, int fd) 
{
    int i;
    char *line;
    char *trim_line;

    i = 0;
    line = get_next_line(fd);

    data->arr[0] = ft_strdup(line);
    if (!data->arr[0])
        printf("Error\n");// TODO: free data
    while (line)
    {
        printf("line: %s\n", line);
        free(line);
        line = get_next_line(fd);
        if (!line)
            break;
        if (check_if_comment(line))
            continue;
        i++;
        trim_line = ft_strtrim(line, " \n");
        data->arr[i] = trim_line;
        if (!data->arr[i]) {
            free_array(data);
            fatal_errors_handler(NULL, "Malloc error.\n");
        }
        data->size++;
    }
    free(line);
}

t_array *get_data(char *filename)
{
    int fd;
    t_array *data;

    data = init_data(filename);
    if (!data)
        return (NULL);
    fd = open_map(filename);
    read_data(data, fd);
    close(fd);
    return (data);
}