/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftosn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 04:19:45 by rreedy            #+#    #+#             */
/*   Updated: 2019/01/05 18:46:09 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static void		nbrcpy_p(long nb, int precision, char *str)
{
	long int	multiplier;
	int			len;
	int			i;

	len = ft_numlen(nb);
	i = 0;
	multiplier = ft_pow(10, len - 1);
	while (str[i] && i < precision)
	{
		if (i < (precision - len))
			str[i] = '0';
		else
		{
			str[i] = ((nb / multiplier) % 10) * ((nb < 0) ? -1 : 1) + '0';
			multiplier = multiplier / 10;
		}
		++i;
	}
}

static t_fp		get_parts(double nb, int *exponent, int precision)
{
	t_fp	f;
	int		len;

	if (precision > 15)
		precision = 15;
	len = ft_numlen((long)nb);
	while (nb && (nb > (1UL << 63) || len != precision + 1))
	{
		if (nb > (1UL << 63) || len > precision + 1)
		{
			nb /= 10;
			++(*exponent);
		}
		else
		{
			nb *= 10;
			--(*exponent);
		}
		len = ft_numlen((long)nb);
	}
	f.integer = ft_round(nb) / ft_pow(10, precision);
	f.fraction = ft_round(nb) - (f.integer * (long)ft_pow(10, precision));
	if (nb)
		*exponent += precision;
	return (f);
}

static char		*make_string(t_fp f, int sign, int exponent, int precision)
{
	char	*str;
	char	*cur;

	str = ft_strinit('0', sign + 3 + ((precision) ? precision + 1 : 0) +
		((ft_numlen(exponent) < 2) ? 2 : ft_numlen(exponent)));
	cur = str;
	if (sign)
		*cur++ = '-';
	*cur++ = f.integer + '0';
	if (precision)
	{
		*cur++ = '.';
		if (precision > 15)
			nbrcpy_p(f.fraction, 15, cur);
		else
			nbrcpy_p(f.fraction, precision, cur);
	}
	if (exponent >= 0)
		ft_strncpy(str + sign + ((precision) ? precision + 1 : 0) + 1, "e+", 2);
	else
		ft_strncpy(str + sign + ((precision) ? precision + 1 : 0) + 1, "e-", 2);
	cur = str + ft_strlen(str) - ft_numlen(exponent);
	nbrcpy_p(exponent, ft_numlen(exponent), cur);
	return (str);
}

char			*ft_ftosn(double n, int precision)
{
	t_double	doub;
	t_fp		f;
	int			sign;
	int			exp;
	long		mantissa;

	doub.d = n;
	sign = (doub.l >> 63) & 1;
	exp = ((doub.l >> 52) & 0x7ff);
	mantissa = (doub.l & 0x000fffffffffffff);
	if (exp == 0x7ff)
	{
		if (mantissa)
			return (ft_strdup("nan"));
		else
			return (ft_strdup((sign) ? "-inf" : "inf"));
	}
	exp = 0;
	f = get_parts(ft_absd(n), &exp, precision);
	return (make_string(f, sign, exp, precision));
}
