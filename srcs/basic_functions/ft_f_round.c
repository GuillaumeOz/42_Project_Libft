/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_round.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 09:03:19 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/15 18:53:07 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_f_round(float p_value)
{
	float	floor;
	float	roof;

	floor = ft_f_floor(p_value);
	roof = ft_f_roof(p_value);
	if ((p_value - floor) < (roof - p_value))
		return (floor);
	else
		return (roof);
}
