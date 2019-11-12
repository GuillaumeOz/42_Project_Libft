/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:54:42 by gozsertt          #+#    #+#             */
/*   Updated: 2019/11/12 11:49:35 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*output;
	size_t	nb_len;
	long	num;

	num = n;
	nb_len = ft_intlen(num);
	output = (char *)malloc(sizeof(char) * (nb_len + SENTINAL));
	if (output == NULL)
		return (NULL);
	output[0] = num < 0 ? '-' : '0';
	num = num < 0 ? -num : num;
	output[nb_len] = '\0';
	while (num != 0)
	{
		output[--nb_len] = (num % 10) + '0';
		num /= 10;
	}
	return (output);
}
