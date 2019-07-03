/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 08:03:47 by gozsertt          #+#    #+#             */
/*   Updated: 2019/04/25 12:52:34 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcmp_strstr(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (s2[i] == '\0')
		return (1);
	return (0);
}

char		*ft_strstr(const char *src, const char *word)
{
	int	result;

	result = 0;
	if (*word == '\0')
		return ((char*)src);
	while (*src)
	{
		if (*src == *word)
		{
			result = ft_strcmp_strstr(src, word);
			if (result)
				return ((char*)src);
		}
		src++;
	}
	return (NULL);
}
