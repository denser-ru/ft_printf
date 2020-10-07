/*ft_parsing.c by cayako*/

# include "ft_printf.h"

static void		ft_get_width(t_pf *pf, char **format)
{
	pf->width = ft_atoi(*format);
	while (ft_strchr("123456789", **format))
		++(*format);
}

static void		ft_get_precision(t_pf *pf, char **format)
{
	++(*format);
	pf->precision = ft_atoi(*format);
	while (ft_strchr("123456789", **format))
		++(*format);
}

static void		ft_get_flag(t_pf *pf, char **format)
{
	if (**format == '0')
		pf->flags = pf->flags | PF_ZERO;
	else if (**format == '+')
		pf->flags = pf->flags | PF_PLUS;
	else if (**format == '-')
		pf->flags = pf->flags | PF_ALIGN;
	else if (**format == ' ')
		pf->flags = pf->flags | PF_SPACE;
	else if (**format == '#')
		pf->flags = pf->flags | PF_SHARP;
	++(*format);
}

static void		ft_get_modifier(t_pf *pf, char **format)
{
	if (**format == 'h')
	{
		if (*((*format) + 1) == 'h')
			pf->flags = pf->flags | PF_HH;
		else
			pf->flags = pf->flags | PF_H;
	}
	else if (**format == 'l')
	{
		if (*((*format) + 1) == 'l')
			pf->flags = pf->flags | PF_L;
		else
			pf->flags = pf->flags | PF_LL;
	}
	else if (**format == 'L')
		pf->flags = pf->flags | PF_ML;
}

void		ft_parsing(t_pf *pf, char *format)
{
	while(*format && !ft_memchr("diouxXfcsp%", *format, 11))
	{
		if (ft_strchr("123456789", *format))
			ft_get_width(pf, &format);
		else if (ft_strchr(".", *format))
			ft_get_precision(pf, &format);
		else if (ft_strchr("#0-+ ", *format))
			ft_get_flag(pf, &format);
		else if (ft_strchr("hlL", *format))
			ft_get_modifier(pf, &format);
		else
			break;
		++format;
	}
	if(*format && ft_memchr("diouxXfcsp%", *format, 11))
		pf->cur = format;
	else
		--format;
	ft_putarg(pf, format);
}

/*void		ft_parsing(t_pf *pf)
{
	if (*((pf->next) + 1) == 'd')
		ft_putnbr(va_arg(*(pf->arg), int));
	if (*((pf->next) + 1) == 's')
		ft_putstr(va_arg(*(pf->arg), char*));
	++(pf->next);
}*/