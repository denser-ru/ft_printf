/*ft_pf_utils.c by cayako*/

# include "ft_printf.h"

void				ft_putchar_n(char c, int i)
{
		while (i--)
		ft_putchar(c);
}

unsigned long long int	ft_get_max_base(int base)
{
	unsigned long long int	i;

	i = 1;
	while (i * base > i)
		i *= base;
	return (i);
}

int	ft_get_nblen_base(unsigned long long nb, int base)
{
	unsigned long long int	i;

	i = 0;
	while ((nb /= base))
		++i;
	return (i);
}