/*ft_pf_utils.c by cayako*/

# include "ft_printf.h"

void				ft_putchar_n(char c, int i)
{
		while (i--)
		ft_putchar(c);
}

unsigned long long	ft_get_max_base(int base)
{
	unsigned long long	i;

	i = 1;
	while (i * base > i)
		i *= base;
	return (i);
}