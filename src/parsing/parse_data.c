#include "lem_in.h"

static void init_lem_in(t_lem_in *lem_in, char *first_line)
{
    lem_in->ants = ft_atoi(first_line);
    lem_in->start = 0;
    lem_in->end = 0;
    lem_in->n_rooms = 0;
    lem_in->rooms = NULL;
}

t_lem_in parse_data(char **data)
{
    int         i;      
    t_lem_in    lem_in;

    i = 1;
    init_lem_in(&lem_in, data[0]);

    while (data[i])
    {
        if (check_if_comment(data[i]))
        {
            ft_printf("Comment: %s\n", data[i]);
            i++;
            continue;
        }

        if (check_if_command(data[i]))
            ft_printf("Command: %s\n", data[i]);

        if (check_if_room(data[i]))
        {
            ft_printf("Room: %s\n", data[i]);
            if (check_if_command(data[i - 1]))
            {

            }
  
        }

        if (check_if_link(data[i]))
            ft_printf("Link: %s\n", data[i]);

        i++;
    }
    
    return (lem_in);
}