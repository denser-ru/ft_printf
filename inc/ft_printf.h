/*ft_printf.h by cayako*/

# include "libft.h"
# include <stdarg.h>

# define PF_ZERO	0
# define PF_PLUS	1
# define PF_ALIGN	2
# define PF_SPACE	4
# define PF_SHARP	8
# define PF_H		16
# define PF_HH		32
# define PF_L		64
# define PF_LL		128
# define PF_ML		256

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