/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:47:16 by lboulatr          #+#    #+#             */
/*   Updated: 2023/04/30 11:40:58 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	ft_putnbr_fd_count_bis(int n, int fd)
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

int	ft_putnbr_fd_count(int n, int fd)
{
	ft_putnbr_fd_count_bis(n, fd);
	return (count(n));
}
