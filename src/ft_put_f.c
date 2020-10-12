/*ft_put_digit.c by cayako*/

# include "ft_printf.h"

int			ft_put_lli(long long nb, int size;)
{
	long long	div;

	while ()
	return (size);
}

void		ft_get_f(t_pf *pf, long long *n, float *d)
{
	long double		nb;
	long long	p;

	nb = va_arg(*(pf->arg), long double);
	*n = (long long)nb;
	*d = nb - *n;
	p = 1;
	while ((*d * p) - (long long)(*d * p))
		p *= 10;
	*d *= p;
}

void		ft_put_f(t_pf *pf)
{
	long long		n;
	float	d;

	ft_get_f(pf, &n, &d);
	ft_putnbr(n);
	ft_putchar('.');
	ft_putnbr((int)d);
}