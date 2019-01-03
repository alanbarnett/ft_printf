/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:24:01 by alan              #+#    #+#             */
/*   Updated: 2019/01/02 21:10:12 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** This function adds extra spaces on the left or right size of a string, as
** specified by the variable "left". If zero, spaces are put on the right side.
** If 1, they are put on the left. The "spaces" variable holds the number of
** extra spaces to be added.
*/

static char		*addspaces(char **str, int spaces, int left)
{
	int		len_str;
	char	*newstr;

	len_str = ft_strlen(*str);
	newstr = ft_strinit(len_str + spaces, ' ');
	if (left)
		ft_strncpy(newstr, *str, len_str);
	else
		ft_strncpy(newstr + spaces, *str, len_str);
	ft_strdel(str);
	return (newstr);
}

static double	get_nb(char length, va_list valist)
{
	double	nb;

	nb = 0;
	if (length == 0)
		nb = va_arg(valist, double);
	else if (length == 'l')
		nb = va_arg(valist, double);
	else if (length == 'L')
		nb = va_arg(valist, long double);
	return (nb);
}

char			*flag_float(t_format *fmt, va_list valist)
{
	double	nb;
	char	*str;
	int		len;

	nb = get_nb(fmt->length, valist);
	if (fmt->precision == -1)
		fmt->precision = 6;
	str = ft_ftoa(nb, fmt->precision);
	len = ft_strlen(str);
	if (fmt->width > len)
		str = addspaces(&str, fmt->width - len, fmt->flags & MINUS);
	fmt->width = ft_strlen(str);
	return (str);
}
