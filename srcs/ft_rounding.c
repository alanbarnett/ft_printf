/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rounding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 04:11:14 by alan              #+#    #+#             */
/*   Updated: 2018/12/17 06:32:52 by alan             ###   ########.fr       */
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

long	ft_round_p(double roundee, int precision)
{
	long	rounded;
	int		difference;

	difference = ft_numlen((long)roundee) - precision;
	while (difference-- > 0)
		roundee /= 10;
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
	difference = ft_numlen((long)roundee) - precision;
	while (difference-- > 0)
		rounded *= 10;
	return (rounded);
}
