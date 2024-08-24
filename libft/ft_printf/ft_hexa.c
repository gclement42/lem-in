/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:24:22 by lboulatr          #+#    #+#             */
/*   Updated: 2023/04/30 11:55:31 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_putnbr_base_hexa(unsigned int nbr, char *base, int *x)
{
	if (nbr < 16)
	{
		ft_putchar_fd_pf(base[nbr], 1);
		(*x)++;
	}
	else if (nbr >= 16)
	{
		ft_putnbr_base_hexa((nbr / 16), base, x);
		ft_putnbr_base_hexa((nbr % 16), base, x);
	}
	return ((*x));
}

int	ft_hexa(unsigned int nbr, int check, char *base, int *x)
{
	if (check == 1)
	{
		ft_putstr_fd_pf("0x", 1);
		return (ft_putnbr_base_hexa(nbr, base, x) + 2);
	}
	return (ft_putnbr_base_hexa(nbr, base, x));
}
