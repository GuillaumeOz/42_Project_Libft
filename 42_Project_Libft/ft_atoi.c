/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:12:45 by gozsertt          #+#    #+#             */
/*   Updated: 2019/09/15 20:28:42 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_digit_atoi(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	is_escapable_ft_atoi(char c)
{
	if (c == '\t' || c == '\v' || c == '\f' || c == '\r'
		|| c == '\n' || c == ' ')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	long long		result;
	int				i;
	int				sign;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] && is_escapable_ft_atoi(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sign = str[i] == '-' ? -1 : 1;
		i++;
	}
	while (str[i] && is_digit_atoi(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((int)result * sign);
}
