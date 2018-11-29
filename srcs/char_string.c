#include "libftprintf.h"
#include <stdio.h>

static void			print_params(t_format fmt_struct)
{
	printf("flags:	%x\n", fmt_struct.flags);
	printf("width:	%d\n", fmt_struct.width);
	printf("precis:	%d\n", fmt_struct.precision);
	printf("length:	%c\n", fmt_struct.length);
	printf("conv:	%d\n", fmt_struct.conv);
	printf("\n");
}

/*
** string came from strdup, guaranteed to be null terminated
** makes a new string that has been correctly cut
*/
static void			add_precision(int precision, char **str)
{
	int		len;
	char	*newstr;

	len = ft_strlen(*str);
	if (len > precision)
	{
		newstr = ft_strndup(*str, precision);
		*str = newstr;
	}
}

/*
static void			add_width(int width, char *str)
{

}
*/

char				*flag_char(t_format *fmt_struct, va_list valist)
{
	char	c;

	print_params(*fmt_struct);
	c = (char)va_arg(valist, int);
	if (!c)
		return (ft_strdup("^@"));
	return (ft_strdup(&c));
}

char				*flag_string(t_format *fmt_struct, va_list valist)
{
	char	*str;

	print_params(*fmt_struct);
	str = va_arg(valist, char *);
	if (!str)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	add_precision(fmt_struct->precision, &str);
	return (str);
}

char				*flag_int(t_format *fmt_struct, va_list valist)
{
	print_params(*fmt_struct);
	return (ft_itoa(va_arg(valist, int)));
}

char				*flag_percent(t_format *fmt_struct)
{
	print_params(*fmt_struct);
	return (ft_strdup("%"));
}
