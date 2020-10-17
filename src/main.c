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

	i = printf("origin_pf: %3.2d|\n", 1);
	ft_putstr("return: ");
	ft_putnbr(i);
	ft_putchar ('\n');
	i = ft_printf("ft_printf: %3.2d|\n", 1);
	ft_putstr("return: ");
	ft_putnbr(i);
	ft_putchar ('\n');
	return (0);
}