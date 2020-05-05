/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned_deci.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 09:03:19 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 12:39:52 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_itoa_unsigned_nbrlen(unsigned long long int nbr,
	size_t base_len)
{
	size_t					nbr_len;

	nbr_len = 1;
	while (nbr >= base_len)
	{
		nbr /= base_len;
		nbr_len++;
	}
	return (nbr_len);
}

char			*ft_itoa_unsigned_deci(unsigned int nbr)
{
	char					*base;
	size_t					base_len;
	size_t					nbr_len;
	char					*result;

	base = "0123456789";
	base_len = ft_strlen(base);
	nbr_len = ft_itoa_unsigned_nbrlen(nbr, base_len);
	result = ft_strnew(nbr_len);
	result[nbr_len] = '\0';
	nbr_len--;
	while (nbr >= base_len)
	{
		result[nbr_len] = base[nbr % base_len];
		nbr /= base_len;
		nbr_len--;
	}
	result[nbr_len] = base[nbr % base_len];
	return (result);
}
