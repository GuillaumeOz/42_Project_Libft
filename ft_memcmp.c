/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:39:23 by gozsertt          #+#    #+#             */
/*   Updated: 2019/04/11 13:58:18 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *s_s1;
	const unsigned char *s_s2;
	size_t				i;

	s_s1 = (const unsigned char*)s1;
	s_s2 = (const unsigned char*)s2;
	i = 0;
	while (n--)
	{
		if (s_s1[i] != s_s2[i])
			return (s_s1[i] - s_s2[i]);
		if (n)
			i++;
	}
	return (0);
}
