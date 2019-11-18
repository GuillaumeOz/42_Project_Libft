/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_lstdel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:50:23 by gozsertt          #+#    #+#             */
/*   Updated: 2019/11/18 14:47:22 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_node(t_gnl *node)
{
	if (node)
	{
		if (node->content)
			free(node->content);
		node->content = NULL;
		node->file_descriptor = 0;
		free(node);
		node = NULL;
	}
}

void		ft_gnl_lstdel(t_gnl **head, size_t position)
{
	t_gnl	*node;
	t_gnl	*previous;
	t_gnl	*next;
	size_t	i;

	if (!head)
		return ;
	node = *head;
	if (position == 0)
	{
		*head = node->next;
		free_node(node);
		return ;
	}
	i = 0;
	while (node && ++i != position)
		node = node->next;
	if (!node || !node->next)
		return ;
	previous = node;
	next = node->next->next;
	previous->next = next;
	node = node->next;
	free_node(node);
}
