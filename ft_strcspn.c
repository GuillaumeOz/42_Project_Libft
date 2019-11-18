/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:35:47 by gozsertt          #+#    #+#             */
/*   Updated: 2019/04/30 15:02:00 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t nb;
	size_t i;
	size_t j;

	i = -1;
	j = -1;
	nb = 0;
	while (s[++i])
	{
		while (reject[++j])
		{
			if (reject[j] == s[i])
				return (nb);
		}
		j = -1;
		nb++;
	}
	return (nb);
}
