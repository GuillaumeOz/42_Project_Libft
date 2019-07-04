/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:25:01 by gozsertt          #+#    #+#             */
/*   Updated: 2019/07/04 15:15:57 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	if (s2)
	{
		i = ft_strlen(s1);
		j = 0;
		while (s2[j])
			s1[i++] = s2[j++];
		s1[i] = '\0';
	}
	return (s1);
}
