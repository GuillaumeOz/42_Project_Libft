/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_lstpush.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:52:18 by gozsertt          #+#    #+#             */
/*   Updated: 2019/11/18 14:46:01 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl	*ft_gnl_lstpush(t_gnl **head, void *content, size_t fd)
{
	t_gnl	*node;

	if (!(node = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	node->content = content;
	if (node)
	{
		node->next = *head;
		node->file_descriptor = fd;
		*head = node;
	}
	return (node);
}
