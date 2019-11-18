/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:54:42 by gozsertt          #+#    #+#             */
/*   Updated: 2019/11/18 19:15:28 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*output;
	size_t	nb_len;

	if (n == -2147483648)
	{
		output = ft_strdup("-2147483648\0");
		return (output);
	}
	nb_len = (int)ft_intlen(n);
	if (n < 0)
		nb_len++;
	if (!(output = (char *)malloc(sizeof(char) * (nb_len + SENTINAL))))
		return (NULL);
	output[0] = n < 0 ? '-' : '0';
	n = n < 0 ? -n : n;
	output[nb_len] = '\0';
	while (n != 0)
	{
		output[--nb_len] = (n % 10) + '0';
		n /= 10;
	}
	return (output);
}
