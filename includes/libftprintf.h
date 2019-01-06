/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:47:21 by abarnett          #+#    #+#             */
/*   Updated: 2019/01/06 00:12:41 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft.h"

# define SHARP 0x1
# define ZERO 0x2
# define MINUS 0x4
# define PLUS 0x8
# define SPACE 0x10

# define CONVS "cCsS%dDiuUboOxXpfFeE"

typedef struct		s_format
{
	unsigned char	flags;
	int				width;
	int				precision;
	char			length;
	char			conv;
}					t_format;

/*
** function pointer functions
*/

char				*flag_char(t_format *fmt, va_list valist);
char				*flag_wchar(t_format *fmt, va_list valist);
char				*flag_string(t_format *fmt, va_list valist);
char				*flag_wstr(t_format *fmt, va_list valist);
char				*flag_percent(t_format *fmt);
char				*flag_int(t_format *fmt, va_list valist);
char				*flag_uint(t_format *fmt, va_list valist);
char				*flag_bin(t_format *fmt, va_list valist);
char				*flag_oct(t_format *fmt, va_list valist);
char				*flag_hex(t_format *fmt, va_list valist);
char				*flag_pointer(t_format *fmt, va_list valist);
char				*flag_float(t_format *fmt, va_list valist);
char				*flag_scientific(t_format *fmt, va_list valist);

/*
** parse functions
*/

int					get_conversion(const char **format, t_format *fmt_struct);
void				get_length(const char **format, t_format *fmt_struct);
void				get_width_precis(const char **format, t_format *fmt_struct);
void				get_flags(const char **format, t_format *fmt_struct);

/*
** make list functions
*/

size_t				make_list(t_list **list, const char *format,
							va_list valist);
char				*combine_list(t_list *list, int size_of_list);

/*
** printf functions
*/

int					ft_printf(const char *format, ...);
int					ft_printfd(int fd, const char *format, ...);
int					ft_sprintf(char **str, const char *format, ...);

#endif
