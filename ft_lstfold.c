/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 20:57:15 by gozsertt          #+#    #+#             */
/*   Updated: 2019/11/18 13:39:19 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstfold(t_list *lst)
{
	t_list	*result;

	if (!(result = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (lst != NULL)
	{
		result->content = lst->content;
		lst = lst->next;
		while (lst != NULL)
		{
			result->content = ft_strjoin(result->content, lst->content);
			lst = lst->next;
		}
		return (result);
	}
	return (result);
}
