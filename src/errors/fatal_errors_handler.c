#include "lem_in.h"

void fatal_errors_handler(t_lem_in *lem_in, char *error)
{
	free_lem_in(lem_in);
	print_error(error);
	exit(1);
}