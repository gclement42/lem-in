/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_streq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:53:40 by osterger          #+#    #+#             */
/*   Updated: 2023/04/30 12:53:41 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_streq(const char *s1, const char *s2)
{
	if (s1 == NULL)
		return (s2 == NULL);
	return (ft_strncmp(s1, s2, ft_strlen(s1) + 1) == 0);
}
