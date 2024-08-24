/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:06:35 by lboulatr          #+#    #+#             */
/*   Updated: 2023/04/30 11:40:58 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_sort_args(const char *str, va_list args, size_t i)
{
	int		x;
	char	*b;

	x = 0;
	b = "0123456789abcdef";
	if (str[i + 1] == 'c')
		return (ft_putchar_fd_count(va_arg(args, int), 1));
	else if (str[i + 1] == 's')
		return (ft_putstr_fd_count(va_arg(args, char *), 1));
	else if (str[i + 1] == 'p')
		return (ft_hexaptr((unsigned long long)va_arg(args, void *), 1, b, &x));
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		return (ft_putnbr_fd_count(va_arg(args, int), 1));
	else if (str[i + 1] == 'u')
		return (ft_putnbr_fd_usign(va_arg(args, unsigned int), 1));
	else if (str[i + 1] == 'x')
		return (ft_hexa(va_arg(args, unsigned int), 0, b, &x));
	else if (str[i + 1] == 'X')
		return (ft_hexa(va_arg(args, unsigned int), 0, "0123456789ABCDEF", &x));
	else if (str[i + 1] == '%')
		return (ft_putchar_fd_count('%', 1));
	else if (str[i + 1] >= 32 && str[i + 1] <= 126)
		return (ft_putchar_fd_count(str[i + 1], 1));
	else
		return (-1);
}

int	count(long long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 1)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	int		x;

	va_start(args, str);
	i = 0;
	x = 0;
	if (write(1, 0, 0) != 0)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			x += ft_sort_args(str, args, i);
			i += 2;
		}
		else if (str[i] == '%' && str[i + 1] == '\0')
			return (x);
		else
			x += ft_putchar_fd_count(str[i++], 1);
	}
	return (va_end(args), x);
}
