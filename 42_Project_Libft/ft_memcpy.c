/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:58:52 by gozsertt          #+#    #+#             */
/*   Updated: 2019/05/16 02:10:59 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d_dest;
	unsigned char	*s_src;

	if ((dest == src) || (n == 0))
		return (dest);
	d_dest = (unsigned char*)dest;
	s_src = (unsigned char*)src;
	while (n--)
		*(d_dest + n) = *(s_src + n);
	return (dest);
}
