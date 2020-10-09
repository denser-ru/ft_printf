/*ft_putarg.c by cayako*/

# include "ft_printf.h"

void		ft_putarg(t_pf *pf, char *format)
{
	if (*format == '%')
		ft_put_percent(pf);
	else if (*format == 'd' || *format == 'i')
		ft_put_digit(pf, 0, 0, pf->precision);
	else if (*format == 'c')
		ft_put_pf_char(pf, 0);
	else if (*format == 's')
		ft_put_pf_str(pf, NULL);
	else
	{
		ft_putchar('%');
		++(pf->i);
		return ;
	}
	pf->cur = ++format;
}