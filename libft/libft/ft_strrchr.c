/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:38:34 by lboulatr          #+#    #+#             */
/*   Updated: 2023/04/30 11:38:28 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		x;
	char	b;
	char	*s;

	x = ft_strlen(str) - 1;
	b = c;
	s = (char *)str;
	if (!s || (str[x + 1] == '\0' && b == '\0'))
		return (&s[x + 1]);
	while (x >= 0)
	{
		if (s[x] == b)
			return (&s[x]);
		else
			x--;
	}
	return (0);
}
