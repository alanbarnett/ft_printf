/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_unicode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 01:16:24 by abarnett          #+#    #+#             */
/*   Updated: 2019/01/02 21:06:50 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** This function adds extra spaces on the left or right size of a string, as
** specified by the variable "left". If zero, spaces are put on the right side.
** If 1, they are put on the left. The "spaces" variable holds the number of
** extra spaces to be added.
*/

static char		*addspaces(char **str, int spaces, int left)
{
	int		len_str;
	char	*newstr;

	len_str = ft_strlen(*str);
	newstr = ft_strinit(len_str + spaces, ' ');
	if (left)
		ft_strncpy(newstr, *str, len_str);
	else
		ft_strncpy(newstr + spaces, *str, len_str);
	ft_strdel(str);
	return (newstr);
}

/*
** This function figures out how many bits a single wide character will need
** when it is converted to a utf-8 multi-byte character
**
** (wc >> (i - 1)) shifts the bits over to isolate the last bit
** it will be true any time there's a 1 bit
** "not"ing it will make it false until we reach the first 1
**
** 08                   11000011 10111111
** 09                   11000111 10111111
** 10                   11001111 10111111
** 11                   11011111 10111111
** 12          11100000 10111111 10111111
** 13          11100001 10111111 10111111
** 14          11100011 10111111 10111111
** 15          11100111 10111111 10111111
** 16          11101111 10111111 10111111
** 17 11110000 10011111 10111111 10111111
** 18 11110000 10111111 10111111 10111111
** 19 11110001 10111111 10111111 10111111
** 20 11110011 10111111 10111111 10111111
** 21 11110111 10111111 10111111 10111111
**
** bytes = (bits + 3) / 5
** ((i > 7) ? ((i + 3) / 5) : 1);
** The bits fall into groups of 5, so the expression calculates which group it
** falls into. 7 technically fits in the first group (2 bytes), so only do this
** if i > 7.
*/

static int		get_bytes(wchar_t wc)
{
	int		i;

	i = 32;
	while (i > 0 && !(wc >> (i - 1)))
		--i;
	return ((i > 7) ? ((i + 3) / 5) : 1);
}

/*
** This function converts a wide character string to a utf-8 character string
** It also cuts the wide character string at length precision
**
** The only difference this function has with the regular, non-precision
** version is this while loop:
**	i = 0;
**	while (wstr && *wstr && i < precision)
**	{
**		totalbytes += get_bytes(*wstr++);
**		++i;
**	}
** Instead of just going all the way up, it has a counter up to precision. This
** way, wstr stops moving once i reaches precision, and totalbytes stops
** counting. Now the new size of the string is made, wstr is at the end of
** precision, and when str gets moved to the end, it still uses totalbytes, so
** everything works out.
*/

static char		*conv_utf8_str_precision(wchar_t *wstr, int precision)
{
	char	*str;
	int		bytes;
	int		totalbytes;
	int		i;

	if (!wstr)
		return (0);
	totalbytes = 0;
	i = 0;
	while (wstr && *wstr && i < precision)
	{
		totalbytes += get_bytes(*wstr++);
		++i;
	}
	str = ft_strnew(totalbytes);
	str += totalbytes;
	while (totalbytes)
	{
		--wstr;
		bytes = get_bytes(*wstr);
		totalbytes -= bytes;
		str -= bytes;
		str = conv_utf8_char(*wstr, str);
	}
	return (str);
}

char			*flag_wstr(t_format *fmt, va_list valist)
{
	wchar_t	*str;
	char	*newstr;
	int		len;

	str = va_arg(valist, wchar_t *);
	if (!str)
		str = L"(null)";
	len = ft_wstrlen(str);
	if (fmt->precision > len || fmt->precision == -1)
		fmt->precision = len;
	if (fmt->width < fmt->precision)
		fmt->width = fmt->precision;
	newstr = conv_utf8_str_precision(str, fmt->precision);
	if (fmt->width > fmt->precision)
		newstr = addspaces(&newstr, fmt->width - fmt->precision,
				fmt->flags & MINUS);
	fmt->width = ft_strlen(newstr);
	return (newstr);
}

char			*flag_wchar(t_format *fmt, va_list valist)
{
	wchar_t	c;
	char	*newstr;

	c = va_arg(valist, wchar_t);
	newstr = conv_utf8_char(c, 0);
	if (fmt->width > 1)
		newstr = addspaces(&newstr, fmt->width - 1, fmt->flags & MINUS);
	fmt->width = ft_strlen(newstr);
	return (newstr);
}
