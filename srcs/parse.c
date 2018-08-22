/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 21:38:40 by abarnett          #+#    #+#             */
/*   Updated: 2018/08/21 22:40:26 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

int					width_precision(char **format)
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
