/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:45:53 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/08 13:09:34 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*apply_width(t_format format, char *str)
{
	return (
		(format.flags & MINUS) ?
			ft_strappend(str, ft_padding(format.width, format.pad), 1, 1) :
			ft_strprepend(str, ft_padding(format.width, format.pad), 1, 1));
}

t_handler g_tbl_printf[] =
{
	{ '%', &mod_handler },
	{ 'c', &c_handler },
	{ 's', &s_handler },
	{ 'p', &p_handler },
	{ 'd', &d_handler },
	{ 'i', &i_handler },
	{ 'o', &o_handler },
	{ 'u', &u_handler },
	{ 'x', &x_handler },
	{ 'X', &xx_handler },
	{ '\0', NULL }
};

t_data		extract_argument(t_format format, va_list *args)
{
	t_data	arg;

	if (format.specifier == 'f' && format.length == LLL)
	{
		arg.long_double_ = va_arg(*args, long double);
	}
	else if (format.specifier == 'f' && format.length == LL)
	{
		arg.double_ = va_arg(*args, double);
	}
	else if (format.specifier == 'd' || format.specifier == 'i' ||
		format.specifier == 'c')
	{
		arg.intmax_ = va_arg(*args, intmax_t);
	}
	else
	{
		arg.uintmax_ = va_arg(*args, uintmax_t);
	}
	return (arg);
}

char		**parse_style(const char *format, int8_t *i)
{
	char		**styles;
	char		*closing_bracket;
	ptrdiff_t	bracket_length;

	styles = NULL;
	if (format[*i] == '{')
	{
		closing_bracket = ft_strchr(format, '}');
		bracket_length = closing_bracket - (format + (*i) + 1);
		if (closing_bracket)
		{
			format = ft_strndup(format + (*i) + 1, bracket_length);
			styles = ft_split(format, ' ');
		}
		(*i) += ft_strlen(format) + 2;
		free((void*)format);
	}
	return (styles);
}

t_format	parse_format(const char *format, va_list *args)
{
	int8_t		i;
	t_format	info;

	i = 0;
	info = (t_format) {
		.flags = parse_flags(format, &i),
		.width = parse_width(format, args, &i),
		.precision = parse_precision(format, args, &i),
		.length = parse_length(format, &i),
		.specifier = parse_specifier(format, &i),
		.style = parse_style(format, &i),
		.pad = ' ',
		.format_length = i
	};
	if (info.width < 0)
	{
		info.flags |= MINUS;
		info.width = -info.width;
	}
	if (info.flags & ZERO && !(info.flags & MINUS))
		if (info.precision == NONE || ft_ischarset(info.specifier, "cf%"))
			info.pad = '0';
	return (info);
}

char		*formatter(const char **format, va_list *args, size_t *len)
{
	t_format	info;
	t_data		arg;
	int32_t		i;
	char		*fstr;

	fstr = NULL;
	info = parse_format((*format) + 1, args);
	if (info.specifier == NONE)
		fstr = ft_strndup(*format, info.specifier + 1);
	else
	{
		if (info.specifier != '%')
			arg = extract_argument(info, args);
		i = -1;
		while (g_tbl_printf[++i].specifier != '\0')
			if (info.specifier == g_tbl_printf[i].specifier)
			{
				fstr = style_handler(info, g_tbl_printf[i].handler(info, arg));
				break ;
			}
	}
	(*format) += info.format_length + 1;
	(*len) = (info.specifier == 'c' && arg.char_ == 0) ?
		1 + info.width - (info.width > 0) : ft_strlen(fstr);
	return (fstr);
}
