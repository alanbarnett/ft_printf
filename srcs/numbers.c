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
	if (precision > len)
	{
		newstr = ft_strinit(precision, '0');
		ft_strncpy(newstr + (precision - len), *str, len);
		ft_strdel(str);
		*str = newstr;
	}
}
*/

/*
** makes a new string
** copies into the right or left side of the new string
** sets old string to new string
*/
/*
static void			add_width(int width, char **str, int is_left)
{
	int		len;
	char	*newstr;

	len = ft_strlen(*str);
	if (width > len)
	{
		newstr = ft_strinit(width, ' ');
		if (is_left)
			ft_strncpy(newstr, *str, len);
		else
			ft_strncpy(newstr + (width - len), *str, len);
		ft_strdel(str);
		*str = newstr;
	}
}
*/

/*
// look for ZERO, PLUS, and SPACE
static void			add_flags(unsigned char flags, int p, int nb, char **str)
{
	char	*cur;

	cur = *str;
	if ((flags & ZERO) && (p == -1))
	{
		if (nb < 0)
		{
			*cur++ = '-';
			while (cur && (*cur == ' ' || *cur == '-'))
				*cur++ = '0';
		}
		else
			while (cur && *cur == ' ')
				*cur++ = '0';
	}
}
*/

/*
** function to replace spaces (and the first -, if the number is negative) with
** zeros. also adds a leading - if the number is negative.
** will also work with a +, if sent the pos flag.
** if (cur && *cur) avoid the chance that I send str on top of (or after) a null
** before immediately writing a -
*/
/*
static void			add_zeros(int nb, int pos, char **str)
{
	char	*cur;

	cur = *str;
	if (cur && *cur && nb < 0)
	{
		*cur++ = '-';
		while (cur && *cur == ' ')
			*cur++ = '0';
		if (cur && *cur == '-')
			*cur = '0';
	}
	else
	{
		if (cur && *cur && pos)
			*cur++ = '+';
		while (cur && *cur == ' ')
			*cur++ = '0';
		if (cur && *cur == '+' && pos)
			*cur = '0';
	}
}
*/

/*
static void			p_w_zeros(int p, int w, int zeros, int nb, char **str)
{
	char	*newstr;
	int		len;

	len = ft_strlen(*str);
	if (len >= ft_abs(w) && len >= p)
		return ;
	//	make a new string with the max value (including -width for left)
	newstr = ft_strinit(ft_vamax(2, (int)ft_abs(w), p), ' ');
	// newstr is now full of spaces, at the max size after w and p
	//	w will never be greater than p if it is negative and p == -1
	//	this branch will only happen when there is a positive w that is larger
	//		than p, and len is smaller than it
	//	which is to say
	//	this branch only happens when the number is right justified
	//	and when there may or may not be zeros before it
	//	which may or may not go all the way to the left
	if (w > p)
	{
		// copies into the right side from the length of the number
		ft_strncpy(newstr + (w - len), *str, len);
		// newstr is now made of spaces, with the number on the right side
		// if zeros need to happen
		//		only when p doesn't exist
		//		if it does then fuck
		if (zeros && p == -1)
			add_zeros(nb, &newstr);
		if (p != -1)
			add_zeros(nb, &(newstr + (w - p)));
	}
	else
	{
		if (p == -1)
		{
			ft_strncpy(newstr, *str, len);
		}
		else if (p > len)
		{
			// in this case, precision is the full length of the string
			// this is the same as width with zeros
			// in other words, the easiest case
			ft_strncpy(newstr + (p - len), *str, len);
		}
		add_zeros(nb, &newstr);
	}
	ft_strdel(str);
	*str = newstr;
}
*/
/*
static void			p_w_zeros(int p, int w, int flags, int nb, char **str)
{
	char	*newstr;
	int		len;

	len = ft_strlen(*str);
	if (len >= w && len >= p)
		return ;
	newstr = ft_strinit(ft_max(w, p), ' ');
	if (w > 0)
	{
		ft_strncpy(newstr + (w - len), *str, len);
		if (zeros && p == -1)
			add_zeros(nb, &newstr);
		if (p != -1)
			add_zeros(nb, &(newstr + (w - p)));
	}
	else
	{
		if (p == -1)
			ft_strncpy(newstr, *str, len);
		else if (p > len)
			ft_strncpy(newstr + (p - len), *str, len);
		add_zeros(nb, &newstr);
	}
	ft_strdel(str);
	*str = newstr;
}
*/

/*
** static char			*stresize(char **buf, int start, size_t size)
** {
** 	char	*new;
** 
** 	new = ft_strnew(ft_strlen(*buf + start) + size);
** 	if (!new)
** 		return (0);
** 	new = ft_strncpy(new, *buf + start, ft_strlen(*buf + start));
** 	ft_strdel(buf);
** 	return (new);
** }
*/

/*
** this function does the following
** makes the length of the string I'll need
**	width should be the full size of the string
**	precision should be the size of the substring inside
**		including zeros, and the sign, and the length of the number
**	len is the length of the number
**		will be used for my itoa function that doesn't make new memory
** if I have enough space, running through the formatting functions
**		precision, width, zeros, sign
**
** do I need a zeros flag?
**	can use precision value for zeros
**	if zeros is set, precision is set to width
**	cases where zeros isn't set:
**		when we have a specific precision
**			handled normally with precision
**		when we don't want zeros
**			can be taken care of by -1 precision
**	the answer is no
*/
/*
** If width is largest, nothing happens
** If len is larger than width, set width to len
**		this avoids a width that's too small, which has no effect.
** If precision is larger than width, set width to precision
**		precision has higher precedence than width
** If either precision or width are smaller than len
**		they have no effect
** Overall, this sets the width to the maximum size of the new string
**
** there are six cases
**
** len > width > precision && len > precision > width
**	precision does not truncate
**		less than len, can be ignored
**	width does not truncate
**		less than len, can be ignored
**	overall length is len
**	edge cases
**		precision is 0
**			if number is 0, len is 0
**
** width > len > precision
**	there will be empty space if width is bigger than len
**	precision has no effect less than the number
**	overall length is width
**	edge cases
**		precision is 0
**			if number is 0, len is 0
** width > precision > len
**	width will cause empty space bigger than the number and precision
**	precision bigger than the number causes zeros
**	overall length is width, precision is still important
**
** precision > len > width && precision > width > len
**	width ignored, precision bigger than len so there will be zeros
**	overall length is precision
**		identical to width, no precision, and zeros
*/
static char			*format_nb(t_format *fmt, int nb)
{
	int		len;
	char	*str;

	len = ft_numlen(nb);
	/*
	** subtracts one from number length if the number is negative
	** this ignores the sign for now, it will be considered again later
	** this could be resolved by making a numlen that ignores the sign
	** or making an abs that doesn't overflow with big input
	** no i'll just do this
	*/
	len = ((nb < 0) ? (len - 1) : len);
	/*
	** sets len to 0 if precision is 0 and the number is 0
	** len will be used to make the section of the string for my number
	*/
	if (fmt->precision == 0 && nb == 0)
		len = 0;
	/*
	**	precision needs to be done first
	**	if it is supplied, and the width is less than that,
	**		set width to precision
	**		if there's a sign, increase width to fit the sign
	**	if precision is not supplied
	**		do width
	**			set it to the length of the number w/o sign, if it's less
	**		set precision to width if zeros
	**			if there's a sign, increase width to hold it
	*/
	if (fmt->precision != -1)
	{
		if ((fmt->flags & (PLUS | SPACE)) || nb < 0)
			++fmt->precision;
		if (fmt->precision > fmt->width)
			fmt->width = fmt->precision;
	}
	else
	{
		// len without sign
		fmt->width = ft_max(fmt->width, len);
		// increases width for a sign
		if (((fmt->flags & (PLUS | SPACE)) || nb < 0) && fmt->width == len)
			++fmt->width;
		// sets precision to width for zeros
		if (fmt->flags & ZERO)
			fmt->precision = fmt->width;
	}
	/*
	** new
	** separator
	** old
	*/
	// Overall, this sets the width to the maximum size of the new string
	//fmt->width = ft_vamax(3, fmt->width, fmt->precision, len);
	// increases width to fit the sign if it won't fit
	// if (fmt->width == len && ((fmt->flags & (PLUS | SPACE)) || nb < 0))
	// 	++fmt->width;
	// If no precision, and zeros, set precision to width
	// this sets the size of the zero filling
	// if (fmt->precision == -1 && (fmt->flags & ZERO))
	// {
	// 	fmt->precision = fmt->width;
	// 	/*
	// 	** checks if precision needs to be smaller for the sign
	// 	*/
	// 	if ((fmt->flags & (PLUS | SPACE)) || nb > 0)
	// 		--fmt->precision;
	// }
	/*
	** negating precision if it doesn't matter anyway
	** I don't think this is necessary
	**   it will only be necessary if whatever function I have to handle
	**   precision cares whether or not it's less than len
	**   if it can ignore that, then this can go
	** for now I'm making this an else if
	*/
	// else if (fmt->precision < len)
	// 	fmt->precision = -1;
	/*
	** above two statements explained:
	** first we check if there is no precision, and zeros is set
	**	if true, we set precision to the width, as precision will mark the zeros
	** else, if precision is less than length,
	**	then it has been set, and so there should be no zeros
	**	but also, it won't do anything, as it's less than the length of the num
	**	so we set it to -1, because it doesn't matter and can be ignored
	*/
	/*
	** When do we need the sign
	**	when it has a plus or a space, and the number is positive
	**	when the number is negative
	** When do we need to add space for the sign
	**	when it can't fit in width
	** when width and precision are equal,
	**	add to width, because sign is outside precision
	** when width is less than precision
	**	won't happen here, width should be equal to the total size here
	**
	** The important part:
	** if width and precision are the same, increase width
	** if they are not, don't bother because:
	**	precision of the number + sign = width or less
	*/
	/*
	** if (((fmt->flags & (PLUS | SPACE)) && nb > 0) || (nb < 0))
	** {
	** 	if (fmt->width == fmt->precision)
	** 		--fmt->precision;
	** 	if (fmt->width == len)
	** 		++fmt->width;
	** }
	*/


	// Here, width is set to max length
	//	includes a sign
	// precision is set to the size of the zeros
	//	set to -1 if there are none

	// string with length of width
	str = ft_strinit(fmt->width, ' ');
	ft_putstr("w: ");
	ft_putnbr(fmt->width);
	ft_putstr(", p: ");
	ft_putnbr(fmt->precision);
	ft_putstr(", l: ");
	ft_putnbr(len);
	ft_putstr("	");
	return (str);
}
/*
** width, precision, zeros
** it can have a width and a precision
** it can have a width and zeros
** it cannot have zeros and precision
** it can have only width
** it can have only preicision
** it cannot have only zeros
**
** width and precision is width outside zeros
** width and zeros is the same thing as precision
**
** precision greater than width is just width with zeros
**
** width on the left
**	works with precision just the same
**	just on the other side
**	doesn't work with zeros
*/

char				*flag_int(t_format *fmt_struct, va_list valist)
{
	char	*str;
	int		nb;

	//print_params(*fmt_struct);
	nb = va_arg(valist, int);
	/*
	if (nb == 0 && fmt_struct->precision == 0)
		str = ft_strdup("");
	else
		str = ft_itoa(nb);
		*/
	str = format_nb(fmt_struct, nb);
	/*
	p_w_zeros(fmt_struct->precision,\
			fmt_struct->width * ((fmt_struct->flags & MINUS) ? -1 : 1),\
			(fmt_struct->flags & ZERO), nb, &str);
			*/
	//add_width(fmt_struct->width, &str, (fmt_struct->flags & MINUS));
	//add_flags(fmt_struct->flags, fmt_struct->precision, nb, &str);
	return (str);
}
