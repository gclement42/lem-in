#ifndef ERRORS_H
# define ERRORS_H

# include "lem_in.h"

void fatal_errors_handler(t_lem_in *lem_in, char *error);
void print_error(char *error);

#endif