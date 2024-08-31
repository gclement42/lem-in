#include "lem_in.h"

static bool check_if_ants(char *line)
{
    if (check_if_link(line) || check_if_room(line) || check_if_command(line) || check_if_comment(line))
        return (false);
    return (true);
}

void parse_nb_ants(t_lem_in *lem_in, t_array *data)
{
    int i;
    int nb_ants;

    i = 0;
    nb_ants = 0;
    while (data->arr[i] && check_if_command(data->arr[i]))
    {
        i++;
    }
    if (!check_if_ants(data->arr[i]))
        fatal_errors_handler(lem_in, "Wrong format of ants number.\n", data);
    nb_ants = ft_atoi(data->arr[i]);
    if (nb_ants <= 0)
        fatal_errors_handler(lem_in, "Invalid number of ants.\n", data);
    lem_in->n_ants = nb_ants;
    data->index = i + 1;
}