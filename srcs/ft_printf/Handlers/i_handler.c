/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:28:14 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/08 12:07:57 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*i_handler(t_format format, t_data arg)
{
	intmax_t	temp;
	bool		sign;
	char		*intstr;

	temp = (format.length < L) ? arg.int_ : arg.intmax_;
	sign = (temp < 0);
	intstr = ft_strdup("");
	if (!(format.precision == 0 && temp == 0))
	{
		temp = temp < 0 ? -temp : temp;
		intstr = ft_strappend(
			intstr, ft_utoa_base(temp, DECIMAL_BASE, format.precision), 1, 1);
	}
	format.width -= ft_strlen(intstr) +
		(sign || (format.flags & PLUS || format.flags & SPACE) ? 1 : 0);
	if (format.width && format.pad == '0')
		intstr = apply_width(format, intstr);
	intstr = (sign) ? ft_strprepend(intstr, "-", 1, 0) : intstr;
	if (format.flags & PLUS && !sign)
		intstr = ft_strprepend(intstr, "+", 1, 0);
	if (format.flags & SPACE && !(format.flags & PLUS) && !sign)
		intstr = ft_strprepend(intstr, " ", 1, 0);
	if (format.width && format.pad != '0')
		intstr = apply_width(format, intstr);
	return (intstr);
}
