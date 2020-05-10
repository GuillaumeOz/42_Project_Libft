/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:24:30 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/07 14:08:35 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;

	ptr = NULL;
	if (size)
	{
		if (!(ptr = (unsigned char*)malloc(sizeof(char) * size)))
			ft_error("The malloc from ft_memalloc failed");
		ft_memset(ptr, 0, size);
	}
	return ((void*)ptr);
}
