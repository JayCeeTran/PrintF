#include "ft_printf.h"

int	f_putch(const char *c)
{
	if(*c == '\0')
		write(1, "\0", 1);
	else
		write(1, c, 1);
	return(1);
}
