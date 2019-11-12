/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:52:18 by gozsertt          #+#    #+#             */
/*   Updated: 2019/11/12 11:45:56 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpush(t_list **head, void *content, size_t content_size)
{
	t_list	*node;

	node = ft_lstnew(content);
	if (node)
	{
		node->next = *head;
		node->content_size = content_size;
		*head = node;
	}
	return (node);
}
