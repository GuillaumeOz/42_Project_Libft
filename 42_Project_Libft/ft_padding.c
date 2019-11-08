/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:25:12 by gozsertt          #+#    #+#             */
/*   Updated: 2019/09/16 10:22:35 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_padding(int size, char c)
{
	char	*buf;
	int		i;

	buf = NULL;
	if (size > 0)
	{
		if (!(buf = (char*)malloc(sizeof(char) * (size + SENTINAL))))
			return (NULL);
		i = 0;
		while (i < size)
			buf[i++] = c;
		buf[i] = '\0';
	}
	return (buf);
}
