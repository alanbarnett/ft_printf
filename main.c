#include <stdio.h>
#include "libft.h"

int	main(void)
{
	//char	*str;
	int		i;

	//str = ft_strcpy(ft_strnew(21), "This is a test string");
	i = 126;
	//ft_printf("String: \"%s\"\nInt: %d\n", str, i);
	/*
	ft_printf("%010d", i);
	ft_putchar('\n');
	*/
	ft_printf("2d:    |%2d\n", i);
	ft_printf("-2d:   |%-2d\n", i);
	ft_printf("02d:   |%02d\n", i);
	ft_printf("+2d:   |%+2d\n", i);
	ft_printf("+07d:  |%+07d\n", i);
	ft_printf("10d:   |%10d\n", i);
	ft_printf("-10d:  |%-10d\n", i);
	ft_printf("-d:    |%-d\n", i);
	ft_printf("+d:    |%+d\n", i);
	ft_printf("+10d:  |%+10d\n", i);
	ft_printf("+010d: |%+010d\n", i);
	ft_printf("+-10d: |%+-10d\n", i);
	ft_putchar('\n');
	printf("2d:    |%2d\n", i);
	printf("-2d:   |%-2d\n", i);
	printf("02d:   |%02d\n", i);
	printf("+2d:   |%+2d\n", i);
	printf("+07d:  |%+07d\n", i);
	printf("10d:   |%10d\n", i);
	printf("-10d:  |%-10d\n", i);
	printf("-d:    |%-d\n", i);
	printf("+d:    |%+d\n", i);
	printf("+10d:  |%+10d\n", i);
	printf("+10d:  |%+10d\n", -i);
	printf("+010d: |%+010d\n", i);
	printf("+010d: |%+010d\n", -i);
	printf("+-10d: |%+-10d\n", i);
	/*
	*/
	return (0);
}
