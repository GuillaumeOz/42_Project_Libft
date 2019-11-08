/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:54:42 by gozsertt          #+#    #+#             */
/*   Updated: 2019/09/08 12:48:12 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int nb)
{
	char	*output;
	size_t	nb_len;
	long	n;

	n = nb;
	nb_len = ft_intlen(n);
	output = (char *)malloc((nb_len + 1) * sizeof(char));
	if (output == NULL)
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
