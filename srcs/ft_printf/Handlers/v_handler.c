/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 10:05:04 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/24 23:18:06 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*v_handler(t_format format, t_data arg)
{
	t_ft_printf_vector2	value;
	char				*vecstr;
	char				*tmp;

	value.x = (format.length == L) ? arg.long_double_ : arg.float_;
	value.y = (format.length == L) ? arg.long_double_ : arg.float_;
	vecstr = ft_strdup("(");
	tmp = ft_itoa((int)value.x);
	vecstr = ft_strappend(vecstr, tmp, 1, 1);
	vecstr = ft_strappend(vecstr, " / ", 1, 0);
	tmp = ft_itoa((int)value.y);
	vecstr = ft_strappend(vecstr, tmp, 1, 1);
	vecstr = ft_strappend(vecstr, ")", 1, 0);
	return	(vecstr);
}
