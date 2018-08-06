#include <stdarg.h>
#include "libft.h"
#include "libftprintf.h"

/*
** Must include:
** 	conversions:	sSpdDioOuUxXcC
**	must manage:	%%
**	flags:			#0-+ (and ' ');
**	must manage:	minimum field-width and precision
**	flags:			hh, h, l, ll, j, z
**
** Bonuses include:
**	conversions:	eE, fF, gG, aA, n
**	flags:			*, %, L, '
**	new flags:
**		%b:		binary
**		%r:		non-printable characters
**		%k:		date in ISO format
**	colors, fd, etc..
*/

void				flag_string(va_list valist)
{
	ft_putstr(va_arg(valist, char *));
}

void				flag_int(va_list valist)
{
	ft_putnbr(va_arg(valist, int));
}

int					flag_launcher(char flag)
{
	char	flags[10];
	int		i;

	flags[0] = 's';
	flags[1] = 'd';
	i = 0;
	while (i < 2)
	{
		if (flags[i] == flag)
			return (i);
		++i;
	}
	return (-1);
}

static char			*parse(const char *format)
{
	char	*loc;

	if (!(loc = ft_strchr(format, '%')))
		return (0);
	return (loc + 1);
}

void				ft_printf(const char *format, ...)
{
	va_list		valist;
	static void	(*p[10])();
	char		*ret;
	char		*prev;

	va_start(valist, format);
	p[0] = flag_string;
	p[1] = flag_int;

	prev = (char *)format;
	ret = parse(prev);

	while (ret)
	{	
		write(1, prev, (ret - prev) - 1);
		/*
		** Instead of this, set up a thing to take the position after
		** the % and the valist, and then make the string to print
		*/
		p[flag_launcher(*ret)](valist);
		prev = ret + 1;
		ret = parse(ret);
	}
	write(1, prev, ft_strlen(prev));
}
