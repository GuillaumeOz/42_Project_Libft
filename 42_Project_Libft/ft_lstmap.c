/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:16:43 by gozsertt          #+#    #+#             */
/*   Updated: 2019/04/24 14:49:25 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *element;

	if (lst == NULL)
		return (NULL);
	element = f(lst);
	new = element;
	while (lst->next)
	{
		lst = lst->next;
		if (f(lst) == NULL)
			return (NULL);
		element->next = f(lst);
		element = element->next;
	}
	return (new);
}
