/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:26:02 by abarnett          #+#    #+#             */
/*   Updated: 2019/02/06 17:03:07 by abarnett         ###   ########.fr       */
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
**	.___________________________________.
**	|conversion	|	length		|flags	|
**	|-----------+---------------+-------|
**	|	c		|				|		|
**	|	s		|				|		|
**	|	p		|				|		|
**	|-----------+---------------+-------|
**	|	d		| h, hh, l, ll	| 0-+s	|
**	|	i		| h, hh, l, ll	| 0-+s	|
**	|	o		| h, hh, l, ll	| 0-+s	|
**	|	u		| h, hh, l, ll	| 0-+s	|
**	|	x		| h, hh, l, ll	| 0-+s	|
**	|	X		| h, hh, l, ll	| 0-+s	|
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

static void		init(t_format *fmt)
{
	fmt->flags = 0;
	fmt->width = 0;
	fmt->precision = -1;
	fmt->length = 0;
	fmt->conv = 0;
}

/*
** Static function to house my dispatch table, which takes the index from the
** conversion, the fmt_struct, and the valist. it returns the string that the
** conversion function makes.
**
** It doesn't need to check for a valid index, that is done in the calling
** function
**
** Current copy of flags string: (UPDATE IF YOU CHANGE IT)
** flags = "cCsS%dDiuUboOxXpfFeE";
*/

static char		*dispatch(int index, t_format *fmt_struct, va_list valist)
{
	static char	*(*p[])() = {
		[0] = flag_char,
		[1] = flag_char,
		[2] = flag_string,
		[3] = flag_wstr,
		[4] = flag_percent,
		[5] = flag_int,
		[6] = flag_int,
		[7] = flag_int,
		[8] = flag_uint,
		[9] = flag_uint,
		[10] = flag_bin,
		[11] = flag_oct,
		[12] = flag_oct,
		[13] = flag_hex,
		[14] = flag_hex,
		[15] = flag_pointer,
		[16] = flag_float,
		[17] = flag_float,
		[18] = flag_scientific,
		[19] = flag_scientific,
	};

	return (p[index](fmt_struct, valist));
}

/*
**	Parse takes a pointer to the format string at the format specifier so that
**	when it moves the pointer to the end of the format specifier, that change
**	can be reflected in the calling function.
**
**	I send in len because I'd just have to use strlen to get it later, when
**	I've already calculated it now
*/

static char		*parse(const char **format, va_list valist, size_t *len)
{
	t_format	fmt_struct;
	char		*ret;
	int			index;

	init(&fmt_struct);
	ret = 0;
	get_flags(format, &fmt_struct);
	get_width_precis(format, &fmt_struct, valist);
	get_length(format, &fmt_struct);
	index = get_conversion(format, &fmt_struct);
	if (index != -1)
	{
		ret = dispatch(index, &fmt_struct, valist);
		if (ret)
			*len = (size_t)fmt_struct.width;
	}
	return (ret);
}

/*
** Make a linked list of substrings using a format string and va_list
** Update the list with a double pointer
** Return the combined length of the substrings
**
**
** potential bug when malloc returns 0 from strndup, and whatever the length
** was supposed to be gets added, and potentially used for malloc in other
** printfs.
*/

size_t			make_list(t_list **list, const char *format, va_list valist)
{
	char	*sub;
	size_t	len;
	size_t	total_len;

	total_len = 0;
	while (format && *format)
	{
		if (*format == '%')
		{
			++format;
			sub = parse(&format, valist, &len);
			if (!sub)
				continue ;
		}
		else
		{
			len = ft_dstrlen(format, '%');
			sub = ft_strndup(format, len);
			format += len;
		}
		total_len += len;
		ft_lstadd_tail(list, ft_lstinit(sub, len));
	}
	return (total_len);
}

/*
** This function combines all the strings in a list
*/

char			*combine_list(t_list *list, int size_of_list)
{
	char	*newstr;
	char	*cur;
	t_list	*lcur;

	newstr = ft_strnew(size_of_list);
	cur = newstr;
	lcur = list;
	while (lcur)
	{
		ft_memcpy((void *)cur, lcur->content, lcur->content_size);
		cur += lcur->content_size;
		lcur = lcur->next;
	}
	return (newstr);
}
