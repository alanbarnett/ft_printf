/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 21:38:40 by abarnett          #+#    #+#             */
/*   Updated: 2018/11/28 22:45:51 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
**		add the character to the end of the list,
**		increase the jump table index count,
**		add your function name to the jump table.
*/
int					conversion_chars(const char **format)
{
	const char	*flags;
	char		*index;

	flags = "cCsSdDioOuUxXp%";
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
**	instead we increase it while the character is a digit.
**
**	temporarily trying out doing it without numlen, as it seems that might
**	be unneccessary. i think it really comes down to taste, as numlen doesn't
**	really do that many more operations, but this might be a bit cleaner.
**	plus now I do more checks if it's a valid character. don't want any sneaky
**	segfaults now, do we? (i wonder how many operations that part adds. I'll
**	go crazy if I try to consider everything.)
*/
void				get_width_precis(const char **format, t_format *fmt_struct)
{
	if (*format && ft_isdigit(**format))
	{
		fmt_struct->width = ft_atoi(*(char **)format);
		//format += ft_numlen(fmt_struct->width);
		while (*format && ft_isdigit(**format))
			++(*format);
	}
	if (*format && **format == '.')
	{
		++(*format);
		fmt_struct->precision = ft_atoi(*(char **)format);
		while (*format && ft_isdigit(**format))
			++(*format);
	}
}

/*
**	The position of the characters in the flags string represent
**	the index of their bit in the ret variable.
**	To add new flags,
**		add the flag character to the end of the flags string
**			(make sure the type of ret is big enough to hold that many bits)
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
	ret = ((ret & 0x6) == 0x6 ? (ret ^ 0x2) : ret);
	ret = ((ret & 0x18) == 0x18 ? (ret ^ 0x10) : ret);
	fmt_struct->flags = ret;
}
