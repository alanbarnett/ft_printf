/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan </var/spool/mail/alan>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 04:24:42 by alan              #+#    #+#             */
/*   Updated: 2018/11/30 04:36:04 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

/*
** Some useful math functions
*/

int		ft_vamax(int params, ...)
{
	va_list	nums;
	int		max;
	int		cur;

	va_start(nums, params);
	max = 0;
	if (params)
	{
		max = va_arg(nums, int);
		while (--params)
		{
			cur = va_arg(nums, int);
			if (cur > max)
				max = cur;
		}
	}
	return (max)
}

int		ft_vamin(int params, ...)
{
	va_list	nums;
	int		min;
	int		cur;

	va_start(nums, params);
	min = 0;
	if (params)
	{
		min = va_arg(nums, int);
		while (--params)
		{
			cur = va_arg(nums, int);
			if (cur < min)
				min = cur;
		}
	}
	return (min)
}

long	ft_abs(long nb)
{
	return (nb < 0 ? (nb * -1) : nb);
}
