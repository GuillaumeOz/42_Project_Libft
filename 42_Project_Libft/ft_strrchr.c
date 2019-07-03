/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 07:21:46 by gozsertt          #+#    #+#             */
/*   Updated: 2019/04/16 07:56:57 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	size_t i;

	i = 0;
	while (*src)
	{
		src++;
		i++;
	}
	while (i > 0 && *src != c)
	{
		src--;
		i--;
	}
	return (*src == c ? (char*)src : NULL);
}
