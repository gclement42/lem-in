#include "lem_in.h"

void fatal_errors_handler(t_lem_in *lem_in, char *error, t_array *data)
{
	if (error)
		print_error(error);
		
	free_lem_in(lem_in);
	free_array(data);
	free(data);
	exit(EXIT_FAILURE);
}

void error_data(char *error, char *line, t_array *data, int fd)
{
	if (error)
		print_error(error);

	full_gnl_loop(fd);
	free(line);
	free_array(data);
	free(data);
	close(fd);
	exit(EXIT_FAILURE);
}