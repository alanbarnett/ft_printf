/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:26:02 by abarnett          #+#    #+#             */
/*   Updated: 2018/08/16 17:46:47 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"
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

/*
**	The position of the characters in the flags string represent
**	the index of their function in the function pointer array.
**	If you would like to add a new function with a new character,
**		add your function to the srcs/ directory,
**		add the character to the end of the list,
**		increase the jump table index count,
**		add your function name to the jump table.
*/

/*
**		di				ouUxX					c		s			p
**
**		int				unsigned int			int		char*		void*
**	hh	char			unsigned char
**	h	short int		unsigned short int
**	l	long int		unsigned long int		wint_t	wint_t*
**	ll	long long int	unsigned long long int
**	j	intmax_t		uintmax_t
**	z	size_t			size_t
*/
int					conversion_chars(char **format)
{
	const char	*flags;
	char		*index;

	flags = "sSpdDioOuUxXcC%";
	if ((index = ft_strchr(flags, **format)))
	{
		(*format)++;
		return (index - flags);
	}
	return (-1);
}

int					field_width(char **format)
{
	int		width;

	width = -1;
	if (ft_isdigit(**format))
	{
		width = ft_atoi(*format);
		*format += ft_numlen(width);
	}
	return (width);
}

/*
**	The position of the characters in the flags string represent
**	the index of their bit in the ret variable.
**	To add new flags,
**		add the flag character to the end of the flags string
**			(make sure the type of ret is big enough to hold that many bits)
**		make some shit to deal with that bit in the parse function
**	The third to last line disables the 0 flag if the - flag is also present.
**	The second to last line disables the ' ' flag if the + flag is also present.
*/
int					flag_chars(char **format)
{
	const char	*flags;
	int			ret;

	flags = "#0-+ ";
	ret = 0;
	while (ft_strchr(flags, **format))
	{
		ret = ret | (1 << (ft_strchr(flags, **format) - flags));
		(*format)++;
	}
	ret = ((ret & 0x6) == 0x6 ? (ret ^ 0x2) : ret);
	ret = ((ret & 0x18) == 0x18 ? (ret ^ 0x10) : ret);
	return (ret);
}
/*
char				*format(char *str, int flags, int width)
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
*/
/*
**	Parse takes a pointer to the format string at the format specifier so that 
**	when it moves the pointer to the end of the format specifier, that change
**	can be reflected in the calling function.
*/
static char			*parse(char **format, va_list valist)
{
	char		*conv;
	int			flags;
	int			width;
	static char	*(*p[15])();

	p[0] = flag_string;
	p[3] = flag_int;
	p[5] = flag_int;
	p[14] = flag_percent;

	flags = flag_chars(format);
	width = field_width(format);
	//still need to get the fucking precision
	conv = p[conversion_chars(format)](valist);
	//conv = format(conv, flags, width);
	return (conv);
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
