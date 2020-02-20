/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:18:01 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/20 13:59:37 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_strisdigit(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((ft_isdigit(str[i] + '0') == 0))
			return (false);
		i++;
	}
	return (true);
}
