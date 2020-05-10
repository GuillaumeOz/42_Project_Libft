/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_leaks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 14:28:48 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/07 15:21:08 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_get_leaks(char *prog_name, char *msg)
{
	char	*command;
	char	*tmp;

	tmp = ft_strdup("leaks ");
	command = ft_strjoin(tmp, prog_name);
	free(tmp);
	tmp = command;
	command = ft_strjoin(tmp, " | grep 'total leaked bytes'");
	free(tmp);
	system(command);
	ft_putstr(msg);
	ft_putchar('\n');
	ft_putchar('\n');
	free(command);
}
