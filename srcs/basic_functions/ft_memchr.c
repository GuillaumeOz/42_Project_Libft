/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 07:51:58 by gozsertt          #+#    #+#             */
/*   Updated: 2019/04/11 17:21:22 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *s_s;
	size_t				i;

	s_s = (const unsigned char*)s;
	i = 0;
	while (n--)
	{
		if (s_s[i] == (const unsigned char)c)
			return ((void*)s_s + i);
		if (n)
			i++;
	}
	return (NULL);
}
