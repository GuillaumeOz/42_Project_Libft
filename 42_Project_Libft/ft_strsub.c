/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:35:37 by gozsertt          #+#    #+#             */
/*   Updated: 2019/05/12 20:38:39 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	if (str == NULL)
		return (NULL);
	if (len + start > ft_strlen(str))
		return (NULL);
	new_str = (char*)malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = start;
	while (i - start != len)
	{
		new_str[i - start] = str[i];
		i++;
	}
	new_str[len] = '\0';
	return (new_str);
}
