/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_no_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:22:38 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/20 15:14:10 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_no_c(const char *s, char c)
{
	char	*str;
	int		i;
	int		j;
	size_t	size;

	size = ft_strlen_without(s, c);
	i = 0;
	j = 0;
	if (!(str = (char*)ft_memalloc(sizeof(char) * (size + SENTINAL))))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	return (str);
}
