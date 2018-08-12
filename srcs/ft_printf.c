/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:26:02 by abarnett          #+#    #+#             */
/*   Updated: 2018/08/12 15:55:05 by abarnett         ###   ########.fr       */
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

	flags = "sSpdDioOuUxXcC";
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
**	The second to last line turns off the 0 flag if the - flag is also present.
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
	return (ret);
}

/*
**	Maybe make a jump table for flags
**	send it the width so it can make the output string
**	send it the conversion so it can format it
**	maybe make the flags a final stage for formatting?
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
	static char	*(*p[14])();

	p[0] = flag_string;
	p[3] = flag_int;
	p[5] = flag_int;

	flags = flag_chars(format);
	width = field_width(format);
	conv = p[conversion_chars(format)](valist);
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
