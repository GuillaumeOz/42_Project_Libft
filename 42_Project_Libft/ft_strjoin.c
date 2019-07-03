/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 21:03:49 by gozsertt          #+#    #+#             */
/*   Updated: 2019/05/09 12:23:35 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*str;

	str = NULL;
	i = -1;
	j = -1;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (s1[++i])
			str[i] = s1[i];
		while (s2[++j])
			str[i + j] = s2[j];
		str[len] = '\0';
		return (str);
	}
	return (NULL);
}
