/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:53:52 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/22 17:03:10 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_hexa(unsigned int nbr, int check, char *base, int *x);
int		ft_hexaptr(unsigned long long nbr, int c, char *b, int *x);
int		ft_putnbr_fd_usign(unsigned int n, int fd);
int		ft_putchar_fd_count(char c, int fd);
int		count(long long int n);
int		ft_putstr_fd_count(char *s, int fd);
int		ft_putnbr_fd_count(int n, int fd);
void	ft_putchar_fd_pf(char c, int fd);
void	ft_putstr_fd_pf(char *s, int fd);
void	ft_putnbr_fd_pf(int n, int fd);

#endif
