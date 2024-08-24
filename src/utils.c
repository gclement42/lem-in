#include "lem_in.h"

void ft_print_error(char *error)
{
    ft_putstr_fd("Error: ", 2);
    ft_putstr_fd(error, 2);
}