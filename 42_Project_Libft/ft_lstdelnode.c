/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:50:23 by gozsertt          #+#    #+#             */
/*   Updated: 2019/05/12 19:43:03 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_node(t_list *node)
{
	if (node)
	{
		if (node->content)
			free(node->content);
		node->content = NULL;
		node->content_size = 0;
		free(node);
		node = NULL;
	}
}

void		ft_lstdelnode(t_list **head, size_t position)
{
	t_list *node;
	t_list *previous;
	t_list *next;
	size_t i;

	if (head == NULL)
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
	if (node == NULL || node->next == NULL)
		return ;
	previous = node;
	next = node->next->next;
	previous->next = next;
	node = node->next;
	free_node(node);
}
