/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 23:37:04 by alan              #+#    #+#             */
/*   Updated: 2018/12/28 00:17:28 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef union	u_double
{
	double		d;
	long		l;
}				t_double;

typedef	struct	s_fp
{
	long		integer;
	long		fraction;
	int			len_i;
	int			len_f;
	int			lead_zeros;
	int			trail_zeros;
}				t_fp;

static void		ft_nbrcpy_p(long n, int precision, char *s)
{
	if (precision > 1)
	{
		if (n >= 10 || n <= -10)
			ft_nbrcpy_p(n / 10, precision - 1, s - 1);
		else
			ft_nbrcpy_p(0, precision - 1, s - 1);
	}
	if (n < 0)
		*s = (ft_abs(n % 10) + '0');
	else
		*s = ((n % 10) + '0');
}

static t_fp		get_parts(double n, int sign, int precision)
{
	t_fp	f;

	f.len_i = 0;
	f.len_f = 0;
	f.lead_zeros = 0;
	f.trail_zeros = 0;
	while (n >= (1UL << 63))
	{
		n /= 10;
		++(f.trail_zeros);
	}
	f.integer = (f.trail_zeros) ? ft_round(n) : (long)n;
	f.len_i = ft_numlen(f.integer) + ((sign) ? 1 : 0);
	while (f.lead_zeros + f.len_f < precision &&
			((f.len_f + f.len_i + f.trail_zeros) < 17))
	{
		n *= 10;
		if ((n <= -1 || n >= 1) ||
			(f.lead_zeros + f.len_f == precision - 1 && ft_round(n)))
			++(f.len_f);
		else
			++(f.lead_zeros);
	}
	f.fraction = ft_round(n);
	return (f);
}

static char		*make_string(t_fp f, int sign, int precision)
{
	char	*s;

	s = ft_strnew(f.len_i + f.trail_zeros + 1 + precision);
	if (sign)
	{
		*s = '-';
		ft_nbrcpy_p(f.integer, f.len_i - 1, s + f.len_i - 1);
	}
	else
		ft_nbrcpy_p(f.integer, f.len_i, s + f.len_i - 1);
	f.len_i = f.len_i + f.trail_zeros;
	if (f.trail_zeros)
		ft_nbrcpy_p(0, f.trail_zeros, s + f.len_i - 1);
	if (precision)
		s[f.len_i] = '.';
	if (f.lead_zeros)
		ft_nbrcpy_p(0, f.lead_zeros, s + f.len_i + f.lead_zeros);
	if (f.len_f)
		ft_nbrcpy_p(f.fraction, f.len_f, s + f.len_i + f.lead_zeros + f.len_f);
	if (precision > f.len_f + f.lead_zeros)
		ft_nbrcpy_p(0, precision - f.len_f, s + f.len_i + precision);
	return (s);
}

char			*ft_ftoa(double n, int precision)
{
	t_double	doub;
	t_fp		f;
	int			sign;
	int			exponent;
	long		significand;

	doub.d = n;
	sign = (doub.l >> 63) & 1;
	exponent = ((doub.l >> 52) & 0x7ff);
	significand = (doub.l & 0x000fffffffffffff);
	if (exponent == 0x7ff)
	{
		if (significand)
			return (ft_strdup("nan"));
		else
			return (ft_strdup((sign) ? "-inf" : "inf"));
	}
	f = get_parts(n, sign, precision);
	return (make_string(f, sign, precision));
}
