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

//	printf("orig_pf: %-20.10f %.5d\n", 12345.12345, 5);
	i = printf("origin_pf: %+3.5d %-10.3s %yk %c %p x = %5.5o\n", -1,
				"12345", '!', &i, 16);
	ft_putstr("return: ");
	ft_putnbr(i);
	ft_putchar ('\n');
	i = ft_printf("ft_printf: %+3.5d %-10.3s %yk %c %p\n", -1, "12345", '!', &i);
	ft_putstr("return: ");
	ft_putnbr(i);
	ft_putchar ('\n');
	return (0);
}

