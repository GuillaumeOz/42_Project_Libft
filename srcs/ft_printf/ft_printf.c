/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 11:31:00 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/08 12:08:47 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		done;

	va_start(args, format);
	done = ft_vdprintf(STDOUT, format, &args);
	va_end(args);
	return (done);
}
