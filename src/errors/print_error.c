#include "errors.h"

void print_error(char *error)
{
    ft_putstr_fd("\033[1;31mError: ", 2);
    ft_putstr_fd(error, 2);
    ft_putstr_fd("\033[0m", 2);
}