/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 19:58:11 by gozsertt          #+#    #+#             */
/*   Updated: 2019/11/18 19:17:22 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(intmax_t n)
{
	intmax_t	num;
	size_t		length;

	length = 1;
	num = (n < 0) ? -n : n;
	while (num >= 10)
	{
		num /= 10;
		length++;
	}
	return (length);
}
