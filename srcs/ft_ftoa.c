/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 23:37:04 by alan              #+#    #+#             */
/*   Updated: 2019/01/02 21:31:59 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		*s = (((n % 10) * -1) + '0');
	else
		*s = ((n % 10) + '0');
}

static t_fp		get_parts(double n, int sign, int precision)
{
	t_fp	f;

	f.len_f = 0;
	f.lead_zeros = 0;
	f.trail_zeros = 0;
	while (n >= (1UL << 63))
	{
		n /= 10;
		++(f.trail_zeros);
	}
	f.integral = (f.trail_zeros) ? ft_round(n) : (long)n;
	f.len_i = ft_numlen(f.integral);
	while (SIG_F < precision && (f.len_f + SIG_I) < 17)
	{
		n *= 10;
		if ((long)n || (SIG_F == precision - 1 && ft_round(n)))
			++(f.len_f);
		else
			++(f.lead_zeros);
	}
	f.fraction = ft_round(n);
	if (sign)
		++(f.len_i);
	return (f);
}

static char		*make_string(t_fp f, int sign, int precision)
{
	char	*s;

	s = ft_strnew(SIG_I + 1 + precision);
	if (sign)
	{
		*s = '-';
		ft_nbrcpy_p(f.integral, f.len_i - 1, s + f.len_i - 1);
	}
	else
		ft_nbrcpy_p(f.integral, f.len_i, s + f.len_i - 1);
	if (f.trail_zeros)
		ft_nbrcpy_p(0, f.trail_zeros, s + SIG_I - 1);
	if (precision)
		s[SIG_I] = '.';
	if (f.lead_zeros)
		ft_nbrcpy_p(0, f.lead_zeros, s + SIG_I + f.lead_zeros);
	if (f.len_f)
		ft_nbrcpy_p(f.fraction, f.len_f, s + SIG_I + SIG_F);
	if (precision > SIG_F)
		ft_nbrcpy_p(0, precision - SIG_F, s + SIG_I + precision);
	return (s);
}

char			*ft_ftoa(double n, int precision)
{
	t_double	unb;
	t_fp		f;
	int			sign;
	int			exp;
	long		mantissa;

	unb.d = n;
	sign = (unb.l >> 63) & 1;
	exp = ((unb.l >> 52) & 0x7ff);
	mantissa = (unb.l & 0x000fffffffffffff);
	if (exp == 0x7ff)
	{
		if (mantissa)
			return (ft_strdup("nan"));
		else
			return (ft_strdup((sign) ? "-inf" : "inf"));
	}
	f = get_parts(n, sign, precision);
	return (make_string(f, sign, precision));
}
