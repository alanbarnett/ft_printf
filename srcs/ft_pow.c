/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:57:15 by alan              #+#    #+#             */
/*   Updated: 2018/12/20 09:49:08 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_pow(int a, int b)
{
	long	power;

	power = 1;
	while (b > 0)
	{
		power *= a;
		--b;
	}
	return (power);
}

double	ft_pow_d(double a, int b)
{
	double	power;

	power = 1;
	while (b > 0)
	{
		power *= a;
		--b;
	}
	return (power);
}
