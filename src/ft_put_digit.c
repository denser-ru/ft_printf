/*ft_put_digit.c by cayako*/

# include "ft_printf.h"


int		ft_digit_modifer(t_pf *pf, int nb)
{
	if (pf->flags & PF_H)
		return((short int)nb);
	if (pf->flags & PF_HH)
		return((char)nb);
	else
		return (nb);
}

void		ft_put_digit(t_pf *pf, int nb, int i, int precision)
{
	int		size;
	char	c;

	nb = ft_digit_modifer(pf, va_arg(*(pf->arg), int));
	size = 1;
	i = nb < 0 ? -nb : nb;
	while ((i /= 10))
		++size;
	precision = precision > size ? precision - size + !nb: 0;
	c = (pf->flags & PF_ZERO) && !(pf->flags & PF_PREC) ? '0' : ' ';
	size += ((pf->flags & PF_PLUS) > 0 || nb < 0) - !nb;
	pf->width = pf->width - precision - size;
	pf->width = pf->width < 0 ? 0 : pf->width;
	ft_putchar_n(' ', pf->width * ((pf->flags & PF_ALIGN) == 0));
	c = nb < 0 ? '-' : '+';
	ft_putchar_n(c, (pf->flags & PF_PLUS) || nb < 0);
	ft_putchar_n('0', precision);
	pf->i += pf->width + precision + size;
	if (nb)
		ft_putnbr(nb < 0 ? -nb : nb);
	ft_putchar_n(' ', (pf->width) * !(!(pf->flags & PF_ALIGN)));
}