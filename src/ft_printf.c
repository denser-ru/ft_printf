/*ft_printf.c by cayako*/

# include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list		arg;

	va_start(arg, format);
	ft_putnendl (format, ft_strchr (format, '%') - format);
	return (ft_strchr (format, '%') - format);
}