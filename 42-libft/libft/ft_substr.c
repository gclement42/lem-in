/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:15:59 by lboulatr          #+#    #+#             */
/*   Updated: 2023/04/30 11:38:28 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	len_count(char const *str, unsigned int start, size_t len)
{
	int	x;

	x = ft_strlen(str);
	if (len > (x - start))
		return (x - start);
	else
		return (len);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	int		x;
	char	*dest;

	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
	{
		dest = malloc(sizeof(char));
		if (!dest)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	else
	{
		x = len_count(str, start, len);
		dest = malloc(sizeof(char) * (x + 1));
		if (!dest)
			return (NULL);
		ft_strlcpy(dest, &str[start], (x + 1));
		dest[x] = '\0';
		return (dest);
	}
}
