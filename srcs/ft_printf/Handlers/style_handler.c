/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 18:49:09 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/08 12:08:25 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_style	g_style_table[] =
{
	{ "default", "0" },
	\
	{ "bold", "1" },
	{ "faint", "2" },
	{ "italic", "3" },
	{ "underlined", "4" },
	{ "inverted", "7"},
	{ "hidden", "8"},
	\
	{ "black", "30" },
	{ "red", "31" },
	{ "green", "32" },
	{ "yellow", "33" },
	{ "blue", "34" },
	{ "magenta", "35" },
	{ "cyan", "36" },
	{ "gray", "37" },
	\
	{ "lgray", "90" },
	{ "lred", "91" },
	{ "lgreen", "92" },
	{ "lyellow", "93" },
	{ "lblue", "94" },
	{ "lmagenta", "95" },
	{ "lcyan", "96" },
	{ "lwhite", "97" },
	\
	{ "bgblack", "40" },
	{ "bgred", "41" },
	{ "bggreen", "42" },
	{ "bgyellow", "43" },
	{ "bgblue", "44" },
	{ "bgmagenta", "45" },
	{ "bgcyan", "46" },
	{ "bggray", "47" },
	\
	{ "bglgray", "100" },
	{ "bglred", "101" },
	{ "bglgreen", "102" },
	{ "bglyellow", "103" },
	{ "bglblue", "104" },
	{ "bglmagenta", "105" },
	{ "bglcyan", "106" },
	{ "bglwhite", "107" },
	\
	{ NULL, NULL}
};

char	*style_handler(t_format format, char *string)
{
	char	*style;
	int8_t	i;
	int8_t	j;

	if (format.style == NULL)
		return (string);
	style = ft_strdup("\033[");
	i = -1;
	while (format.style[++i])
	{
		j = -1;
		while (g_style_table[++j].style)
			if (ft_strcmp(format.style[i], g_style_table[j].style) == 0)
			{
				style = ft_strappend(style, g_style_table[j].ansi_code, 1, 0);
				if (format.style[i + 1] != NULL)
					style = ft_strappend(style, ";", 1, 0);
				free(format.style[i]);
				break ;
			}
	}
	free(format.style);
	style = ft_strappend(style, "m", 1, 0);
	string = ft_strprepend(string, style, 1, 1);
	return (ft_strappend(string, "\033[0m", 1, 0));
}
