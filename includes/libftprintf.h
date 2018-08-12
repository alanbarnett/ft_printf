/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:47:21 by abarnett          #+#    #+#             */
/*   Updated: 2018/08/12 15:19:14 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

char				*flag_string(va_list valist);
char				*flag_int(va_list valist);
int					conversion_launcher(char flag);
static char			*parse(char **format, va_list valist);
void				ft_printf(const char *format, ...);

#endif
