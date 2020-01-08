/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:23:44 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/08 12:08:20 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*s_handler(t_format format, t_data arg)
{
	char	*fstr;

	fstr = (arg.str_ == NULL) ?
		ft_strdup("(null)") :
		ft_strdup(arg.str_);
	if (format.precision != NONE)
		if (0 <= format.precision && format.precision < (long)ft_strlen(fstr))
			fstr[format.precision] = '\0';
	format.width -= ft_strlen(fstr);
	if (format.width > 0 && format.pad == ' ')
		fstr = apply_width(format, fstr);
	return (fstr);
}
