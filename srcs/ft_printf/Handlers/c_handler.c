/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 19:30:54 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/08 12:09:20 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*c_handler(t_format format, t_data arg)
{
	char	*charstr;
	size_t	len;

	if (format.width)
		format.width -= CHARACTER;
	len = CHARACTER + format.width;
	if (!(charstr = (char*)malloc(sizeof(char) * (len + SENTINAL))))
		exit(-1);
	if (!format.width || (format.width && format.flags & MINUS))
		charstr[0] = arg.char_;
	else
		charstr[format.width] = arg.char_;
	charstr[len] = '\0';
	if (format.width)
		(format.flags & MINUS) ?
			ft_memset(charstr + 1, format.pad, format.width) :
			ft_memset(charstr, format.pad, format.width);
	return (charstr);
}
