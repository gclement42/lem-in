#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdbool.h>

# include "../libft/include/libft.h"
# include "struct.h"
# include "room.h"
# include "parsing.h"
# include "errors.h"
# include "free.h"

// ----------------------------- Global utils -----------------------------
void display_data(t_lem_in *lem_in);
void *ft_realloc(void *ptr, size_t size);


#endif