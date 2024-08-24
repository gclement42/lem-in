/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:47:34 by lboulatr          #+#    #+#             */
/*   Updated: 2023/04/30 11:38:28 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_list;
	t_list	*tmp;
	t_list	*start;

	if (lst && f && del)
	{
		tmp = lst;
		start = ft_lstnew(f(tmp->content));
		if (!start)
			return (NULL);
		tmp = tmp->next;
		while (tmp != NULL)
		{
			n_list = ft_lstnew(f(tmp->content));
			if (!n_list)
			{
				ft_lstclear(&start, del);
				return (NULL);
			}
			ft_lstadd_back(&start, n_list);
			tmp = tmp->next;
		}
		return (start);
	}
	return (NULL);
}
