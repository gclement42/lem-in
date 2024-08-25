#include "lem_in.h"

bool check_if_link(char *line)
{
    if (ft_strchr(line, '-') && line[0] != 'L' && line[0] != '#')
        return (true);
    return (false);
}

bool check_is_valid_link(char *line)
{
    int i;

    i = 0;
    while (line[i] != '-')
        i++;
    if (line[i + 1] == '\0' || line[i + 1] == '\n')
        return (false);
    return (true);
}

int count_n_links(char **data)
{
    int i;
    int n_links;

    i = 0;
    n_links = 0;
    while (data[i])
    {
        if (check_if_link(data[i]))
            n_links++;
        i++;
    }
    return (n_links);
}
