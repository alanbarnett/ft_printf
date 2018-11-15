/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 10:14:30 by abarnett          #+#    #+#             */
/*   Updated: 2018/11/06 14:34:01 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_numlen(long num)
{
	size_t	length;

	length = 1;
	if (num < 0)
	{
		num *= -1;
		++length;
	}
	while (num >= 10)
	{
		num /= 10;
		++length;
	}
	return (length);
}
