/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 21:38:40 by abarnett          #+#    #+#             */
/*   Updated: 2018/12/10 17:22:32 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void			print_params(t_format fmt_struct)
{
	char	*convs;
	char	*flags;
	int		i;

	convs = "cCsSdDioOuUxXp%";
	flags = "#0-+ ";
	i = 0;
	ft_putchar('%');
	if (fmt_struct.flags)
	{
		while (i < 5)
		{
			if ((1 << i) & fmt_struct.flags)
				ft_putchar(flags[i]);
			++i;
		}
	}
	if (fmt_struct.width)
		ft_putnbr(fmt_struct.width);
	if (fmt_struct.precision != -1)
	{
		ft_putchar('.');
		ft_putnbr(fmt_struct.precision);
	}
	if (fmt_struct.length)
		ft_putchar(fmt_struct.length);
	ft_putchar(*(convs + fmt_struct.conv));
	ft_putstr(":	");
}

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

/*
**	The position of the characters in the flags string represent
**	the index of their function in the function pointer array.
**	If you would like to add a new function with a new character,
**		add your function to the srcs/ directory,
**			add a prototype to the header file too,
**		add the character to the end of the list (found in the header file),
**		increase the jump table index count (found in printf.c),
**		add your function name to the jump table.
*/
int					conversion_chars(const char **format)
{
	const char	*flags;
	char		*index;

	flags = CONVS;
	if (*format && (index = ft_strchr(flags, **format)))
	{
		(*format)++;
		return (index - flags);
	}
	return (-1);
}

/*
**	This function grabs the length of the conversion, if present, and stores it
**	in the fmt_struct, while also moving the format string to the next spot.
**
**	If the length "hh" or "ll" is used, it is replaced with "H" or "L".
*/
void				get_length(const char **format, t_format *fmt_struct)
{
	const char	*flags;
	char		*index;

	flags = "hHlLjz";
	if (*format && (index = ft_strchr(flags, **format)))
	{
		if (**format == 'h' && *(*format + 1) == 'h')
		{
			fmt_struct->length = 'H';
			++(*format);
		}
		else if (**format == 'l' && *(*format + 1) == 'l')
		{
			fmt_struct->length = 'L';
			++(*format);
		}
		else
			fmt_struct->length = *index;
		++(*format);
	}
}

/*
**	This function uses atoi to grab the number for width and precision.
**	it is important that we don't move by the length of the number for
**	precision, because a '.' that isn't followed by a number has a precision
**	of 0, and the numlen of 0 is 1, so it would move it unnecessarily.
**	instead we increase it while the character is a digit. this also prevents
**	negative numbers from getting through (by not moving past the minus sign,
**	even though atoi will do that anyway) in addition to the if statement below
**	that checks if atoi was able to pull one.
*/
void				get_width_precis(const char **format, t_format *fmt_struct)
{
	if (*format && ft_isdigit(**format))
	{
		fmt_struct->width = ft_atoi(*(char **)format);
		while (*format && ft_isdigit(**format))
			++(*format);
	}
	if (*format && **format == '.')
	{
		++(*format);
		fmt_struct->precision = ft_atoi(*(char **)format);
		while (*format && ft_isdigit(**format))
			++(*format);
		if (fmt_struct->precision < 0)
			fmt_struct->precision = 0;
	}
}

/*
**	The position of the characters in the flags string represent
**	the index of their bit in the ret variable.
**	To add new flags,
**		add the flag character to the end of the flags string
**			(make sure the type of ret is big enough to hold that many bits)
**			(add a macro for easier usage if you want)
**		flags will be dealt with in modules for each conversion
**	The third to last line disables the 0 flag if the - flag is also present.
**	The second to last line disables the ' ' flag if the + flag is also present.
*/
void				get_flags(const char **format, t_format *fmt_struct)
{
	const char		*flags;
	const char		*cur;
	unsigned char	ret;

	flags = "#0-+ ";
	ret = 0;
	while ((cur = ft_strchr(flags, **format)))
	{
		ret = ret | (1 << (cur - flags));
		(*format)++;
	}
	ret = ((ret & (ZERO | MINUS)) == (ZERO | MINUS) ? (ret ^ ZERO) : ret);
	ret = ((ret & (SPACE | PLUS)) == (SPACE | PLUS) ? (ret ^ SPACE) : ret);
	fmt_struct->flags = ret;
}
