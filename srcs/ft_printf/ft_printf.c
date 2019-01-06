/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 23:12:22 by abarnett          #+#    #+#             */
/*   Updated: 2019/01/06 00:12:44 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

/*
** Generate a linked list of substrings from format
** Combine them into a string
** Print and free the string
** Free the list
*/

int					ft_printf(const char *format, ...)
{
	va_list		valist;
	t_list		*strings;
	size_t		total_len;
	char		*combine;

	va_start(valist, format);
	strings = 0;
	total_len = make_list(&strings, format, valist);
	combine = combine_list(strings, total_len);
	write(1, combine, total_len);
	ft_lstdel(&strings, ft_lstmemdel);
	ft_strdel(&combine);
	va_end(valist);
	return (total_len);
}

/*
** Generate a linked list of substrings from format
** Combine them into one string
** Print it to a file descriptor
** Free the string and list
*/

int					ft_printfd(int fd, const char *format, ...)
{
	va_list		valist;
	t_list		*strings;
	size_t		total_len;
	char		*combine;

	va_start(valist, format);
	strings = 0;
	total_len = make_list(&strings, format, valist);
	combine = combine_list(strings, total_len);
	write(fd, combine, total_len);
	ft_lstdel(&strings, ft_lstmemdel);
	ft_strdel(&combine);
	va_end(valist);
	return (total_len);
}

/*
** Generate a linked list of substrings from format
** Combine them into the string that was passed
** Free the list
*/

int					ft_sprintf(char **str, const char *format, ...)
{
	va_list		valist;
	t_list		*strings;
	size_t		total_len;
	char		*combine;

	va_start(valist, format);
	strings = 0;
	total_len = make_list(&strings, format, valist);
	*str = combine_list(strings, total_len);
	ft_lstdel(&strings, ft_lstmemdel);
	va_end(valist);
	return (total_len);
}
