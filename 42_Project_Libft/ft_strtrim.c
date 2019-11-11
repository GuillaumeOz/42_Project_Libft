/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:12:56 by gozsertt          #+#    #+#             */
/*   Updated: 2019/11/11 16:53:44 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_charset(char const *s1, char const *set)
{
	int	count;
	int	i;
	int j;

	count = 0;
	i = -1;
	j = -1;
	while (set[++i])
	{
		while (s1[++j])
			if (set[i] == s1[j])
				count++;
		j = -1;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		len;

	if (!s1 || !set)
		return (NULL);
	len = (ft_strlen(s1) - ft_count_charset(s1, set));
	if (!(ret = (char*)malloc(sizeof(char) * (len + SENTINAL))))
		return (NULL);
	ret[len] = '\0';
	while (*s1)
	{
		if (!ft_ischarset(*s1, set))
		{
			*ret = *s1;
			ret++;
		}
		s1++;
	}
	return (ret - len);
}
