/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:26:02 by abarnett          #+#    #+#             */
/*   Updated: 2018/08/24 21:12:33 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

/*
** Must include:
** 	conversions:	sSpdDioOuUxXcC
**	must manage:	%%
**	flags:			#0-+ (and ' ');
**	must manage:	minimum field-width and precision
**	flags:			hh, h, l, ll, j, z
**
** Bonuses include:
**	conversions:	eE, fF, gG, aA, n
**	flags:			*, %, L, '
**	new flags:
**		%b:		binary
**		%r:		non-printable characters
**		%k:		date in ISO format
**	colors, fd, etc..
*/

t_format			*new_fmt_struct()
{
	t_format	*fmt;

	fmt = (t_format *)ft_memalloc(sizeof(t_format));
	fmt->conv = 0;
	fmt->flags = 0;
	fmt->width = 0;
	fmt->precision = 0;
	return (fmt);
}

char				*flag_string(va_list valist)
{
	return (va_arg(valist, char *));
}

char				*flag_int(va_list valist)
{
	return (ft_itoa(va_arg(valist, int)));
}

char				*flag_percent()
{
	return (ft_strdup("%"));
}

void				*format(t_format fmt_struct)
{
	char	*formatted;

	if (flags & 0x4)
	{
		if (width > (int)ft_strlen(str))
		{
			formatted = ft_memalloc(width);
			
		}
	}
}

/*
**	Parse takes a pointer to the format string at the format specifier so that 
**	when it moves the pointer to the end of the format specifier, that change
**	can be reflected in the calling function.
*/
static char			*parse(char **format, va_list valist)
{
	t_format	*fmt_struct;
	static char	*(*p[15])();

	fmt_struct = new_fmt_struct();
	p[0] = flag_string;
	p[3] = flag_int;
	p[5] = flag_int;
	p[14] = flag_percent;

	flag_chars(format, fmt_struct);
	width_precision(format, fmt_struct);
	fmt_struct->conv = p[conversion_chars(format)](valist);
	format(fmt_struct);
	return (fmt_struct->conv);
}

void				ft_printf(const char *format, ...)
{
	va_list		valist;
	char		*p_str;

	va_start(valist, format);
	while ((p_str = ft_strchr(format, '%')))
	{
		format += write(1, format, p_str - format) + 1;
		p_str = parse((char **)&format, valist);
		ft_putstr(p_str);
		ft_strdel(&p_str);
	}
	write(1, format, ft_strlen(format));
}
