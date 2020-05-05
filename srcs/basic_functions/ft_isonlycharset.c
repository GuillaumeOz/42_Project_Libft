/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isonlycharset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:30:55 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/03 16:03:58 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isonlycharset(const char *format, const char *charset)
{
	int i;
	int ascii[256];
	int set_zero;

	i = -1;
	set_zero = 0;
	if (!format || (ft_ischar(charset, format[0]) == FAILURE))
		return (FAILURE);
	while (set_zero < 256)
		ascii[set_zero++] = 0;
	while (charset[++i])
		if (ascii[(int)charset[i]] == 0)
			ascii[(int)charset[i]] = 1;
	i = 0;
	while (format[i])
	{
		if (ascii[(int)format[i]] != 1)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
