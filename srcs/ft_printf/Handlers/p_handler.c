/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:30:04 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/08 12:08:17 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*p_handler(t_format format, t_data arg)
{
	char	*addr;

	addr = ft_strdup("");
	if (!(format.precision == 0 && arg.intptr_ == 0))
	{
		addr = ft_strappend(addr,
			ft_utoa_base(arg.intptr_, HEX_LOWER_BASE, format.precision), 1, 1);
	}
	if (format.width && format.pad == '0')
		addr = apply_width(format, addr);
	addr = ft_strprepend(addr, "0x", 1, 0);
	format.width -= ft_strlen(addr);
	if (format.width > 0 && format.pad == ' ')
		addr = apply_width(format, addr);
	return (addr);
}
