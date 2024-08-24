/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:51:33 by lboulatr          #+#    #+#             */
/*   Updated: 2023/04/30 11:40:58 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putchar_fd_count(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

void	ft_putchar_fd_pf(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd_pf(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

void	ft_putnbr_fd_pf(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n >= 0 && n <= 9)
			ft_putchar_fd_pf(n + 48, fd);
		else if (n < 0)
		{
			ft_putchar_fd_pf('-', fd);
			ft_putnbr_fd_pf(n * (-1), fd);
		}
		else
		{
			ft_putnbr_fd_pf((n / 10), fd);
			ft_putnbr_fd_pf((n % 10), fd);
		}
	}
}

int	ft_putstr_fd_count(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
	else
	{
		write(fd, "(null)", 6);
		i += 6;
	}
	return (i);
}
