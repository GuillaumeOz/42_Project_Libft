/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndupfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:51:27 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/21 19:05:06 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndupfree(const char *src, size_t n, int free_src)
{
	char	*res;

	res = ft_strndup(src, n);
	if (free_src && src)
		free((void *)src);
	return (res);
}
