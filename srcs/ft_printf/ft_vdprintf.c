/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 12:55:28 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/08 12:08:51 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_vdprintf(int filedes, const char *format, va_list *args)
{
	int32_t	tt_bytes;
	size_t	len;
	char	*fstr;

	if (!format)
		return (0);
	tt_bytes = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (!(fstr = formatter(&format, args, &len)))
				return (-1);
			tt_bytes += write(filedes, fstr, len);
			free(fstr);
		}
		else
		{
			tt_bytes += write(filedes, format, 1);
			format++;
		}
	}
	return (tt_bytes);
}
