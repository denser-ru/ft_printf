/*ft_put_src.c by cayako*/

# include "ft_printf.h"

void			ft_put_percent(t_pf *pf)
{
	ft_putchar('%');
	++(pf->i);
}

void			ft_put_pf_char(t_pf *pf, char c)
{
	c = va_arg(*(pf->arg), int);
	ft_putchar(c);
	++(pf->i);
}

void		ft_put_pf_str(t_pf *pf, char *s)
{
	int		len;
	int		space;

	s = va_arg(*(pf->arg), char*);
	len = ft_strlen(s);
	len = len > pf->precision ? pf->precision : len;
	space = pf->width > len ? pf->width - len : 0;
	if (!(pf->flags & PF_ALIGN))
		ft_putchar_n(' ', space);
	ft_putnstr(s, len);
	if (pf->flags & PF_ALIGN)
		ft_putchar_n(' ', space);
	(pf->i) += len + space;
}