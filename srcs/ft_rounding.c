/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rounding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 04:11:14 by alan              #+#    #+#             */
/*   Updated: 2018/12/22 03:11:52 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ceil(double roundee)
{
	int	rounded;

	rounded = (int)roundee;
	if (rounded >= 0 && rounded < roundee)
		++rounded;
	else if (rounded < 0 && rounded > roundee)
		--rounded;
	return (rounded);
}

int		ft_floor(double roundee)
{
	int	rounded;

	rounded = (int)roundee;
	return (rounded);
}

long	ft_round(double roundee)
{
	long	rounded;

	if (roundee >= 0)
	{
		if ((roundee - (long)roundee) * 10 >= 5)
			rounded = (long)roundee + 1;
		else
			rounded = (long)roundee;
	}
	else
	{
		if ((roundee - (long)roundee) * -10 >= 5)
			rounded = (long)roundee - 1;
		else
			rounded = (long)roundee;
	}
	return (rounded);
}

double	ft_round_d(double roundee)
{
	double	rounded;

	/*
	if (roundee < (1L << 63))
		rounded = (double)ft_round(roundee);
	else
		rounded = roundee;
	*/
	rounded = roundee;
	return (rounded);
}
