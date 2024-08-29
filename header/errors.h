#ifndef ERRORS_H
# define ERRORS_H

# include "lem_in.h"

# define ERR_MALLOC     "Memory allocation failed.\n"
# define ERR_SPLIT      "Split failed.\n"

void        fatal_errors_handler(t_lem_in *lem_in, char *error, t_array *data);     
void        error_data(char *error, char *line, t_array *data, int fd);
void        print_error(char *error);

#endif