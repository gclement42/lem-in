#include "../include/libft.h"

t_list *ft_pop(t_list **lst)
{
	t_list *tmp;

	if (!lst || !*lst)
		return (NULL);
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = NULL;
	return (tmp);
}
