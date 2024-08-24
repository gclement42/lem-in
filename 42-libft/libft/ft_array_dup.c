/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 02:45:37 by osterger          #+#    #+#             */
/*   Updated: 2023/05/01 02:54:08 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	copy_array(char **array, char **dup_array);

char	**ft_array_dup(char **array)
{
	int		array_len;
	char	**dup_array;

	if (!array || !array[0])
		return (NULL);
	array_len = ft_array_len(array);
	dup_array = (char **)malloc((array_len + 1) * sizeof(char *));
	if (!dup_array)
		return (NULL);
	if (copy_array(array, dup_array) != SUCCESS)
		return (NULL);
	dup_array[array_len] = NULL;
	return (dup_array);
}

static int	copy_array(char **array, char **dup_array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		dup_array[i] = ft_strdup(array[i]);
		if (!dup_array[i])
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
