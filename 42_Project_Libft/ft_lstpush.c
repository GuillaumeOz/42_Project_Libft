/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:52:18 by gozsertt          #+#    #+#             */
/*   Updated: 2019/05/12 16:43:05 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpush(t_list **head, void const *content, size_t content_size)
{
	t_list	*node;

	node = ft_lstnew(content, content_size);
	if (node)
	{
		node->next = *head;
		*head = node;
	}
	return (node);
}
