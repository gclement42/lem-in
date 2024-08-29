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
# include "link.h"
# include "room.h"
# include "parsing.h"
# include "errors.h"
# include "free.h"
# include "ants.h"

// ----------------------------- Global utils -----------------------------

void        *ft_realloc(void *ptr, size_t size, size_t len);

// ----------------------------- Display functions -----------------------------

void        display_data(t_lem_in *lem_in);
void        display_info_rooms(t_lem_in *lem_in);
void        display_info_ants(t_lem_in *lem_in);

#endif