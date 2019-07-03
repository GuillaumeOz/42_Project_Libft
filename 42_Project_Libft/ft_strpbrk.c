/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:01:48 by gozsertt          #+#    #+#             */
/*   Updated: 2019/04/23 15:17:33 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *s, const char *accept)
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	str = (char*)s;
	len = ft_strlen(s);
	while (*str)
	{
		while (i < len)
		{
			if (accept[i] == *str)
				return (str);
			i++;
		}
		str++;
		i = 0;
	}
	return (NULL);
}
