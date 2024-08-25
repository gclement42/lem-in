#include "lem_in.h"

void free_lem_in(t_lem_in *lem_in)
{
    if (lem_in->rooms)
        free(lem_in->rooms);
    if (lem_in->links)
        free(lem_in->links);
}

void fatal_errors_handler(t_lem_in *lem_in, char *error)
{
	free_lem_in(lem_in);
	print_error(error);
	print_error("Error\n"); 
	exit(1);
}