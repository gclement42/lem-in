/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:18:32 by lboulatr          #+#    #+#             */
/*   Updated: 2023/04/30 11:38:28 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		x;

	i = 0;
	x = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (len == 0 || !(*haystack))
		return (NULL);
	while (haystack[i] && i <= len)
	{
		if (haystack[i] == needle[0])
		{
			x = 0;
			while ((haystack[i + x] == needle[x]
					&& needle[x] != '\0') && (i + x < len))
				x++;
			if (needle[x] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}
