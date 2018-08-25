/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:47:21 by abarnett          #+#    #+#             */
/*   Updated: 2018/08/24 18:04:41 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
#include "libft.h"

typedef struct		s_format
{
	char			*conv;
	int				flags;
	int				width;
	int				precision;
}					t_format;

// function pointer functions
char				*flag_string(va_list valist);
char				*flag_int(va_list valist);
char				*flag_percent();

// parse functions
int					conversion_chars(char **format);
void				width_precision(char **format, t_format *fmt_struct);
void				flag_chars(char **format, t_format *fmt_struct);

// printf functions
//char				*format(char *str, int flags, int width);
//static char			*parse(char **format, va_list valist);
void				ft_printf(const char *format, ...);

#endif

/*
** Have each function for the flags know what it can't work with
** so it can determine if it can be ignored or not
** e.x. 0 flag doesn't work with s conversion
*/

/*
if (width > (int)ft_strlen(conv))
{
	fmt_str = ft_memset(ft_strnew(width),		\
				((flags & 0x2) ? '0' : ' '),	\
				width);
	if (flags & 0x4)
	{
		if (flags & 0x8 && ft_isdigit(*conv))
		{
			*fmt_str = '+';
			ft_memcpy(fmt_str + 1, conv, ft_strlen(conv));
		}
		else
			ft_memcpy(fmt_str, conv, ft_strlen(conv));
	}
	else
	{
		ft_memcpy(fmt_str + (width - ft_strlen(conv)), conv, ft_strlen(conv));
		if (flags & 0x8 && ft_isdigit(*conv))
			*(fmt_str + ((flags & 0x2) ? 0 : (width - ft_strlen(conv) - 1))) = '+';
	}
	ft_strdel(&conv);
	conv = fmt_str;
}
else if (flags & 0x8 && ft_isdigit(*conv))
{
	fmt_str = ft_strnew(ft_strlen(conv) + 1);
	*fmt_str = '+';
	ft_memcpy(fmt_str + 1, conv, ft_strlen(conv));
	ft_strdel(&conv);
	conv = fmt_str;
}
*/
