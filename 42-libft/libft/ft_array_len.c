/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 02:38:44 by osterger          #+#    #+#             */
/*   Updated: 2023/05/01 02:42:28 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_array_len(char **array)
{
	int	i;

	i = 0;
	if (!array || !array[i])
		return (0);
	while (array[i])
		i++;
	return (i);
}
