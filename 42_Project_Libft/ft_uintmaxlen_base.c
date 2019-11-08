/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmaxlen_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:47:44 by gozsertt          #+#    #+#             */
/*   Updated: 2019/09/16 14:08:37 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_uintmaxlen_base(uintmax_t n, unsigned int base)
{
	size_t	length;

	length = 1;
	while (n >= base)
	{
		n /= base;
		length++;
	}
	return (length);
}
