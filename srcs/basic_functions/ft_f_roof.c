/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_roof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 09:03:19 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/15 18:47:12 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float		ft_f_roof(float p_value)
{
	float	rounded_value;
	int		i_value;

	if (p_value == 0)
		return (p_value);
	i_value = p_value;
	if (p_value < 0)
	{
		rounded_value = i_value;
		return (rounded_value);
	}
	rounded_value = p_value - i_value;
	if (rounded_value == 0)
	{
		rounded_value = p_value;
		return (rounded_value);
	}
	else
		rounded_value = i_value + 1;
	return (rounded_value);
}
