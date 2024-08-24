/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:13:19 by lboulatr          #+#    #+#             */
/*   Updated: 2023/06/29 08:40:02 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

# define SUCCESS			EXIT_SUCCESS
# define FAILURE			EXIT_FAILURE

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// ----------------------- LIBFT ----------------------------------------

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isalnum(int c);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *b, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *str, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_strrchr(const char *str, int c);
void		*ft_memchr(const void *str, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*strnstr(const char *haystack, const char *needle, size_t len);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t		ft_strlcat(char *dest, char const *src, size_t size);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int			ft_streq(const char *s1, const char *s2);
void		*ft_free(void **ptr);
char		*ft_join_three(char *str1, char *str2, char *str3);
int			ft_array_len(char **array);
char		**ft_array_dup(char **array);
void		ft_print_array(char **array);
void		ft_close_fd(void);
int			ft_numlen(int nbr);
int			ft_abs(int nbr);
void    	ft_exit(char *msg);

// ----------------------- FT_PRINTF ----------------------------------------

int			ft_printf(const char *str, ...);
int			ft_hexa(unsigned int nbr, int check, char *base, int *x);
int			ft_hexaptr(unsigned long long nbr, int c, char *b, int *x);
int			ft_putnbr_fd_usign(unsigned int n, int fd);
int			ft_putchar_fd_count(char c, int fd);
int			count(long long int n);
int			ft_putstr_fd_count(char *s, int fd);
int			ft_putnbr_fd_count(int n, int fd);
void		ft_putchar_fd_pf(char c, int fd);
void		ft_putstr_fd_pf(char *s, int fd);
void		ft_putnbr_fd_pf(int n, int fd);

#endif 
