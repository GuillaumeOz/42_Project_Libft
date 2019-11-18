/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 11:03:47 by gozsertt          #+#    #+#             */
/*   Updated: 2019/04/22 20:09:17 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcmp_strnstr(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (s2[i] == '\0')
		return (1);
	return (0);
}

char		*ft_strnstr(const char *src, const char *word, size_t n)
{
	int		result;
	size_t	len_word;

	len_word = 0;
	if (*word == '\0')
		return ((char*)src);
	while (word[len_word] != '\0')
		len_word++;
	while (*src != '\0' && n-- >= len_word)
	{
		if (*src == *word)
		{
			result = ft_strcmp_strnstr(src, word);
			if (result)
				return ((char*)src);
		}
		src++;
	}
	return (NULL);
}
