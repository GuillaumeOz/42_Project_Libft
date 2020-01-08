/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 18:41:26 by gozsertt          #+#    #+#             */
/*   Updated: 2019/08/28 19:28:31 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strnlen(const char *s, size_t maxlen)
{
	size_t i;

	i = 0;
	while (i < maxlen && s[i])
		++i;
	return (i);
}
