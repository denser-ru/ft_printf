/*ft_put_ox.c by cayako*/

# include "ft_printf.h"

void		ft_put_atoi_base(unsigned long long int nb, int base, char f)
{
	unsigned long long int	hex;
	unsigned long long int	div;
	unsigned long long int	nb2;
	const char				*abc = "0123456789abcdef0123456789ABCDEF";

	hex = nb / base;
	nb2 = nb / base;
	nb -= nb2 * base;
	div = 1;
	while ((hex /= base))
		div *= base;
	div *= base;
	while ((div /= base))
	{
		hex = nb2 / div;
				
		ft_putchar(abc[hex + (f == 'X' ? 16 : 0)]);
		nb2 -= hex * div;
	}
	ft_putchar(abc[nb + (f == 'X' ? 16 : 0)]);
}

void		ft_put_prefix(t_pf *pf, char f)
{
	if ((pf->flags & PF_SHARP) && f == 'o')
		ft_putchar('0');
	else if ((pf->flags & PF_SHARP) && f != 'u')
		ft_putnstr(f == 'X' ? "0X" : "0x", 2);
}

void		ft_put_x(t_pf *pf, char f, int base, unsigned long long int nb)
{
	int						size;
	int						precision;
	unsigned long long int	div;

	size = 1;
	div = 1;
	size += ft_get_nblen_base(nb, base);
	pf->precision = (pf->flags & PF_PREC) ? pf->precision : pf->width;
	precision = pf->precision > size ? pf->precision - size: 0;
	size += ((pf->flags & PF_PLUS) || (pf->flags & PF_SPACE))
		+ ((pf->flags & PF_SHARP) > 0) * 2;
	pf->width = pf->width - precision - size;
	pf->width = pf->width < 0 ? 0 : pf->width;
	ft_putchar_n(' ', pf->width * ((pf->flags & PF_ALIGN) == 0) );
	ft_putchar_n(f != 'p' || (f == 'p' && !(pf->flags & PF_PLUS)) ? ' ' : '+',
				(pf->flags & PF_PLUS) || (pf->flags & PF_SPACE));
	ft_put_prefix(pf, f);
	ft_putchar_n('0', precision);
	pf->i += pf->width + precision + size;
	ft_put_atoi_base(nb, base, f);
	ft_putchar_n(' ', (pf->width) * !(!(pf->flags & PF_ALIGN)));
}

void		ft_put_oxup(t_pf *pf, char f, int base)
{
	if (f == 'p')
		pf->flags = pf->flags | PF_LL | PF_SHARP;
	if (pf->flags & PF_LL)
		ft_put_x(pf, f, base, va_arg(*(pf->arg), unsigned long long int));
	else if (pf->flags & PF_L)
		ft_put_x(pf, f, base, va_arg(*(pf->arg), unsigned long int));
	else
		ft_put_x(pf, f, base, va_arg(*(pf->arg), unsigned int));
}
