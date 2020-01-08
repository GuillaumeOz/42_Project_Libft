/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:35:37 by gozsertt          #+#    #+#             */
/*   Updated: 2019/11/18 16:20:23 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s2;

	i = 0;
	if (!(s))
		return (NULL);
	if (start > ft_strlen(s) || len == 0)
	{
		s2 = (char *)malloc((sizeof(char) * 1));
		s2[0] = '\0';
		return (s2);
	}
	if (!(s2 = (char *)malloc((sizeof(char) * (len + 1)))))
		return (NULL);
	while (s[start] && i < len)
	{
		s2[i] = s[start];
		i++;
		start++;
	}
	s2[i] = '\0';
	return (s2);
}
