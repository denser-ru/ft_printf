/*ft_put_digit.c by cayako*/

# include "ft_printf.h"


long long	ft_digit_modifer(t_pf *pf)
{
	if (pf->flags & PF_H)
		return((short)va_arg(*(pf->arg), long long));
	if (pf->flags & PF_HH)
		return((char)va_arg(*(pf->arg), long long));
	if (pf->flags & PF_L)
		return((long)va_arg(*(pf->arg), long long));
	if (pf->flags & PF_LL)
		return(va_arg(*(pf->arg), long long));
	return ((int)va_arg(*(pf->arg), long long));
}

void		ft_put_digit(t_pf *pf, long long nb, int width, int prec)
{
	int		size;
	char	c;
	int		sgn;
	int		z;

	nb = ft_digit_modifer(pf);
	sgn = nb < 0 ? 1 : 0;
	nb = sgn ? -nb : nb;
	z = ((pf->flags & PF_PREC) && !(pf->precision) && !sgn && !nb);
	size = z ? 0 : ft_get_nblen_base(nb, 10) + 1;
	prec = (pf->precision - size) > 0 ? pf->precision - size : 0;
	size += ((pf->flags & PF_PLUS) || sgn || (pf->flags & PF_SPACE));
	width = width - size - prec > 0 ? width - size - prec: 0;
	if (!(pf->flags & PF_ALIGN) && (!(pf->flags & PF_ZERO) || (pf->flags & PF_PREC)))
		ft_putchar_n(' ', width);
	c = sgn ? '-' : '+';
	ft_putchar_n(c, (pf->flags & PF_PLUS) || sgn);
	if (!(pf->flags & PF_ALIGN) && (pf->flags & PF_ZERO) && !(pf->flags & PF_PREC))
		ft_putchar_n('0', width);
	if (!(pf->flags & PF_PLUS) && !sgn && (pf->flags & PF_SPACE))
		ft_putchar(' ');
	ft_putchar_n('0', prec);
	pf->i += width + prec + size;
	if (!z)
		ft_put_atoi_base(nb, 10, 'd');
	ft_putchar_n(' ', (width) * !(!(pf->flags & PF_ALIGN)));
}