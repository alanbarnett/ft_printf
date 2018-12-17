/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 10:05:09 by abarnett          #+#    #+#             */
/*   Updated: 2018/06/06 17:26:00 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	append_character(char *dest, char src)
{
	while (*dest)
		dest++;
	*dest++ = src;
	*dest = '\0';
}

static void	recursive_strfill(char *str, long num)
{
	if (num >= 10)
		recursive_strfill(str, num / 10);
	append_character(str, ('0' + num % 10));
}

char		*ft_itoa(int n)
{
	char	*str;
	long	num;

	num = (long)n;
	if (num < 0)
	{
		num *= -1;
		str = ft_strnew(ft_numlen(num) + 1);
		if (!str)
			return (0);
		str[0] = '-';
	}
	else
	{
		str = ft_strnew(ft_numlen(num));
		if (!str)
			return (0);
	}
	recursive_strfill(str, num);
	return (str);
}
