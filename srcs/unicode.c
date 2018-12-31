/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:52:10 by abarnett          #+#    #+#             */
/*   Updated: 2018/12/31 05:50:57 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static int	get_bytes(wchar_t wc)
{
	int		i;

	i = 32;
	while (i > 0 && !(wc >> (i - 1)))
		--i;
	return ((i > 7) ? ((i + 3) / 5) : 1);
}

/*
** This function converts a single wide character to a utf-8 multi-byte
** character.
**
**	if (!str && wchar)
**		str = ft_strnew(bytes);
** this checks if the string already exists, because it can be passed to this
** function (i.e. when it's used in conv_utf8_str), or it can be ignored (like
** when this function is used on its own). don't allocate space for a string
** that already exists.
**
**	if (!wchar || !str)
**		return ((!wchar) ? ft_strnew(1) : 0);
** check if either we have recieved an empty character, or if the alloc
** failed. ternary to check if we have recieved an empty character, then
** return an empty string with strnew, else if s alloc failed, return 0
** This won't cause a memory leak, because we already check if the character
** exists in the previous statement, so it wouldn't have alloced s if there
** was no character
**
**	*cur |= (!(cur - str) ? (0xFF << (8 - bytes)) : 0x80);
** This adds an empty continuation byte if the cursor is ahead of s
** if the cursor is on s (cur - str == 0, returning false), it adds an empty
** starting utf-8 byte.
**	*cur |= (wchar & 0x3F);
** This adds the first six bits of the wide character into the cursor,
**	wchar = wchar >> 6;
** and then this shifts the wide character over to the next 6.
**	cur = (cur - str) ? (cur - 1) : 0;
** finally, we move the cursor, or set it to 0 if it's on s (cur - str == 0,
** returning false).
*/

char		*conv_utf8_char(wchar_t wchar, char *str)
{
	char	*cur;
	int		bytes;

	bytes = get_bytes(wchar);
	if (!str && wchar)
		str = ft_strnew(bytes);
	if (!wchar || !str)
		return ((!wchar) ? ft_strnew(1) : 0);
	cur = str + bytes - 1;
	if (bytes > 1)
		while (cur >= str)
		{
			*cur |= (!(cur - str) ? (0xFF << (8 - bytes)) : 0x80);
			*cur |= (wchar & 0x3F);
			wchar = wchar >> 6;
			cur = (cur - str) ? (cur - 1) : 0;
		}
	else
		*cur = (char)wchar;
	return (str);
}

/*
**	This function converts a wide character string to a utf-8 character string
**
**	if (!wstr)
**		return (0);
** if no string, don't do anything
**
**	while (wstr && *wstr)
**		totalbytes += get_bytes(*wstr++);
** check if the character is valid to grab bytes
** this is so it doesn't get bytes for a null character
** also move wstr to the end
**
**	str += totalbytes;
** this starts s at the last byte, so we can move backwards. this is
** essentially to remove the need for a counter variable, because if I were to
** move forwards, we would have to count up to totalbytes. this allows me to
** move str and wstr backwards, while decreasing totalbytes to 0.
**
**	--wstr;
** move behind the null terminator (that's what wstr should be at now, thanks to
** the while loop earlier)
**	bytes = get_bytes(*wstr);
** get the bytes for the current character
**	totalbytes -= bytes;
** decrease totalbytes by that amount
**	str -= bytes;
** move str backwards by that amount, so it's lined up with the beginning of the
** character it's about to copy
**	str = conv_utf8_char(*wstr, str);
** copy the character
*/

char		*conv_utf8_str(wchar_t *wstr)
{
	char	*str;
	int		bytes;
	int		totalbytes;

	totalbytes = 0;
	if (!wstr)
		return (0);
	while (wstr && *wstr)
		totalbytes += get_bytes(*wstr++);
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
