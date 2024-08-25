#include "lem_in.h"

bool check_if_ants(char *line)
{
    if (check_if_link(line) || check_if_room(line) || check_if_command(line) || check_if_comment(line))
        return (false);
    return (true);
}

bool check_if_valid_nb_ants(char *line)
{

}