/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_unicode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 01:16:24 by abarnett          #+#    #+#             */
/*   Updated: 2018/12/31 06:00:21 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*flag_wstr(t_format *fmt, va_list valist)
{
	wchar_t	*str;
	char	*newstr;

	str = va_arg(valist, wchar_t *);
	if (!str)
		str = L"(null)";
	newstr = conv_utf8_str(str);
	fmt->width = ft_strlen(newstr);
	return (newstr);
}

char			*flag_wchar(t_format *fmt, va_list valist)
{
	wchar_t	c;
	char	*newstr;

	c = va_arg(valist, wchar_t);
	newstr = conv_utf8_char(c, 0);
	fmt->width = ft_strlen(newstr);
	return (newstr);
}
