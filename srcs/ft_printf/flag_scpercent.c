/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_scpercent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 21:34:21 by abarnett          #+#    #+#             */
/*   Updated: 2018/12/31 05:21:48 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** This function sets the width to the full size of the string, and the
** precision to the size of the substring inside.
**
** It takes the length of the string to compare, and the format struct for
** access to precision and width
*/

static char			*format_string(t_format *fmt, char *str, int len)
{
	if (fmt->precision != -1)
	{
		if (fmt->precision > len)
			fmt->precision = len;
		else if (fmt->precision < len && !str)
			fmt->precision = 0;
		if (fmt->precision > fmt->width)
			fmt->width = fmt->precision;
	}
	else
	{
		fmt->width = ft_max(fmt->width, len);
		fmt->precision = len;
	}
	return (ft_strinit(fmt->width, ' '));
}

char				*flag_string(t_format *fmt, va_list valist)
{
	char	*str;
	char	*newstr;
	int		len;

	if (fmt->length == 'l')
		return (flag_wstr(fmt, valist));
	str = va_arg(valist, char *);
	if (!str)
		len = 6;
	else
		len = ft_strlen(str);
	newstr = format_string(fmt, str, len);
	if (!str)
		str = "(null)";
	if (fmt->flags & MINUS)
		ft_strncpy(newstr, str, fmt->precision);
	else
		ft_strncpy(newstr + fmt->width - fmt->precision, str, fmt->precision);
	return (newstr);
}

char				*flag_char(t_format *fmt, va_list valist)
{
	char	c;
	char	*newstr;

	if (fmt->length == 'l')
		return (flag_wchar(fmt, valist));
	c = (char)va_arg(valist, int);
	if (fmt->width < 1)
		fmt->width = 1;
	newstr = ft_strinit(fmt->width, ' ');
	if (fmt->flags & MINUS)
		newstr[0] = c;
	else
		newstr[fmt->width - 1] = c;
	return (newstr);
}

/*
** This function makes a new string of the width (or 1, of width is less), and
** copies a percent sign in on the left or right, depending on the MINUS flag.
*/

char				*flag_percent(t_format *fmt)
{
	char	*newstr;

	if (fmt->width < 1)
		fmt->width = 1;
	newstr = ft_strinit(fmt->width, ' ');
	if (fmt->flags & MINUS)
		newstr[0] = '%';
	else
		newstr[fmt->width - 1] = '%';
	return (newstr);
}
