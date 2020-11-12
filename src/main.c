/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:30:43 by cayako            #+#    #+#             */
/*   Updated: 2020/11/12 12:56:25 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"

/*
/** #include <stdio.h>
** It`s file for testinf ft_printf function !
*/

int		main(void)
{
	int		i;

	ft_putstr("\nreturn: ");
	ft_putnbr(i);
	ft_putchar('\n');
	i = ft_printf("%hx", -1518156344);
	ft_putstr("\nreturn: ");
	ft_putnbr(i);
	ft_putchar('\n');
	return (0);
}
