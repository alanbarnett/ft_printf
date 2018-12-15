/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:23:46 by abarnett          #+#    #+#             */
/*   Updated: 2018/12/13 20:58:36 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** numlen that counts the sign
*/

size_t	ft_numlen_sign_base(long long num, int base)
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

/*
** numlen that does not count the sign
*/

size_t	ft_numlen_base(long long num, int base)
{
	int length;

	length = 1;
	while (num >= base || num <= -base)
	{
		num /= base;
		++length;
	}
	return (length);
}

/*
** numlen that works for unsigned numbers
*/

size_t	ft_unumlen_base(unsigned long long num, int base)
{
	int length;

	length = 1;
	while (num >= (unsigned int)base)
	{
		num /= base;
		++length;
	}
	return (length);
}
