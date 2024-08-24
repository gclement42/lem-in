# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 13:06:34 by lboulatr          #+#    #+#              #
#    Updated: 2023/06/29 08:39:51 by lboulatr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus

RED			            =	\033[1;31m
GREEN			        =	\033[1;32m
YELLOW			        =	\033[1;33m
BLUE			        =	\033[0;36m
EOC					    =	\033[0m

SRCS                    = libft/ft_atoi.c\
                        libft/ft_isascii.c\
                        libft/ft_memcmp.c\
                        libft/ft_putendl_fd.c\
                        libft/ft_strdup.c\
                        libft/ft_strlen.c\
                        libft/ft_substr.c\
                        libft/ft_bzero.c\
                        libft/ft_isdigit.c\
                        libft/ft_memcpy.c\
                        libft/ft_putnbr_fd.c\
                        libft/ft_striteri.c\
                        libft/ft_strmapi.c\
                        libft/ft_tolower.c\
                        libft/ft_calloc.c\
                        libft/ft_isprint.c\
                        libft/ft_memmove.c\
                        libft/ft_putstr_fd.c\
                        libft/ft_strjoin.c\
                        libft/ft_strnstr.c\
                        libft/ft_toupper.c\
                        libft/ft_isalnum.c\
                        libft/ft_itoa.c\
                        libft/ft_memset.c\
                        libft/ft_split.c\
                        libft/ft_strlcat.c\
                        libft/ft_strrchr.c\
                        libft/ft_isalpha.c\
                        libft/ft_memchr.c\
                        libft/ft_putchar_fd.c\
                        libft/ft_strchr.c\
                        libft/ft_strlcpy.c\
                        libft/ft_strtrim.c\
                        libft/ft_strncmp.c\
                        libft/ft_lstsize.c\
                        libft/ft_lstadd_front.c\
                        libft/ft_lstnew.c\
                        libft/ft_lstlast.c\
                        libft/ft_lstadd_back.c\
                        libft/ft_lstdelone.c\
                        libft/ft_lstclear.c\
                        libft/ft_lstiter.c\
                        libft/ft_lstmap.c\
                        libft/ft_streq.c\
                        libft/ft_print_array.c\
                        libft/ft_array_len.c\
                        libft/ft_array_dup.c\
                        libft/ft_free.c\
                        libft/ft_free_array.c\
                        libft/ft_join_three.c\
                        libft/ft_close_fd.c\
                        libft/ft_exit.c\
                        \
                        ft_printf/ft_printf.c\
                        ft_printf/ft_hexa.c\
						ft_printf/ft_hexaptr.c\
						ft_printf/ft_putnbr_fd_count.c\
						ft_printf/ft_putnbr_fd_usign.c\
						ft_printf/ft_printf_utils.c\

OBJS                    = $(SRCS:%.c=$(BUILD_DIR)%.o)

BUILD_DIR               = build/

CC                      = cc

HEAD                    = include/libft.h

FLAGS                   = -Wall -Wextra -Werror

NAME                    = libft.a

LIB                     = ar rc

RM                      = rm -rf

$(BUILD_DIR)%.o:        %.c ${HEAD} 
	 					    @mkdir -p $(@D)
							@echo "$(BLUE)[CREATE]$(EOC) $@"
						    @${CC} ${FLAGS} -include${HEAD} -c $< -o $@

all:    			    ${NAME}

${NAME}:    		    ${OBJS}
							@echo "$(BLUE)[CREATE]$(EOC) $@"
						    @${LIB} ${NAME} ${OBJS}
						    @echo "$(GREEN) ➤ $(NAME) is ready !$(EOC)"

clean:
					        @${RM} ${OBJS}
						    @$(RM) $(BUILD_DIR)
							@echo "$(RED)[CLEAN DONE]$(EOC) $@"

fclean:    			    clean
						    @${RM} ${NAME} ${BUILD_DIR}
							@echo "$(RED)[LIBFT IS FULLY CLEANED]$(EOC) $@"

re:                     all fclean
