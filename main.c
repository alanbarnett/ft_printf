#include <stdio.h>
#include "libft.h"

int	main(void)
{
	//char	*str;
	int		i;

	//str = ft_strcpy(ft_strnew(21), "This is a test string");
	i = 126;
	ft_printf("int: %d, int2: %d, testing some %5% shits % %\n", i, 17);
	ft_printf("%d %d %d %d gg!\n", 1, -2, 33, 42);
	printf("string: %10s\n", "hello");
	printf("%X\n", 12648430);
	printf("@moulitest: %s\n", NULL);
	//printf("%U\n", 4294967296);
	printf("%hd\n", (short)32768);
	printf("%hd\n", (short)-32769);
	printf("%hhd\n", (char)-129);
	printf("%     000005d\n", 42);
	printf("% 05d\n", -42);
	printf("%10.6d\n", 135);
	printf("%#010x\n", 0x135);
	printf("%#10x\n", 0x135);
	printf("%-10.5s\n", "hello, world!");
	printf("%012.7f\n", 2.2843);
	printf("%012.6d\n", 224);
	printf("%012.6d\n", -224);
	printf("%12.6d\n", 224);
	printf("%12.6d\n", -224);
	//printf("% x\n", 0xC0FFEE);
	printf("int: %d, percent: |%5%\n", i);
	//printf("%lu\n", sizeof(signed char));
	printf("%-6d\n", i);
	printf("%+-6d\n", i);
	printf("%06d\n", i);
	printf("% 06d\n", i);
	printf("%+06d\n", i);
	printf("%-6d\n", -i);
	printf("%+-6d\n", -i);
	printf("%06d\n", -i);
	printf("% 06d\n", -i);
	printf("%+06d\n", -i);
	printf("%lu\n", 299999999UL);
	printf("% 010d\n", 135);
	
	//ft_printf("String: \"%s\"\nInt: %d\n", str, i);
	/*
	ft_printf("%010d", i);
	ft_putchar('\n');

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
	*/
	/*
	*/
	return (0);
}
