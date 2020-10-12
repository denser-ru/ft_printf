/*ft_printf.h by cayako*/

# include "libft.h"
# include <stdarg.h>

# define PF_ZERO	1
# define PF_PLUS	2
# define PF_ALIGN	4
# define PF_SPACE	8
# define PF_SHARP	16
# define PF_PREC	32
# define PF_H		64
# define PF_HH		128
# define PF_L		256
# define PF_LL		512
# define PF_ML		1024

typedef struct		s_pf
{
	va_list			*arg;
	char			*start;
	char			*cur;
	char			*next;
	int				i;
	int				width;
	int				precision;
	int				flags;
}					t_pf;

int					ft_printf(const char *format, ...);
void				ft_parsing(t_pf *pf, char *format);
void				ft_putarg(t_pf *pf, char *format);

void				ft_putchar_n(char c, int i);
unsigned long long	ft_get_max_base(int base);
unsigned long long	ft_get_nblen_base(unsigned long long nb, int base);
void				ft_put_oxup(t_pf *pf, char f, int base);
void				ft_put_digit(t_pf *pf, int nb, int i, int precision);
void				ft_put_percent(t_pf *pf);
void				ft_put_pf_char(t_pf *pf, char c);
void				ft_put_pf_str(t_pf *pf, char *s);
void				ft_put_f(t_pf *pf);