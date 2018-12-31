/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan </var/spool/mail/alan>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:15:25 by alan              #+#    #+#             */
/*   Updated: 2018/12/31 06:04:54 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include "libftprintf.h"

int	main(void)
{
	/*
	int		i;

	i = 99;
	// normal tests
	ft_printf("Hello, World!\n");
	ft_printf("testing a %char\n", (char)i);
	ft_printf("i: %d\n", i);
	ft_printf("String: \"%s\"\nInt: %d\n", "stringy string", 1990);
	ft_printf("%d %ld %lld\n", 123, 1234, 12345);
	ft_printf("int: %+015.7d, int2: %-0015.8d, testing some %5% shits % %\n", i, 17);
	ft_printf("%# 05.3d %.d %d %d gg!\n", 1, -2, 33, 42);
	*/
	/*
	// poop tests
	ft_printf("%.0d\n", 0);
	ft_printf("|%.-3d|\n", 0);
	printf("%.0d\n", 0);
	printf("%.-3d\n", 0);
	*/
	/*
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
	ft_putchar('\n');
	printf("|%s|\n", (char *)0);
	printf("|%10s|\n", (char *)0);
	printf("|%10.2s|\n", (char *)0);
	printf("|%2.10s|\n", (char *)0);
	printf("|%.3s|\n", (char *)0);
	printf("|%.6s|\n", (char *)0);
	ft_putchar('\n');
	ft_printf("|%c|\n", 0);
	ft_printf("|%10c|\n", 0);
	ft_printf("|%10.2c|\n", 0);
	ft_printf("|%2.10c|\n", 0);
	ft_printf("|%-c|\n", 0);
	ft_printf("|%-10c|\n", 0);
	ft_printf("|%-10.2c|\n", 0);
	ft_printf("|%-2.10c|\n", 0);
	*/
	/*
	// tests with precision and width for ints
	ft_printf("|%.5u|, 99\n", i);
	ft_printf("|%.0u|, 99\n", i);
	ft_printf("|%.u|, 0\n", 0);
	ft_printf("|%7.5u|, 99\n", i);
	ft_printf("|%7.0u|, 99\n", i);
	ft_printf("|%7.u|, 0\n", 0);
	ft_printf("|%-7.5u|, 99\n", i);
	ft_printf("|%0+7.5u|, 99\n", i);
	ft_printf("|% 07.0u|, 99\n", i);
	ft_putchar('\n');
	ft_printf("|%-07.u|, 0\n", 0);
	ft_printf("|%-07.d|, 0\n", 0);
	ft_printf("|%+07.d|, 0\n", 0);
	ft_printf("|%-+07.d|, 0\n", 0);
	ft_printf("|% 07.d|, 0\n", 0);
	*/
	/*
	printf("|%-07.u|, 0\n", 0);
	printf("|%-07.d|, 0\n", 0);
	printf("|%+07.d|, 0\n", 0);
	printf("|%-+07.d|, 0\n", 0);
	printf("|% 07.d|, 0\n", 0);
	ft_putchar('\n');
	*/
	/*
	// testing 0 flag for ints
	ft_printf("|%08u|\n", i);
	ft_printf("|%02u|\n", i);
	ft_printf("|%01u|\n", i);
	ft_printf("|%08.5u|\n", i);
	ft_printf("|%-8.5u|\n", i);
	ft_printf("|%08.5u|\n", -i);
	ft_printf("|%-8.5u|\n", -i);
	ft_printf("|%8.9u|\n", -i);
	ft_printf("|%-8.9u|\n", i);
	ft_printf("|%02.u|\n", i);
	ft_printf("|%01.u|\n", 0);
	ft_printf("|%08u|\n", -i);
	ft_printf("|%08.5u|\n", -i);
	ft_printf("|%.5u|, 99\n", i);
	ft_printf("|%.0u|, 99\n", i);
	ft_printf("|%.u|, 0\n", 0);
	ft_printf("|%7.5u|, 99\n", i);
	ft_printf("|%7.0u|, 99\n", i);
	ft_printf("|%7.u|, 0\n", 0);
	ft_printf("|%-7.5u|, 99\n", i);
	ft_printf("|%0+7.5u|, 99\n", i);
	ft_printf("|% 07.0u|, 99\n", i);
	ft_printf("|%-07.u|, 0\n", 0);
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
	//ft_printf("%d\n", 1001);
	// testing U
	//ft_printf("|%hU|\n", 4294967296);
	// ft_printf("%o\n", 255);
	// ft_printf("%O\n", 255);
	// ft_printf("%#o\n", 0);
	// ft_printf("%#O\n", 0);
	// ft_printf("");
	// ft_printf("%x\n", 255);
	// ft_printf("%X\n", 255);
	// ft_printf("%#x\n", 0);
	// ft_printf("%#X\n", 0);
	// ft_printf("%#x\n", 255);
	// ft_printf("%#X\n", 158);
	// ft_printf("%#05x\n", 255);
	// ft_printf("%#05X\n", 158);
	// ft_printf("%#6o\n", 2500);
	// ft_printf("%-#6o\n", 2500);
	// ft_printf("@moulitest: |%#.o %#.0o|\n", 0, 0);
	// ft_printf("%-#10.o\n", 250);
	// ft_printf("%-#10.o\n", 0);
	// */
/*
**	ft_printf("%#-5.o\n", 0);
**	ft_printf("%#5.o\n", 0);
**	ft_printf("%o\t%#o\t%.o\t%#.o\t%#.4o\n", 0, 0, 0, 0, 0);
**	ft_printf("%o\t%#o\t%.o\t%#.o\t%#6.4o\n", 7, 7, 7, 7, 7);
**	ft_printf("%o\t%#o\t%.o\t%#.o\t%#.4o\n", 8, 8, 8, 8, 512);
**	ft_printf("%o\t%#o\t%.o\t%#.o\t%#.2o\n", 8, 8, 8, 8, 512);
**	ft_printf("\n");
**	ft_printf("%d\t%+d\t%.d\t%+.d\t%+.4d\n", 0, 0, 0, 0, 0);
**	ft_printf("%d\t%+d\t%.d\t%+.d\t%+.4d\n", 7, 7, 7, 7, 7);
**	ft_printf("%d\t%+d\t%.d\t%+.d\t%+.4d\n", 8, 8, 8, 8, 8);
**	ft_printf("\n");
**	ft_printf("%x\t%#x\t%.x\t%#.x\t%#.4x\n", 0, 0, 0, 0, 0);
**	ft_printf("%x\t%#x\t%.x\t%#.x\t%#.4x\n", 7, 7, 7, 7, 7);
**	ft_printf("%x\t%#x\t%.x\t%#.x\t%#.4x\n", 8, 8, 8, 8, 8);
**	ft_printf("\n");
*/
	/*
	// Pointer tests
	int pointer;

	pointer = 9;
	ft_printf("%p: %d\n", &pointer, pointer);
	printf("%p: %d\n", &pointer, pointer);
	*/
	/*
	// large int/fraction tests
	ft_printf("\nlarge int/fraction tests\n");
	ft_printf("ft_printf:\n");
	ft_printf("%lf\n", 123456789123456789123456789.123456789123456789123456789);
	ft_printf("%lf\n", 123456789123456789.625);
	ft_printf("%lf\n", 12345678912345678912345.123456789);
	ft_printf("%lf\n", 123456789.123456789);
	ft_printf("%lf\n", 1234567891234567.89);
	ft_printf("%lf\n", 123456789123456.789);
	ft_printf("\nprintf:\n");
	printf("%lf\n", 123456789123456789123456789.123456789123456789123456789);
	printf("%lf\n", 123456789123456789.625);
	printf("%lf\n", 12345678912345678912345.123456789);
	printf("%lf\n", 123456789.123456789);
	printf("%lf\n", 1234567891234567.89);
	printf("%lf\n", 123456789123456.789);
	// Big tests
	ft_printf("\nBig tests\n");
	ft_printf("\nft_printf:\n");
	ft_printf("%lf\n\n", 1e300);
	ft_printf("%lf\n\n", 1e247);
	ft_printf("%lf\n\n", 1e200);
	ft_printf("%lf\n\n", 1e100);
	ft_printf("%lf\n\n", 1e50);
	ft_printf("%lf\n\n", 1e24);
	ft_printf("%lf\n\n", 1e3);
	ft_printf("\nprintf:\n");
	printf("%lf\n\n", 1e300);
	printf("%lf\n\n", 1e247);
	printf("%lf\n\n", 1e200);
	printf("%lf\n\n", 1e100);
	printf("%lf\n\n", 1e50);
	printf("%lf\n\n", 1e24);
	printf("%lf\n\n", 1e3);
	// Trailing zeros
	ft_printf("\nTrailing zeros tests\n");
	ft_printf("\nft_printf:\n");
	ft_printf("%.25lf\n", 0.252628992900000000000000000);
	ft_printf("%.25lf\n", 0.252628992932340986346278998);
	ft_printf("\nprintf:\n");
	printf("%.25lf\n", 0.252628992900000000000000000);
	printf("%.25lf\n", 0.252628992932340986346278998);
	// Leading zeros
	ft_printf("\nLeading zeros tests\n");
	ft_printf("\nft_printf:\n");
	ft_printf("%.12lf\n", -0.000000000252628);
	ft_printf("%.12lf\n", 0.000000000252628);
	ft_printf("%.15lf\n", 0.000000000252628);
	ft_printf("%.18lf\n", 0.0000000000000252628);
	ft_printf("%.25lf\n", 0.000000000000000002526289929);
	ft_printf("%.300lf\n", 1.0e-300);
	ft_printf("%.330lf\n", 2.0e-323);
	ft_printf("\nprintf:\n");
	printf("%.12lf\n", -0.000000000252628);
	printf("%.12lf\n", 0.000000000252628);
	printf("%.15lf\n", 0.000000000252628);
	printf("%.18lf\n", 0.0000000000000252628);
	printf("%.25lf\n", 0.000000000000000002526289929);
	printf("%.300lf\n", 1.0e-300);
	printf("%.330lf\n", 2.0e-323);
	*/
	/*
	// Normal tests
	ft_printf("\nNormal tests\n");
	ft_printf("\nft_printf:\n");
	ft_printf("%f\n", 14.75);
	ft_printf("%f\n", -14.75);
	ft_printf("%.4f\n", 1997.0918);
	ft_printf("%.9f\n", 217.4444444);
	ft_printf("%.12lf\n", 0.000000000252628);
	ft_printf("%.15lf\n", 0.000000000252628);
	ft_printf("%.20lf\n", 0.000000000252628);
	ft_printf("\nprintf:\n");
	printf("%f\n", 14.75);
	printf("%f\n", -14.75);
	printf("%.4f\n", 1997.0918);
	printf("%.9f\n", 217.4444444);
	printf("%.12lf\n", 0.000000000252628);
	printf("%.15lf\n", 0.000000000252628);
	printf("%.20lf\n", 0.000000000252628);
	*/
	/*
	// 5.0505 tests
	ft_printf("\n5.0505 tests\n");
	ft_printf("\nft_printf:\n");
	ft_printf("%.3f\n", 5.0505000);
	ft_printf("%.4f\n", 5.0505000);
	ft_printf("%.5f\n", 5.0505000);
	ft_printf("%.6f\n", 5.0505000);
	ft_printf("%.7f\n", 5.0505000);
	ft_printf("%.15f\n", 5.0505000000000);
	ft_printf("\nprintf:\n");
	printf("%.3f\n", 5.0505000);
	printf("%.4f\n", 5.0505000);
	printf("%.5f\n", 5.0505000);
	printf("%.6f\n", 5.0505000);
	printf("%.7f\n", 5.0505000);
	printf("%.15f\n", 5.0505000000000);
	*/
	/*
	// inf nan
	ft_printf("\ninf / -inf / nan tests\n");
	ft_printf("\nft_printf:\n");
	ft_printf("%lf\n", INFINITY);
	ft_printf("%lf\n", -INFINITY);
	ft_printf("%lf\n", NAN);
	ft_printf("\nprintf:\n");
	printf("%lf\n", INFINITY);
	printf("%lf\n", -INFINITY);
	printf("%lf\n", NAN);
	*/
	/*
	// Negative zero tests
	ft_printf("\nNegative Zero\n");
	t_double testprint;
	testprint.l = (1L << 63);
	ft_printf("\nft_printf:\n");
	ft_printf("zero:	%lf\n", (double)0);
	ft_printf("-zero:	%lf\n", testprint.d);
	ft_printf("\nprintf:\n");
	printf("zero:	%lf\n", (double)0);
	printf("-zero:	%lf\n", testprint.d);
	*/
	/*
	// Rounding tests
	ft_printf("\nRounding tests\n");
	ft_printf("\nft_printf:\n");
	ft_printf("%.6f\n", 1.1230996);
	ft_printf("%.6f\n", 1.1230995);
	ft_printf("%.6f\n", 1.1230985);
	ft_printf("%.2f\n", 2.3650);
	ft_printf("\nprintf:\n");
	printf("%.6f\n", 1.1230996);
	printf("%.6f\n", 1.1230995);
	printf("%.6f\n", 1.1230985);
	printf("%.2f\n", 2.3650);
	*/

	/*
	// Scientific notation tests
	printf("%e\n", 12.234);
	*/

	// Unicode tests
	ft_printf("%S\n", L"\u03c0test\u03c0");
	ft_printf("%ls\n", L"\u03c0test\u03c0");
	ft_printf("%S\n", 0);
	ft_printf("%C\n", 0);
	ft_printf("%lc\n", L'\U0001f47d');

	/*
	ft_printf("%x\n", -42);
	printf("%x\n", -42);
	*/

	/*
	// Pointer tests
	ft_printf("\nPointer tests\n");

	char	c = 0;
	char	*str = "pouet";

	ft_printf("\nft_printf:\n");
	ft_printf("%p\n", &p);
	ft_printf("%p\n", (void *)0);
	ft_printf("%p\n", &c);
	ft_printf("%p\n", str);
	ft_printf("%p\n", &str);
	str = NULL;
	ft_printf("%p\n", str);
	str = ft_strdup("Coucou les haricots !");
	ft_printf("%p\n", str);

	str = "pouet";

	printf("\nprintf:\n");
	printf("%p\n", &p);
	printf("%p\n", (void *)0);
	printf("%p\n", &c);
	printf("%p\n", str);
	printf("%p\n", &str);
	str = NULL;
	printf("%p\n", str);
	str = ft_strdup("Coucou les haricots !");
	printf("%p\n", str);
	*/
	/*
	// Pointer flag tests
	int		p = 900;
	ft_printf("\nflag tests\n");
	ft_printf("\nft_printf\n");
	ft_printf("%p\n", &p);
	ft_printf("%0p\n", &p);
	ft_printf("%#p\n", &p);
	ft_printf("%15p\n", &p);
	ft_printf("%-15p\n", &p);
	ft_printf("%15.3p\n", &p);
	ft_printf("%20.10p\n", &p);
	ft_printf("\nprintf:\n");
	printf("%p\n", &p);
	printf("%p\n", &p);
	printf("%p\n", &p);
	printf("%15p\n", &p);
	printf("%-15p\n", &p);
	printf("%15p\n", &p);
	printf("%20p\n", &p);
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
	printf("%o\t%#o\t%.o\t%#.o\t%#.4o\n", 0, 0, 0, 0, 0);
	printf("%o\t%#o\t%.o\t%#.o\t%#6.4o\n", 7, 7, 7, 7, 7);
	printf("%o\t%#o\t%.o\t%#.o\t%#.4o\n", 8, 8, 8, 8, 512);
	printf("%o\t%#o\t%.o\t%#.o\t%#.2o\n", 8, 8, 8, 8, 512);
	printf("\n");
	printf("%d\t%+d\t%.d\t%+.d\t%+.4d\n", 0, 0, 0, 0, 0);
	printf("%d\t%+d\t%.d\t%+.d\t%+.4d\n", 7, 7, 7, 7, 7);
	printf("%d\t%+d\t%.d\t%+.d\t%+.4d\n", 8, 8, 8, 8, 8);
	printf("\n");
	printf("%x\t%#x\t%.x\t%#.x\t%#.4x\n", 0, 0, 0, 0, 0);
	printf("%x\t%#x\t%.x\t%#.x\t%#.4x\n", 7, 7, 7, 7, 7);
	printf("%x\t%#x\t%.x\t%#.x\t%#.4x\n", 8, 8, 8, 8, 8);
	printf("\n");
	printf("%+d\n", 10);
	printf("%+d\n", 0);
	printf("%+d\n", -10);
	printf("1234567890\n");
	printf("%+10.8d\n", 10);
	printf("%+10.8d\n", 0);
	printf("%+10.8d\n", -10);
	printf("1234567890\n");
	printf("%+8.8d\n", 10);
	printf("%+9.8d\n", 0);
	printf("%+10.8d\n", -10);
	printf("1234567890\n");
	printf("%+8d\n", 10);
	printf("%+9d\n", 0);
	printf("%+10d\n", -10);
	printf("1234567890\n");
	printf("%+.8d\n", 10);
	printf("%+.9d\n", 0);
	printf("%+.10d\n", -10);
	printf("1234567890\n");
	printf("%+8.10d\n", 10);
	printf("%+8.10d\n", 0);
	printf("%+8.10d\n", -10);
	printf("1234567890\n");
	printf("%8.10d\n", 10);
	printf("%8.10d\n", 0);
	printf("%8.10d\n", -10);
	printf("1234567890\n");
	printf("%06.2d\n", 512);
	printf("%Test\n");
	*/

	/*
	// versus test with width, precision, and -+ 0 flags
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
