/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seglen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 20:12:39 by gozsertt          #+#    #+#             */
/*   Updated: 2019/04/24 14:00:22 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_seglen(const char *s, size_t start, int c)
{
	size_t	len;

	len = 0;
	while (s[len + start] != c && s[len + start] != '\0')
		len++;
	return (len);
}
