/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprepend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:11:23 by gozsertt          #+#    #+#             */
/*   Updated: 2019/09/11 15:13:17 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strprepend(const char *s1, const char *s2, int free_s1, int free_s2)
{
	return (ft_strjoinfre(s2, s1, free_s2, free_s1));
}
