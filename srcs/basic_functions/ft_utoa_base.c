/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:38:58 by gozsertt          #+#    #+#             */
/*   Updated: 2019/09/16 16:50:55 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa_base(uintmax_t n, char *base, int precision)
{
	unsigned short	intbase;
	unsigned short	col;
	char			*buf;

	if (!ft_valid_base(base))
		return (NULL);
	col = ft_uintmaxlen_base(n, ft_strlen(base));
	precision = (precision - col > 0) ? precision - col : 0;
	col += precision;
	if (!(buf = (char*)malloc(sizeof(char) * (col + 1))))
		return (NULL);
	buf = ft_memset(buf, '0', col);
	buf[col] = '\0';
	intbase = ft_strlen(base);
	while (col - precision > 0)
	{
		buf[--col] = base[n % intbase];
		n /= intbase;
	}
	return (buf);
}
