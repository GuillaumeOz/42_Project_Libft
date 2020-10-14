/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 12:49:14 by gozsertt          #+#    #+#             */
/*   Updated: 2020/10/14 18:26:56 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef	struct	s_ft_printf_vector2
{
	float	x;
	float	y;
}				t_ft_printf_vector2;

typedef union	u_data
{
	char				*str_;
	bool				bool_;
	signed char			char_;
	signed short		short_;
	signed int			int_;
	signed long			long_;
	signed long long	long_long_;
	unsigned char		uchar_;
	unsigned short		ushort_;
	unsigned int		uint_;
	unsigned long		ulong_;
	unsigned long long	ulong_long_;
	float				float_;
	double				double_;
	intmax_t			intmax_;
	uintmax_t			uintmax_;
	intptr_t			intptr_;
	uintptr_t			uintptr_;
	ptrdiff_t			ptrdiff_;
	size_t				size_;
	t_ft_printf_vector2	vector2_;
}				t_data;

typedef struct	s_format_info
{
	int8_t				flags;
	int32_t				width;
	int32_t				precision;
	int8_t				length;
	int8_t				specifier;
	char				**style;
	char				pad;
	int8_t				format_length;
}				t_format;

typedef struct	s_handler
{
	char				specifier;
	char				*(*handler)(t_format format, t_data arg);
}				t_handler;

typedef struct	s_style
{
	char				*style;
	char				*ansi_code;
}				t_style;

enum			e_flags
{
	MINUS = (1 << 0),
	PLUS = (1 << 1),
	SPACE = (1 << 2),
	HASH = (1 << 3),
	ZERO = (1 << 4)
};

enum			e_lengths
{
	HH = sizeof(char),
	H = sizeof(short),
	L = sizeof(int),
	LL = sizeof(long long int),
	LLL = sizeof(long double),
	IU_MAX = sizeof(intmax_t),
	SIZET = sizeof(size_t),
	PTRDIFF = sizeof(ptrdiff_t)
};

int				ft_printf(const char *format, ...);

int				ft_vdprintf(int filedes, const char *format, va_list *args);

char			*apply_width(t_format format, char *str);
char			**parse_style(const char *format, int8_t *i);
t_data			extract_argument(t_format format, va_list *args);
t_format		parse_format(const char *format, va_list *args);
char			*formatter(const char **format, va_list *args, size_t *len);

int8_t			parse_flags(const char *format, int8_t *i);
int32_t			parse_width(const char *format, va_list *args, int8_t *i);
int32_t			parse_precision(const char *format, va_list *args, int8_t *i);
int8_t			parse_length(const char *format, int8_t *i);
int8_t			parse_specifier(const char *format, int8_t *i);

# define SPECIFIERS "cspiuodxXv%"

char			*style_handler(t_format format, char *fstr);
char			*mod_handler(t_format format, t_data arg);
char			*c_handler(t_format format, t_data arg);
char			*s_handler(t_format format, t_data arg);
char			*p_handler(t_format format, t_data arg);
char			*d_handler(t_format format, t_data arg);
char			*i_handler(t_format format, t_data arg);
char			*o_handler(t_format format, t_data arg);
char			*u_handler(t_format format, t_data arg);
char			*x_handler(t_format format, t_data arg);
char			*xx_handler(t_format format, t_data arg);
char			*v_handler(t_format format, t_data arg);

#endif
