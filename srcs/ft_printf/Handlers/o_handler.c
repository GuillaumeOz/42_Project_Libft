/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:13:17 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/08 12:08:13 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*o_handler(t_format format, t_data arg)
{
	uintmax_t	temp;
	char		*intstr;

	if (format.length < L && format.length != NONE)
		temp = (format.length == HH) ? arg.uchar_ : arg.ushort_;
	else
		temp = (format.length == NONE) ? arg.uint_ : arg.uintmax_;
	intstr = ft_strdup("");
	if (!(format.precision == 0 && temp == 0 && !(format.flags & HASH)))
	{
		format.precision -= (format.flags & HASH && temp) ? 1 : 0;
		temp = (temp < 0) ? ~temp + 1 : temp;
		intstr = ft_strjoinfre(
			intstr, ft_utoa_base(temp, OCTAL_BASE, format.precision), 1, 1);
		format.width -= ft_strlen(intstr);
		format.width -= (format.flags & HASH && temp) ? 1 : 0;
	}
	if (format.width && format.pad == '0')
		intstr = apply_width(format, intstr);
	if (format.flags & HASH && temp)
		intstr = ft_strprepend(intstr, "0", 1, 0);
	if (format.width && format.pad != '0')
		intstr = apply_width(format, intstr);
	return (intstr);
}
