/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 23:37:04 by alan              #+#    #+#             */
/*   Updated: 2018/12/24 01:43:18 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef union	u_double
{
	double		d;
	long		l;
}				t_double;

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

static void		ft_nbrcpy_p(long nb, int precision, char *str)
{
	if (precision > 1)
	{
		if (nb >= 10 || nb <= -10)
			ft_nbrcpy_p(nb / 10, precision - 1, str - 1);
		else
			ft_nbrcpy_p(0, precision - 1, str - 1);
	}
	if (nb < 0)
		*str = (ft_abs(nb % 10) + '0');
	else
		*str = ((nb % 10) + '0');
}

/*
** Gather fraction part without bits
*/

static void		copy_fraction(char *str, double num, int precision, int offset)
{
	double	fraction;
	int		len_of_f;
	int		leading_zeros;

	len_of_f = 0;
	leading_zeros = 0;
	while (leading_zeros + len_of_f < precision && (len_of_f + offset < 17))
	{
		num *= 10;
		if (num < -1 || num > 1)
			++len_of_f;
		else
			++leading_zeros;
	}
	fraction = ft_round(num);

	if (leading_zeros)
		ft_nbrcpy_p(0, leading_zeros, str + offset + leading_zeros);
	ft_nbrcpy_p(fraction, len_of_f, str + offset + leading_zeros + len_of_f);
	if (precision > len_of_f + leading_zeros)
		ft_nbrcpy_p(0, precision - len_of_f, str + offset + precision);
}

static char		*make_string(int sign, long intpart, double num, int precision)
{
	int		len_of_i;
	char	*str;

	len_of_i = ft_numlen(intpart);
	if (sign)
	{
		++len_of_i;
		str = ft_strnew(len_of_i + 1 + precision);
		*str = '-';
		ft_nbrcpy_p(intpart, len_of_i - 1, str + len_of_i - 1);
	}
	else
	{
		str = ft_strnew(len_of_i + 1 + precision);
		ft_nbrcpy_p(intpart, len_of_i, str + len_of_i - 1);
	}
	str[len_of_i] = '.';
	copy_fraction(str, num, precision, len_of_i);
	return (str);
}

static long		get_intpart(int exp, long mantissa)
{
	long	intpart;

	intpart = 0;
	if (52 <= exp && exp < 64)
		intpart = (mantissa << (exp - 52));
	else if (0 <= exp && exp < 52)
		intpart = (mantissa >> (52 - exp));
	return (intpart);
}

char			*ft_ftoa(double nb, int precision)
{
	t_double	unb;
	int			exp;
	long		mantissa;
	long		intpart;

	unb.d = nb;
	exp = ((unb.l >> 52) & 0x7ff);
	mantissa = (unb.l & 0x000fffffffffffff);
	if (exp == 0x7ff)
		if (mantissa)
			return (ft_strdup("nan"));
		else
			if (unb.l & (1L << 63))
				return (ft_strdup("-inf"));
			else
				return (ft_strdup("inf"));
	else if (exp != 0)
		mantissa |= (1L << 52);
	exp -= 0x3ff;
	intpart = get_intpart(exp, mantissa);
	return (make_string(((unb.l >> 63) & 1), intpart, nb, precision));
}
