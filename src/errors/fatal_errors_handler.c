#include "lem_in.h"

void fatal_errors_handler(t_lem_in *lem_in, char *error)
{
	print_error(error);
	free_lem_in(lem_in);
	exit(1);
}