/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 21:30:54 by abarnett          #+#    #+#             */
/*   Updated: 2018/12/14 19:01:08 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*flag_pointer(t_format *fmt, va_list valist)
{
	(void)valist;
	(void)fmt;
	return (ft_strdup("flag_pointer"));
}
