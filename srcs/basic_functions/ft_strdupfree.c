/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:55:38 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/10 14:55:45 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdupfree(char *src, int free_src)
{
	char	*ret;

	ret = ft_strdup(src);
	if (free_src && src)
		free((void *)src);
	return (ret);
}
