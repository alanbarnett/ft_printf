/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 04:36:34 by alan              #+#    #+#             */
/*   Updated: 2018/12/14 18:21:36 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Figures out the size of the number to be pulled from va_arg
** Uses the length in my format struct, passed as a character
** Checks for capital as a shortcut for long
*/

static long long	get_nb(char conv, char length, va_list valist)
{
	long long	nb;

	nb = 0;
	if (conv == 'D')
	{
		if (length == 'l' || length == 'L')
			length = 'L';
		else
			length = 'l';
	}
	if (length == 0)
		nb = va_arg(valist, int);
	else if (length == 'l')
		nb = va_arg(valist, long);
	else if (length == 'L')
		nb = va_arg(valist, long long);
	else if (length == 'h')
		nb = (short)va_arg(valist, int);
	else if (length == 'H')
		nb = (char)va_arg(valist, int);
	else if (length == 'j')
		nb = va_arg(valist, long long);
	else if (length == 'z')
		nb = va_arg(valist, size_t);
	return (nb);
}

/*
** This function adds the sign and zeros from a format struct to a string
**
** First it moves the string, if it's supposed to be left justified,
** then it will add the appropriate sign to the string, based on the sign of
** the number and the PLUS and SPACE flags,
** then it checks if the length of the number is greater than zero,
** then it replaces spaces in between the minus sign and the number with zeros.
*/

static void			add_flags(char *str, t_format *fmt, long long nb, int len)
{
	if (!(fmt->flags & MINUS))
		str += (fmt->width - fmt->precision);
	if (((fmt->flags & (PLUS | SPACE)) || nb < 0))
	{
		if (nb < 0)
			*str++ = '-';
		else if ((fmt->flags & PLUS) && nb >= 0)
			*str++ = '+';
		else if ((fmt->flags & SPACE) && nb >= 0)
			*str++ = ' ';
	}
	if (len)
	{
		while (str && *str == ' ')
			*str++ = '0';
	}
}

/*
** This function takes a string that has malloced space that is guaranteed to
** fit the size of the number, and it converts the number to a string while
** placing it inside the string. It's like itoa, except for it doesn't make
** memory.
**
** The string starts at the end of the number, with the pointer pointing to the
** last digit.
**
** It will recursively break down the number, moving the string backwards with
** each step. Once the number is small enough, it will add the ascii at the
** character position. It does not care about the sign of the number.
*/

static void			ft_nbrcpy(long long nb, char *str)
{
	if (nb >= 10 || nb <= -10)
		ft_nbrcpy(nb / 10, str - 1);
	if (nb < 0)
		*str = (ft_abs(nb % 10) + '0');
	else
		*str = (nb % 10 + '0');
}

/*
** this function does the following:
** makes the length of the string I'll need
**	width should be the full size of the string
**	precision should be the size of the substring inside
**		including zeros, and the sign, and the length of the number
**	len is the length of the number, without the sign
*/
/*
************************      ADDITIONAL NOTES      ***************************
**
** do I need a zeros flag?
**	can use precision value for zeros
**	if zeros is set, precision is set to width
**	cases where zeros isn't set:
**		when we have a specific precision
**			handled normally with precision
**		when we don't want zeros
**			can be taken care of by properly setting precision
**	the answer is no
**
**	I don't need a zeros flag, precision will be changed to larger than the
**	length of the number if I want to add zeros
**
*******************************************************************************
**
** width, precision, zeros
** it can have a width and a precision
** it can have a width and zeros
** it cannot have zeros and precision
** it can have only width
** it can have only preicision
** it cannot have only zeros
**
** width and precision is width outside zeros
** width and zeros is the same thing as precision the size of width
** precision greater than width is just width with zeros
**
** width on the left
**	works with precision just the same
**	just on the other side
**	doesn't work with zeros
**		these flags cancel as a part of the format struct creation much earlier
**
*******************************************************************************
**
** there are six cases
**
** len > width > precision && len > precision > width
**	precision does not truncate
**		less than len, can be ignored
**	width does not truncate
**		less than len, can be ignored
**	overall length is len
**	edge cases
**		precision is 0
**			if number is 0, len is 0
**
** width > len > precision
**	there will be empty space if width is bigger than len
**	precision has no effect less than the number
**	overall length is width
**	edge cases
**		precision is 0
**			if number is 0, len is 0
** width > precision > len
**	width will cause empty space bigger than the number and precision
**	precision bigger than the number causes zeros
**	overall length is width, precision is still important
**
** precision > len > width && precision > width > len
**	width ignored, precision bigger than len so there will be zeros
**	overall length is precision
**		identical to width, no precision, and zeros
**
** If width is largest, nothing happens
** If len is larger than width, set width to len
**		this avoids a width that's too small, which has no effect.
** If precision is larger than width, set width to max of precision and len
**		precision has higher precedence than width
**		len is still important
** If either precision or width are smaller than len
**		they have no effect
** Overall, this sets the width to the maximum size of the new string
**
*******************************************************************************
*/
/*
** // Function with notes on the lines mixed in
** static char			*format_nb(t_format *fmt, int nb, int len)
** {
** 	// if precision is supplied,
** 	// if it's less than the len,
** 	// 	set it to the len
** 	// if there's a sign,
** 	// 	increase precision to fit the sign
** 	// if the width is less than precision,
** 	// 	set width to precision
** 	if (fmt->precision != -1)
** 	{
** 		if (fmt->precision < len)
** 			fmt->precision = len;
** 		if ((fmt->flags & (PLUS | SPACE)) || nb < 0)
** 			++fmt->precision;
** 		if (fmt->precision > fmt->width)
** 			fmt->width = fmt->precision;
** 	}
** 	// if precision is not supplied,
** 	// set width to the length of the number w/o sign, if it's less
** 	// set precision to the length of the number
** 	// if there's a sign,
** 	// 	increase precision to hold it
** 	// 	if width is still the size of the number,
** 	// 		increase width to hold it
** 	// if zeros,
** 	// 	set precision to width
** 	else
** 	{
** 		fmt->width = ft_max(fmt->width, len);
** 		fmt->precision = len;
** 		if (((fmt->flags & (PLUS | SPACE)) || nb < 0))
** 		{
** 			++fmt->precision;
** 			if (fmt->width == len)
** 				++fmt->width;
** 		}
** 		if (fmt->flags & ZERO)
** 			fmt->precision = fmt->width;
** 	}
** 	// Here, width is set to max length
** 	// precision is set to the size of the internal string
** 	// 	includes the sign
** 	return (ft_strinit(fmt->width, ' '));
** }
*/

static char			*format_nb(t_format *fmt, long long nb, int len)
{
	if (fmt->precision != -1)
	{
		if (fmt->precision < len)
			fmt->precision = len;
		if ((fmt->flags & (PLUS | SPACE)) || nb < 0)
			++fmt->precision;
		if (fmt->precision > fmt->width)
			fmt->width = fmt->precision;
	}
	else
	{
		fmt->width = ft_max(fmt->width, len);
		fmt->precision = len;
		if (((fmt->flags & (PLUS | SPACE)) || nb < 0))
		{
			++fmt->precision;
			if (fmt->width == len)
				++fmt->width;
		}
		if (fmt->flags & ZERO)
			fmt->precision = fmt->width;
	}
	return (ft_strinit(fmt->width, ' '));
}

/*
** This function creates of a string from my format struct for an integer
**
** If precision and the number are zero, set the length of the number to zero.
** len will be used to determine the sizes of width and precision in format_nb,
** and setting it to 0 here makes sure there is no number (which is what's
** supposed to happen with these values).
** Sign is not included in the length, this is just the length of digits.
**
** Then the struct gets formatted for the number and it's length
**
** Then the number is copied into the string
** - not copied if the length is zero
** - copied to the right or left side, based on the MINUS flag
**
** Then the sign and zeros are added to the string.
*/

char				*flag_int(t_format *fmt, va_list valist)
{
	char		*str;
	long long	nb;
	int			len;

	nb = get_nb(fmt->conv, fmt->length, valist);
	if (fmt->precision == 0 && nb == 0)
		len = 0;
	else
		len = ft_numlen(nb);
	str = format_nb(fmt, nb, len);
	if (len)
	{
		if (fmt->flags & MINUS)
			ft_nbrcpy(nb, str + (fmt->precision - 1));
		else
			ft_nbrcpy(nb, str + (fmt->width - 1));
	}
	add_flags(str, fmt, nb, len);
	return (str);
}
