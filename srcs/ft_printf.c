#include <stdarg.h>
#include <stdio.h>
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

char				*flag_string(va_list valist)
{
	return (va_arg(valist, char *));
}

char				*flag_int(va_list valist)
{
	return (ft_itoa(va_arg(valist, int)));
}

/*
**	The position of the characters in the flags string represent
**	the index of their function in the function pointer array.
**	If you would like to add a new function with a new character,
**		add your function to the srcs/ directory,
**		add the character to the end of the list,
**		increase the jump table index count,
**		add your function name to the jump table.
*/
int					conversion_chars(char **format)
{
	const char	*flags;

	flags = "sSpdDioOuUxXcC";
	if (ft_strchr(flags, **format))
		return (ft_strchr(flags, **format) - flags);
	return (-1);
}

int					field_width(char **format)
{
	int		width;

	width = -1;
	if (ft_isdigit(**format))
	{
		width = ft_atoi(*format);
		*format += ft_numlen(width);
	}
	return (width);
}

/*
**	The position of the characters in the flags string represent
**	the index of their bit in the ret variable.
**	To add new flags,
**		add the flag character to the end of the flags string
**			(make sure the type of ret is big enough to hold that many bits)
**		make some shit to deal with that bit in the parse function
*/
int					flag_chars(char **format)
{
	const char	*flags;
	int			ret;

	flags = "#0-+ ";
	ret = 0;
	while (ft_strchr(flags, **format))
	{
		ret = ret | (1 << (ft_strchr(flags, **format) - flags));
		(*format)++;
	}
	ret = ((ret & 0x6) == 0x6 ? (ret ^ 0x2) : ret);
	return (ret);
}

static char			*parse(const char **format, va_list valist)
{
	char		*fmt_str;
	char		*conv;
	int			flags;
	int			width;
	static char	*(*p[14])();
	
	p[0] = flag_string;
	p[3] = flag_int;
	p[5] = flag_int;

	fmt_str = (char *)format;
	/*
	**	Maybe make a jump table for flags
	**	send it the width so it can make the output string
	**	send it the conversion so it can format it
	**	maybe make the flags a final stage for formatting?
	*/
	flags = flag_chars(&fmt_str);
	width = field_width(&fmt_str);
	conv = p[conversion_chars(&fmt_str)](valist);
	if (width > (int)ft_strlen(conv))
	{
		fmt_str = ft_memset(ft_strnew(width),		\
					((flags & 0x2) ? '0' : ' '),	\
					width);
		if (flags & 0x4)
		{
			if (flags & 0x8 && ft_isdigit(*conv))
			{
				*fmt_str = '+';
				ft_memcpy(fmt_str + 1, conv, ft_strlen(conv));
			}
			else
				ft_memcpy(fmt_str, conv, ft_strlen(conv));
		}
		else
		{
			ft_memcpy(fmt_str + (width - ft_strlen(conv)), conv, ft_strlen(conv));
			if (flags & 0x8 && ft_isdigit(*conv))
				*(fmt_str + ((flags & 0x2) ? 0 : (width - ft_strlen(conv) - 1))) = '+';
		}
		ft_strdel(&conv);
		conv = fmt_str;
	}
	else if (flags & 0x8 && ft_isdigit(*conv))
	{
		fmt_str = ft_strnew(ft_strlen(conv) + 1);
		*fmt_str = '+';
		ft_memcpy(fmt_str + 1, conv, ft_strlen(conv));
		ft_strdel(&conv);
		conv = fmt_str;
	}
	return (conv);
}

void				ft_printf(const char *format, ...)
{
	va_list		valist;
	char		*p_str;

	va_start(valist, format);
	while ((p_str = ft_strchr(format, '%')))
	{
		write(1, format, p_str - format);
		p_str = parse(&format, valist);
		ft_putstr(p_str);
		//ft_strdel(&p_str);
	}
}
