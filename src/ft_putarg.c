/*ft_putarg.c by cayako*/

# include "ft_printf.h"

void		ft_put_percent(t_pf *pf)
{
	ft_putchar('%');
		++(pf->i);
}

void		ft_putarg(t_pf *pf, char *format)
{
	if (*format == '%')
		ft_put_percent(pf);
	pf->cur = ++format;
}