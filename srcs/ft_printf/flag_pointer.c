/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 21:30:54 by abarnett          #+#    #+#             */
/*   Updated: 2019/01/05 22:13:49 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** This function adds the flags from a format struct to a string
**
** First it moves the string, if it's supposed to be left justified,
** then it checks if the length of the number is greater than zero before
** adding anything,
** then it adds the 0x if it needs to,
** then it replaces spaces up to the number with zeros.
*/

static void					add_flags(char *str, t_format *fmt)
{
	if (!(fmt->flags & MINUS))
		str += (fmt->width - fmt->precision);
	ft_strncpy(str, "0x", 2);
	str += 2;
	while (str && *str == ' ')
		*str++ = '0';
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
** character position.
*/

static void					ft_unbrcpy_hex(unsigned long long nb, char *str)
{
	if (nb >= 16)
		ft_unbrcpy_hex(nb / 16, str - 1);
	if ((nb % 16) >= 10)
		*str = ((nb % 16) + 'a' - 10);
	else
		*str = ((nb % 16) + '0');
}

/*
** This function creates a string from my format struct for a hexadecimal
** number
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
** Then the alternate form and zeros are added to the string
**
** Then it is made uppercase if it is a capital conversion
*/

char						*flag_pointer(t_format *fmt, va_list valist)
{
	char				*str;
	unsigned long long	nb;
	int					len;

	nb = va_arg(valist, unsigned long long);
	if (nb == 0 && fmt->precision == 0)
		len = 0;
	else
		len = ft_unumlen_base(nb, 16);
	if (fmt->precision == -1 || fmt->precision < len)
		fmt->precision = len + 2;
	else
		fmt->precision += 2;
	fmt->width = ft_max(fmt->width, fmt->precision);
	str = ft_strinit(fmt->width, ' ');
	if (fmt->flags & MINUS)
		ft_unbrcpy_hex(nb, str + (fmt->precision - 1));
	else
		ft_unbrcpy_hex(nb, str + (fmt->width - 1));
	add_flags(str, fmt);
	return (str);
}
