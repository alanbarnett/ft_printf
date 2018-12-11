#include "libftprintf.h"

/*
** string came from strdup, guaranteed to be null terminated
** makes a new string that has been correctly cut
*/
/*
static void			add_precision(int precision, char **str)
{
	int		len;
	char	*newstr;

	len = ft_strlen(*str);
	if ((precision != -1) && len > precision)
	{
		newstr = ft_strndup(*str, precision);
		ft_strdel(str);
		*str = newstr;
	}
}
*/

static void			add_width(int width, char **str, int is_left)
{
	int		len;
	char	*newstr;

	len = ft_strlen(*str);
	if (width > len)
	{
		newstr = ft_nmemset(ft_strnew(width), ' ', width);
		if (is_left)
			ft_strncpy(newstr, *str, len);
		else
			ft_strncpy(newstr + (width - len), *str, len);
		ft_strdel(str);
		*str = newstr;
	}
}

/*
** This function sets the width to the full size of the string, and the
** precision to the size of the substring inside.
**
** It takes the length of the string to compare, and the format struct for
** access to precision and width
*/
static char			*format_string(t_format *fmt, int len)
{
	if (fmt->precision != -1)
	{
		if (fmt->precision > len)
			fmt->precision = len;
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

char				*flag_char(t_format *fmt, va_list valist)
{
	char	c;
	char	*str;

	//print_params(*fmt);
	c = (char)va_arg(valist, int);
	if (!c)
		str = ft_strdup("^@");
	str = ft_strndup(&c, 1);
	add_width(fmt->width, &str, (fmt->flags & MINUS));
	return (str);
}

char				*flag_string(t_format *fmt, va_list valist)
{
	char	*str;
	char	*newstr;
	int		len;

	//print_params(*fmt);
	str = va_arg(valist, char *);
	if (!str)
	{
		str = "(null)";
		len = 6;
	}
	else
		len = ft_strlen(str);
	newstr = format_string(fmt, len);
	if (fmt->flags & MINUS)
		ft_strncpy(newstr, str, fmt->precision);
	else
		ft_strncpy(newstr + fmt->width - fmt->precision, str, fmt->precision);
	return (newstr);
}

char				*flag_percent(t_format *fmt)
{
	char	*str;

	//print_params(*fmt);
	str = ft_strdup("%");
	add_width(fmt->width, &str, (fmt->flags & MINUS));
	return (str);
}
