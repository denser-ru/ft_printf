/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.c
 * Copyright (C) 2020 cayako <denser@Ctrl-UX31A>
 * 
 */

# include "ft_printf.h"
# include <stdio.h>

int main()
{
	int		i;

	i = printf("origin_pf: % 3.d %-10.3s %yk %c x = % #+20.12X p = % +0p o = %o u = %u f = % 8.1Lf)\n", 0,
		"12345", '!',
			(unsigned long long int)(18446744073709551615ULL),
				(void*)(54321), 12345, 12345, (long double)-10.24);
	ft_putstr("return: ");
	ft_putnbr(i);
	ft_putchar ('\n');
	i = ft_printf("ft_printf: % 3.d %-10.3s %yk %c x = % #+20.12X p = % +0p o = %o u = %u f = % 8.1Lf)\n", 0,
		"12345", '!',
			(unsigned long long int)(18446744073709551615ULL),
				(void*)(54321), 12345, 12345, (long double)-10.24);
	ft_putstr("return: ");
	ft_putnbr(i);
	ft_putchar ('\n');
	return (0);
}