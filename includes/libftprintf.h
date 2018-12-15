/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:47:21 by abarnett          #+#    #+#             */
/*   Updated: 2018/12/14 02:27:00 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft.h"

# define SHARP 0x1
# define ZERO 0x2
# define MINUS 0x4
# define PLUS 0x8
# define SPACE 0x10

# define CONVS "cCsS%dDiuUboOxXp"

typedef struct		s_format
{
	unsigned char	flags;
	int				width;
	int				precision;
	char			length;
	char			conv;
}					t_format;

// function pointer functions
char				*flag_char(t_format *fmt, va_list valist);
char				*flag_string(t_format *fmt, va_list valist);
char				*flag_percent(t_format *fmt);
char				*flag_int(t_format *fmt, va_list valist);
char				*flag_uint(t_format *fmt, va_list valist);
char				*flag_bin(t_format *fmt, va_list valist);
char				*flag_oct(t_format *fmt, va_list valist);
char				*flag_hex(t_format *fmt, va_list valist);
char				*flag_pointer(t_format *fmt, va_list valist);

// parse functions
void				print_params(t_format fmt_struct);
int					get_conversion(const char **format, t_format *fmt_struct);
void				get_length(const char **format, t_format *fmt_struct);
void				get_width_precis(const char **format, t_format *fmt_struct);
void				get_flags(const char **format, t_format *fmt_struct);

// printf functions
int					ft_printf(const char *format, ...);

#endif
