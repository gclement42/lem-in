#include "lem_in.h"

void fatal_errors_handler(t_lem_in *lem_in, char *error, t_array *data)
{
	print_error(error);
	free_lem_in(lem_in);
	free_array(data);
	free(data);
	exit(EXIT_FAILURE);
}

void error_data(char *error, char *line, t_array *data, int fd)
{
	print_error(error);
	free(line);
	free_array(data);
	free(data);
	close(fd);
	exit(EXIT_FAILURE);
}