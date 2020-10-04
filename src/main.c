/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.c
 * Copyright (C) 2020 cayako <denser@Ctrl-UX31A>
 * 
 */

#include "ft_printf.h"
int main()
{
	int		i;

	ft_putendl("ft_printf:");
	i = ft_printf("write: %d", 123);
	ft_putstr("return: ");
	ft_putnbr(i);
	ft_putchar ('\n');
	return (0);
}

