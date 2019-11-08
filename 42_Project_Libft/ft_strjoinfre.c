/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfre.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 23:57:11 by gozsertt          #+#    #+#             */
/*   Updated: 2019/09/11 11:41:53 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfre(const char *s1, const char *s2, int free_s1, int free_s2)
{
	char *new_str;

	new_str = ft_strjoin(s1, s2);
	if (s1 && free_s1)
		free((void *)s1);
	if (s2 && free_s2)
		free((void *)s2);
	return (new_str);
}
