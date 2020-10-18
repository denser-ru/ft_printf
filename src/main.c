/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:30:43 by cayako            #+#    #+#             */
/*   Updated: 2020/10/18 14:30:53 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int		i;

	i = printf("origin_pf: %3.2d|\n", 1);
	ft_putstr("return: ");
	ft_putnbr(i);
	ft_putchar('\n');
	i = ft_printf("ft_printf: %3.2d|\n", 1);
	ft_putstr("return: ");
	ft_putnbr(i);
	ft_putchar('\n');
	return (0);
}
