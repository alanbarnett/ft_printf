/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:23:46 by abarnett          #+#    #+#             */
/*   Updated: 2018/09/03 21:46:54 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlen_base(long num, int base)
{
	int length;

	length = 1;
	if (num < 0)
	{
		num *= -1;
		++length;
	}
	while (num >= base)
	{
		num /= base;
		++length;
	}
	return (length);
}
