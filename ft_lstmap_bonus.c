/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:16:43 by gozsertt          #+#    #+#             */
/*   Updated: 2019/11/18 12:57:30 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *head;
	t_list *node;

	if (!lst || !f || !del)
		return (NULL);
	if (!(node = ft_lstnew(f(lst->content))))
		return (NULL);
	head = node;
	while (lst->next)
	{
		lst = lst->next;
		if (!(node->next = ft_lstnew(f(lst->content))))
			ft_lstclear(&head, del);
		node = node->next;
	}
	return (head);
}
