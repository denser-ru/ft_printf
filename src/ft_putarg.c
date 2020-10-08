/*ft_putarg.c by cayako*/

# include "ft_printf.h"

static void		ft_put_percent(t_pf *pf)
{
	ft_putchar('%');
	++(pf->i);
}

static void		ft_put_pf_char(t_pf *pf, char c)
{
	c = va_arg(*(pf->arg), int);
	ft_putchar(c);
	++(pf->i);
}

static void		ft_put_pf_str(t_pf *pf, char *s)
{
	s = va_arg(*(pf->arg), char*);
	ft_putstr(s);
	(pf->i) += ft_strlen(s);
}

int		ft_digit_modifer(t_pf *pf, int nb)
{
	if (pf->flags & PF_H)
		return((short int)nb);
	if (pf->flags & PF_HH)
		return((char)nb);
	else
		return (nb);
}

void		ft_put_digit(t_pf *pf, int nb, int i)
{
	size_t	size;

	size = 1;
	nb = ft_digit_modifer(pf, va_arg(*(pf->arg), int));
	i = nb;
	while ((i /= 10))
		++size;
	pf->i += nb < 0 ? ++size : size;
	ft_putnbr(nb);
}

void		ft_putarg(t_pf *pf, char *format)
{
	if (*format == '%')
		ft_put_percent(pf);
	if (*format == 'd' || *format == 'i')
		ft_put_digit(pf, 0, 0);
	if (*format == 'c')
		ft_put_pf_char(pf, 0);
	if (*format == 's')
		ft_put_pf_str(pf, NULL);
	pf->cur = ++format;
}