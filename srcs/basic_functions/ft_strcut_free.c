/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:35:59 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/25 13:30:55 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut_free(char **s1, char delim, int to_free)
{
	char	*result;
	char	*tmp;
	size_t	len;
	size_t	string_size;

	len = 0;
	string_size = 0;
	tmp = *s1;
	while (tmp[len] != '\0' && tmp[len] == delim)
		len++;
	while (tmp[len + string_size] != '\0' && tmp[len + string_size] != delim)
		string_size++;
	result = ft_strndup(tmp + len, string_size);
	if (to_free == 1)
		free(*s1);
	return (result);
}
