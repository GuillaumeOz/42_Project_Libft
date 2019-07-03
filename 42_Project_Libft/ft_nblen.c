/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 19:58:11 by gozsertt          #+#    #+#             */
/*   Updated: 2019/04/22 20:06:44 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nblen(long nb)
{
	size_t	nblen;

	nblen = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		nblen++;
	}
	while (nb != 0)
	{
		nb /= 10;
		nblen++;
	}
	return (nblen);
}
