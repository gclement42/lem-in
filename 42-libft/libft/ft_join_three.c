/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 02:34:01 by osterger          #+#    #+#             */
/*   Updated: 2023/05/01 02:36:10 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_join_three(char *str1, char *str2, char *str3)
{
	char	*tmp1;
	char	*tmp2;
	char	*empty;

	empty = NULL;
	if (!str2)
		empty = "";
	if (empty)
	{
		tmp1 = ft_strjoin(str1, empty);
		if (!tmp1)
			return (NULL);
	}
	else
	{
		tmp1 = ft_strjoin(str1, str2);
		if (!tmp1)
			return (NULL);
	}
	tmp2 = ft_strjoin(tmp1, str3);
	if (!tmp2)
		return (ft_free((void **)&tmp1), NULL);
	ft_free((void **)&tmp1);
	return (tmp2);
}
