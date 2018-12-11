/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan </var/spool/mail/alan>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:15:25 by alan              #+#    #+#             */
/*   Updated: 2018/12/10 19:54:29 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libftprintf.h"

int	main(void)
{
	//int		i;

	//i = 99;
	/*
	// normal tests
	ft_printf("Hello, World!\n");
	ft_printf("testing a %char\n", (char)i);
	ft_printf("i: %d\n", i);
	ft_printf("String: \"%s\"\nInt: %d\n", "stringy string", 1990);
	*/
	// tests with precision and width for strings
	ft_printf("Hello %.5s!\n", "world, and all it's inhabitants");
	ft_printf("Hello %.10s!\n", "world");
	ft_printf("10s:       |%10s|\n", "hello");
	ft_printf("10.3s:     |%10.3s|\n", "hello");
	ft_printf("10.9s:     |%10.9s|\n", "hello");
	ft_printf("1.9s:      |%1.9s|\n", "hello");
	ft_printf(".4s:       |%.4s|\n", "hello");
	ft_printf("10c:       |%10c|\n", 'h');
	ft_printf("10%%:       |%10%|\n");
	ft_printf("-10s:      |%-10s|\n", "hello");
	ft_printf("-10.3s:    |%-10.3s|\n", "hello");
	ft_printf("-10.9s:    |%-10.9s|\n", "hello");
	ft_printf("-1.9s:     |%.4s|\n", "hello");
	ft_printf("-.4s:      |%1.9s|\n", "hello");
	ft_printf("-10c:      |%-10c|\n", 'h');
	ft_printf("-10%%:      |%-10%|\n");
	// testing null strings && characters
	ft_printf("|%s|\n", 0);
	ft_printf("|%10s|\n", 0);
	ft_printf("|%10.2s|\n", 0);
	ft_printf("|%2.10s|\n", 0);
	ft_printf("|%.3s|\n", 0);
	ft_printf("|%.6s|\n", 0);
	ft_printf("|%10.2s|\n", "(null)");
	ft_printf("|%.3s|\n", "(null)");
	ft_printf("|%.6s|\n", "(null)");
	/*
	ft_putchar('\n');
	printf("|%s|\n", (char *)0);
	printf("|%10s|\n", (char *)0);
	printf("|%10.2s|\n", (char *)0);
	printf("|%2.10s|\n", (char *)0);
	printf("|%.3s|\n", (char *)0);
	printf("|%.6s|\n", (char *)0);
	ft_putchar('\n');
	*/
	ft_printf("|%c|\n", 0);
	ft_printf("|%10c|\n", 0);
	ft_printf("|%10.2c|\n", 0);
	ft_printf("|%2.10c|\n", 0);
	ft_printf("|%-c|\n", 0);
	ft_printf("|%-10c|\n", 0);
	ft_printf("|%-10.2c|\n", 0);
	ft_printf("|%-2.10c|\n", 0);
	/*
	// tests with precision and width for ints
	ft_printf("|%.5d|, 99\n", i);
	ft_printf("|%.0d|, 99\n", i);
	ft_printf("|%.d|, 0\n", 0);
	ft_printf("|%7.5d|, 99\n", i);
	ft_printf("|%7.0d|, 99\n", i);
	ft_printf("|%7.d|, 0\n", 0);
	ft_printf("|%-7.5d|, 99\n", i);
	ft_printf("|%0+7.5d|, 99\n", i);
	ft_printf("|% 07.0d|, 99\n", i);
	ft_printf("|%-07.d|, 0\n", 0);
	*/
	/*
	// testing 0 flag for ints
	ft_printf("|%08d|\n", i);
	ft_printf("|%02d|\n", i);
	ft_printf("|%01d|\n", i);
	ft_printf("|%08.5d|\n", i);
	ft_printf("|%-8.5d|\n", i);
	ft_printf("|%08.5d|\n", -i);
	ft_printf("|%-8.5d|\n", -i);
	ft_printf("|%8.9d|\n", -i);
	ft_printf("|%-8.9d|\n", i);
	ft_printf("|%02.d|\n", i);
	ft_printf("|%01.d|\n", 0);
	ft_printf("|%08d|\n", -i);
	ft_printf("|%08.5d|\n", -i);
	ft_printf("|%.5d|, 99\n", i);
	ft_printf("|%.0d|, 99\n", i);
	ft_printf("|%.d|, 0\n", 0);
	ft_printf("|%7.5d|, 99\n", i);
	ft_printf("|%7.0d|, 99\n", i);
	ft_printf("|%7.d|, 0\n", 0);
	ft_printf("|%-7.5d|, 99\n", i);
	ft_printf("|%0+7.5d|, 99\n", i);
	ft_printf("|% 07.0d|, 99\n", i);
	ft_printf("|%-07.d|, 0\n", 0);
	*/
	/*
	// testing lengths
	ft_printf("testing with %lld %hhd %ld %hd\n", i, i, i, i);
	*/
	/*
	// gross tests
	ft_printf("%%10% : |%10%|\n");
	*/

	/*
	// testing standard printf
	printf("%10.d\n", i);
	printf("%p\n", (void *)0);
	printf("%zD\n", (long)i);
	printf("%zO\n", (long)i);
	printf("%zU\n", (long)i);
	printf("%zo\n", 0xffffffffffffffff);
	printf("string: %10s\n", "hello");
	printf("%X\n", 12648430);
	printf("@moulitest: %s\n", NULL);
	printf("%U\n", 4294967296);
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
	printf("% x\n", 0xC0FFEE);
	printf("int: %d, percent: |%5%\n", i);
	printf("%lu\n", sizeof(signed char));
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
	*/

	//ft_printf("int: %+015.7d, int2: %-0015.8d, testing some %5% shits % %\n", i, 17);
	//ft_printf("%# 05.3d %.d %d %d gg!\n", 1, -2, 33, 42);

	// versus test with width, precision, and -+ 0 flags
	/*
	ft_printf("3d:      |%3d|\n", 42890);
	ft_printf("3d:      |%3d|\n", -42890);
	ft_printf("2d:      |%2d|\n", i);
	ft_printf("-2d:     |%-2d|\n", i);
	ft_printf("02d:     |%02d|\n", i);
	ft_printf("+2d:     |%+2d|\n", i);
	ft_printf(".4d:     |%.4d|\n", i);
	ft_printf("-.4d:    |%-.4d|\n", i);
	ft_printf("+.4d:    |%+.4d|\n", i);
	ft_printf("+.4d:    |%+.4d|\n", -i);
	ft_printf("+07d:    |%+07d|\n", i);
	ft_printf("10d:     |%10d|\n", i);
	ft_printf("-10d:    |%-10d|\n", i);
	ft_printf("-d:      |%-d|\n", i);
	ft_printf("+d:      |%+d|\n", i);
	ft_printf("+10d:    |%+10d|\n", i);
	ft_printf("+10d:    |%+10d|\n", -i);
	ft_printf("+010d:   |%+010d|\n", i);
	ft_printf("+010d:   |%+010d|\n", -i);
	ft_printf("+-10d:   |%+-10d|\n", i);
	ft_printf("-10.4d:  |%-10.4d|\n", i);
	ft_printf("10.4d:   |%10.4d|\n", i);
	ft_printf("-10.4d:  |%-10.4d|\n", -i);
	ft_printf("10.4d:   |%10.4d|\n", -i);
	ft_printf("-010.4d: |%-10.4d|\n", i);
	ft_printf("+10.4d:  |%10.4d|\n", i);
	ft_printf("-010.4d: |%-10.4d|\n", -i);
	ft_printf("010.4d:  |%10.4d|\n", -i);
	ft_putchar('\n');
	printf("3d:      |%3d|\n", 42890);
	printf("3d:      |%3d|\n", -42890);
	printf("2d:      |%2d|\n", i);
	printf("-2d:     |%-2d|\n", i);
	printf("02d:     |%02d|\n", i);
	printf("+2d:     |%+2d|\n", i);
	printf(".4d:     |%.4d|\n", i);
	printf("-.4d:    |%-.4d|\n", i);
	printf("+.4d:    |%+.4d|\n", i);
	printf("+.4d:    |%+.4d|\n", -i);
	printf("+07d:    |%+07d|\n", i);
	printf("10d:     |%10d|\n", i);
	printf("-10d:    |%-10d|\n", i);
	printf("-d:      |%-d|\n", i);
	printf("+d:      |%+d|\n", i);
	printf("+10d:    |%+10d|\n", i);
	printf("+10d:    |%+10d|\n", -i);
	printf("+010d:   |%+010d|\n", i);
	printf("+010d:   |%+010d|\n", -i);
	printf("+-10d:   |%+-10d|\n", i);
	printf("-10.4d:  |%-10.4d|\n", i);
	printf("10.4d:   |%10.4d|\n", i);
	printf("-10.4d:  |%-10.4d|\n", -i);
	printf("10.4d:   |%10.4d|\n", -i);
	printf("-010.4d: |%-10.4d|\n", i);
	printf("+10.4d:  |%10.4d|\n", i);
	printf("-010.4d: |%-10.4d|\n", -i);
	printf("010.4d:  |%10.4d|\n", -i);
	*/

	/*
	// Tests with precision less than number length
	ft_printf("%.2d\n", 4242);
	ft_printf("%.d\n", 4242);
	ft_printf("%+.2d\n", 4242);
	ft_printf("%+.d\n", 4242);
	ft_printf("%-.2d\n", 4242);
	ft_printf("%-.d\n", 4242);
	ft_printf("%0.2d\n", 4242);
	ft_printf("%0.d\n", 4242);
	*/

	/*
	// Tests with other sizes
	ft_printf("%hhd\n", 128);
	ft_printf("%ld\n", 2147483648);
	ft_printf("%lld\n", 9223372036854775807);
	*/
	return (0);
}
